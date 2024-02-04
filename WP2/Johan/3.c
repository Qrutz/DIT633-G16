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
PERSON input_record(void);             // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and
// writes the first record
void printfile(void);                                 // Prints out all persons in the file
void search_by_firstname(char *name, int sortOption); // Prints out the person if
// in list
void append_file(PERSON *inrecord); // appends a new person to the file

void search_by_firstname(char *name, int sortOption)
{
    FILE *file; // file pointer
    PERSON t;   // temp person

    if ((file = fopen("personDB.dat", "rb")) == NULL)
    {
        printf("\n ERROR CANT OPEN FILE");
        exit(1);
    }

    while (fread(&t, sizeof(PERSON), 1, file) == 1)
    {
        // conditional to specify fname or lname search and compare to input name
        if (strcmp((sortOption == 0 ? t.firstname : t.famname), name) == 0)
        {
            printf("\n Found match: Fname: %s, Lname: %s, PNumber: %s", t.firstname, t.famname, t.pers_number);

            break; // break after first match
        }
        else
        {
            printf("\nNo match found for the name %s.\n", name);
        }
    }

    fclose(file);
}

void append_file(PERSON *inrecord)
{
    FILE *file;

    if ((file = fopen("personDB.dat", "ab")) == NULL) // append binary = ab
    {
        printf("\n ERROR CANT OPEN FILE");
        exit(1);
    }

    fwrite(inrecord, sizeof(PERSON), 1, file);

    fclose(file);

    printf("New person added successfully\n");
}

void printfile(void)
{
    FILE *file;
    PERSON t;

    if ((file = fopen("personDB.dat", "rb")) == NULL)
    {
        printf("\n Cant open file");
        exit(1);
    }

    while (fread(&t, sizeof(PERSON), 1, file) == 1)
    {
        printf("\nFname: %s, Lname: %s, PNumber: %s", t.firstname, t.famname, t.pers_number);
    }

    putchar('\n');
    fclose(file);
}

void write_new_file(PERSON *inrecord)
{
    FILE *file;

    strcpy(inrecord->famname, "Johnson");
    strcpy(inrecord->firstname, "John");
    strcpy(inrecord->pers_number, "199912178275");

    if ((file = fopen("personDB.dat", "wb")) == NULL)
    {
        printf("\n Error cant create file");
        exit(1);
    }
    fwrite(inrecord, sizeof(PERSON), 1, file);

    fclose(file);

    printf("data written sucess\n");
}
int main(void)

{
    FILE *file;
    PERSON ppost;

    while (1)
    {
        printf("1: Create a new and delete the old file\n");
        printf("2: Add a new person to the file\n");
        printf("3: Search for a person in the file\n");
        printf("4: Print out all in the file\n");
        printf("5: Exit the program\n");

        char inputChoice;

        scanf(" %c", &inputChoice);

        switch (inputChoice)
        {
        case '1':
            write_new_file(&ppost);
            // Call function to create a new file
            break;
        case '2':
            // Firstname input
            printf("Firstname: ");
            scanf("%s", ppost.firstname);

            // lastname input
            printf("Lastname: ");
            scanf("%s", ppost.famname);

            // pers input
            printf("Personal number: ");
            scanf("%s", ppost.pers_number);

            // feed function our updated person.
            append_file(&ppost);

            break;
        case '3':
            // Search for a person
            char sortChoice;
            printf("Search by firstname (f/F), lastname (l/L): ");
            scanf(" %c", &sortChoice);

            if (sortChoice == 'f' || sortChoice == 'F')
            {
                char searchfname[20];
                printf("\nEnter firstname to search: ");
                scanf("%s", searchfname);

                // call function
                search_by_firstname(searchfname, 0);
            }
            else if (sortChoice == 'l' || sortChoice == 'L')
            {
                char searchlname[20];
                printf("\n Enter lastname to search: ");
                scanf("%s", searchlname);

                // call function
                search_by_firstname(searchlname, 1);
            }
            break;
        case '4':
            printfile();
            break;
        case '5':
            printf("Exiting program!!\n");
            return 0; // kill program
        }
    }
    return (0);
}