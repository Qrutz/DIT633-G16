#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char binaryGroupToHex(const char *group)
{
    // Convert the binary string to a long integer with base 2
    int value = strtol(group, NULL, 2);

    if (value < 10) // if val < 10, return 'normal' ints 0-9
    {
        return '0' + value;
    }
    else // for values > 10 use ABCDFGH etc.
    {
        return 'A' + (value - 10);
    }
}

int main(int argc, char *argv[])
{

    char binaryStr[65]; //  Buffer to hold the input binary string

    if (argc == 2)
    {
        // If there is an argument, we can assume we are not using piping method, so take normal argv input
        strncpy(binaryStr, argv[1], 64);
        binaryStr[64] = '\0'; // ensure null termination
    }
    else
    {
        // Otherwise, read from stdin
        if (scanf("%64s", binaryStr) != 1)
        {
            fprintf(stderr, "Failed to read binary string\n");
            return 1;
        }
    }

    int len = strlen(binaryStr);
    char answer[20]; // answer buffer
    int index = 0;   // index tracker for answer

    for (int i = 0; i < len; i += 4) // iterate over binary string in groups of 4
    {
        char group[5];                    // temp buffer to store group of 4 binary digits
        strncpy(group, binaryStr + i, 4); // copy next four characters of binaryStr into a group

        char hex = binaryGroupToHex(group); // convert the group to hexadecimal form

        answer[index++] = hex; // store hex decimal in answer buffer and increase index
    }

    answer[index] = '\0'; // terminate string

    printf("%s", answer);
    return 0;
}
