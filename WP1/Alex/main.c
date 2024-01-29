// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 16 (2024)
// Work package 0
// Exercise 1
// Submission code: 7654 (provided by your TA-s)
#include <stdio.h>
#include <string.h>
// Main function in the program, program arguments supported
int main(int argc, char *argv[])
{
    // Checks number of arguments to ensure that the correct number of parameters has been inputted
    if (argc != 2)
    {
        printf("Error: Incorrect number of parameters. Please use my_program.exe -h for more info.");
        // Returns 1 to signify an error has occured
        return 1;
    }

    // Checks to see if the help flag has been used
    if (strcmp(argv[1], "-h") == 0)
    {
        printf("Help: Enter the program name, followed by the user's name to see the correct output (E.G.: myprogram.exe tom)");
        return 0;
    }

    // Prints the message followed by the entered name
    printf("Hello World! - I'm %s!", argv[1]);
    return 0;
}
