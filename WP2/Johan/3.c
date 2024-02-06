#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;
// Function declaration (to be extend)
PERSON input_record(void);                       // Reads a person’s record.
void write_new_file(PERSON *inrecord);           // Creates a file and writes the first record
void printfile(void);                            // Prints out all persons in the file
void search_by_name(char *name, int sortOption); // Prints out the person if in list

void append_file(PERSON *inrecord); // appends a new person to the file

void search_by_name(char *name, int sortOption)
{
    FILE *file;    // file pointer
    PERSON t;      // temp person
    int found = 0; // flag for checking if atleast one record has been found

    if ((file = fopen("personDB.dat", "rb")) == NULL) // Open file and check if it actually exists
    {
        printf("\nERROR CANT OPEN FILE");
        exit(1); // exit program if error occured
    }

    // Read each record from the file
    while (fread(&t, sizeof(PERSON), 1, file) == 1) //
    {
        // Compare relevant field (firstname | famname) to input, based on sortOption parameter
        if (strcmp((sortOption == 0 ? t.firstname : t.famname), name) == 0)
        {
            printf("\nFound match: Firstname: %s, Lastname: %s, persnumber: %s\n", t.firstname, t.famname, t.pers_number);
            found = 1; // mark that we have found atleast one record
        }
    }

    // if we didnt find a record, return not found msg
    if (!found)
    {
        printf("\nNo match found for the name %s.\n", name);
    }

    fclose(file); // close file
}

void append_file(PERSON *inrecord)
{
    FILE *file; // file pointer

    // open our database file in ab(append binary) mode to add record to file or create a new file and add record
    if ((file = fopen("personDB.dat", "ab")) == NULL)
    {
        printf("\n ERROR CANT OPEN FILE");
        exit(1); // Exit if file cannot be opened for whatever reason
    }

    // Write record to file
    fwrite(inrecord, sizeof(PERSON), 1, file);

    fclose(file); // close file

    printf("New person added successfully\n");
}

void printfile(void)
{
    FILE *file; // file pointer
    PERSON t;   // temp person to hold each record

    // Open database file in rb(read binary) mode to read the file
    if ((file = fopen("personDB.dat", "rb")) == NULL)
    {
        printf("\n Cant open file");
        exit(1); // Exit if file cant be opened for whatever reason.
    }

    // check if file is empty
    fseek(file, 0, SEEK_END);

    // if stream position is NOT zero, we can assume records exist.
    if (ftell(file) == 0)
    {
        printf("The file is empty!\n");
        fclose(file); // close file
        return;
    }
    else // else records do exist
    {
        // move stream pointer back to top of file
        rewind(file);
    }

    // Read each record and print it
    while (fread(&t, sizeof(PERSON), 1, file) == 1)
    {
        printf("\nFirstname: %s, Lastname: %s, persnumber: %s", t.firstname, t.famname, t.pers_number);
    }

    putchar('\n'); // newline for formatting
    fclose(file);  // close file
}

void write_new_file(PERSON *inrecord)
{
    FILE *file; // file pointer

    // Hardcoded data that we will use to insert into database file.
    strcpy(inrecord->famname, "Johnson");
    strcpy(inrecord->firstname, "John");
    strcpy(inrecord->pers_number, "199910177273");

    // Open database file in wb(write binary) mode, so we either create a new file, or overwrite if it already exists
    if ((file = fopen("personDB.dat", "wb")) == NULL)
    {
        printf("\n Error cant create file");
        exit(1); // Exit if file cant be opened for whatever reason.
    }
    // write hardcoded data to database file
    fwrite(inrecord, sizeof(PERSON), 1, file);

    fclose(file); // close file

    printf("data written sucess\n");
}
int main(void)

{
    FILE *file;
    PERSON ppost; // Initialize person to hold user input

    // infinite loop until ctrl-z is entered
    while (1)
    {
        printf("1: Create a new and delete the old file\n");
        printf("2: Add a new person to the file\n");
        printf("3: Search for a person in the file\n");
        printf("4: Print out all in the file\n");
        printf("5: Exit the program\n");

        char inputChoice; // Input buffer for options

        scanf(" %c", &inputChoice); // grab input

        // switch to handle input choice with corresponding action.
        switch (inputChoice)
        {
        case '1':
            // Call function to write new file
            write_new_file(&ppost);
            break;
        case '2':
            printf("Firstname: ");
            scanf("%s", ppost.firstname); // prompt user for firstname to insert

            // lastname input
            printf("Lastname: ");
            scanf("%s", ppost.famname); // prompt user for lastname to insert

            // pers input
            printf("Personal number: ");
            scanf("%s", ppost.pers_number); // prompt user for pers number to insert

            // feed append function our updated person to be inserted.
            append_file(&ppost);

            break;
        case '3':
        {
            // char buffer to store sort choice which is either by firstname OR lastname
            char sortChoice;
            printf("Search by firstname (f/F), lastname (l/L): ");
            scanf(" %c", &sortChoice); // capture input

            // If user wants to search by firstname
            if (sortChoice == 'f' || sortChoice == 'F')
            {
                char searchfname[20]; // buffer for search fname param
                printf("\nEnter firstname to search: ");
                scanf("%s", searchfname); // capture input

                // call search function with our firstname to search
                search_by_name(searchfname, 0); // 0 tells the function we want to search with firstname
            }
            // if user wants to search by lastname instead
            else if (sortChoice == 'l' || sortChoice == 'L')
            {
                char searchlname[20]; // buffer for search lname;
                printf("\nEnter lastname to search: ");
                scanf("%s", searchlname); // capture input

                // call search function with lname param
                search_by_name(searchlname, 1); // 1 tells the function we want to search with lastname
            }
            break;
        }
        case '4':
            printfile(); // call print file function
            break;
        case '5':
            printf("Exiting program!!\n");
            return 0; // kill program
        }
    }

    return (0); // Kill program
}