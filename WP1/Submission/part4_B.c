// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 4.B
// Submission code: XXXX (provided by your TA-s)

// This script will turn a binary number to hexadecimal

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char binaryGroupToHex(const char *group)
{
    // Convert the binary string to a long integer with base 2
    int value = strtol(group, NULL, 2);

    if (value < 10) // if value is less than 10, return 'normal' ints 0-9
    {
        return '0' + value;
    }
    else // for values >= 10 use hexadecimal characters instead.
    {
        return 'A' + (value - 10);
    }
}

int isBinaryString(const char *str)
{
    // iterate over input str and verify its a binary string.
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '0' && str[i] != '1') // If current value is not 0 or 1, return 0/false
        {
            return 0; // Not a binary string
        }
    }
    return 1; // It is a binary string
}

int main(int argc, char *argv[])
{

    char binaryStr[65]; //  Buffer to hold the input binary string

    if (argc == 2)
    {
        // help flag
        if (strcmp(argv[1], "-h") == 0)
        {
            printf("Run the program then enter the binary number that you would like to convert to hexadecimal.\n");
            printf("It is possible to use this program in conjunction with dec2bin.exe in the following format:\n");
            printf("> .\\dec2bin.exe <decimal number> | .\\bin2hex.exe");
            return 2;
        }
        // If there is an argument, we can assume we are not using piping method, so take normal argv input
        // Copy the input binary string into the buffer
        strncpy(binaryStr, argv[1], 64);
        binaryStr[64] = '\0'; // ensure null termination
    }
    else
    {
        // Otherwise, read input from stdin (piping method)
        if (scanf("%64s", binaryStr) != 1)
        {
            printf("Failed to read binary string\n");
            return 2;
        }
    }

    // check if the input is a binary string
    if (!isBinaryString(binaryStr))
    {
        printf("Error: Input is not a valid binary string (contains characters other than '0' and '1')\n");
        return 2;
    }

    int len = strlen(binaryStr); // length of input binary string

    // Check if the length of the input binary string is a multiple of 4
    if (len % 4 != 0)
    {
        printf("Error: Invalid bit size. The length of the binary string must be a multiple of 4.\n");
        return 2;
    }

    char answer[20]; // Answer buffer to hold the hexadecimal answer
    int index = 0;   // Index tracker for answer buffer

    // iterate over binary string in groups of 4
    // so that we can convert each group to hexadecimal using our helper function.
    for (int i = 0; i < len; i += 4)
    {
        char group[5];                    // temp buffer to store group of 4 binary digits, +1 for null termination
        strncpy(group, binaryStr + i, 4); // copy next four characters of binaryStr into a group

        char hex = binaryGroupToHex(group); // convert the group to hexadecimal form

        answer[index++] = hex; // store hex decimal in answer buffer and increase index
    }

    answer[index] = '\0'; // terminate string

    printf("%s\n", answer);
    return 0;
}
