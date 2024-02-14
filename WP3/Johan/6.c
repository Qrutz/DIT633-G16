#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 20

void copyString(char *copy, char *input)
{
    // while theres a character
    while (*input != '\0')
    {
        *copy = *input; // copy current char from input to copy
        copy++;         // move to next copy character
        input++;        // move to next input char
    }

    // null terminate
    *copy = '\0';
}

int main(char *argv[])
{

    char str[STR_MAX];           // hold string
    char strCopy[STR_MAX];       // hold copy string (a)
    char strCopyManual[STR_MAX]; // hold copy string for (b)

    printf("Enter string to copy 1-20 characters: \n");

    scanf("%s", str);

    strcpy(strCopy, str);

    copyString(strCopyManual, str);

    printf("a) Copy with strcpy: %s\n", strCopy);

    printf("b) Copy with copyString : %s\n", strCopyManual);

    return 0;
}