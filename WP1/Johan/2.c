#include <stdio.h>
#include <stdlib.h> // so we can we atoi.

int isUpperCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int getPositionInAlphabet(char c)
{
    if (isUpperCase(c) == 1)
    {
        return c - 'A';
    }
    else if (isUpperCase(c) == 0)
    {
        return c - 'a';
    }
    else
    {
        return -1;
    }
}

char getLetterAfterShift(char c, int shift)
{
    int posalf = getPositionInAlphabet(c);

    int newpos = (posalf + shift) % 26;

    char newChar;

    if (isUpperCase(c) == 1)
    {
        return 'A' + newpos;
    }
    else
    {
        return 'a' + newpos;
    }
}

int main(int argc, char *argv[])
{

    // printf("%d", charsToShift);

    char str[100];             // Buffer for user input
    int shift = atoi(argv[1]); // convert to int

    // printf("%s", 'A' + newpos);

    while (1)
    {
        str[0] = '\0';

        scanf("%s", str);

        for (int i = 0; str[i] != '\0'; i++)
        {
            char shiftedChar = getLetterAfterShift(str[i], shift);
            printf("%c", shiftedChar);
        }

        printf("\n");
    }
    return 0;
}