// (C) Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 16 (2024)
// Work package 0
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)
// Main function in the program, no program arguments supported

#include <stdio.h>
#include <string.h>

char name[15];
char *nameptr = name;
int age;

// Begin program execution here in main
int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        printf("No input given\n");
    }
    else if (argc >= 3)
    {
        printf("Too many arguments\n");
    }
    else
    {
        printf("Hello World! I'm %s!", argv[1]);
    }

    // Indicates that program ended successfully
    return 0;
}
