#include <stdio.h>
#include <stdlib.h> // so we can we atoi.

int getPositionInAlphabet(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else if (c >= 'a' && c <= 'z')
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
    int positionInAlphabet = getPositionInAlphabet(c);

    int newPosition = (positionInAlphabet + shift) % 26;

    if (c >= 'A' && c <= 'Z')
    {
        return 'A' + newPosition;
    }
    else
    {
        return 'a' + newPosition;
    }
}

int main(int argc, char *argv[])
{
    char str[100];             // Buffer for user input
    int shift = atoi(argv[1]); // convert to int

    while (1)
    {
        str[0] = '\0';

        scanf("%s", str);

        for (int i = 0; str[i] != '\0'; i++)
        {
            char shiftedCharacter = getLetterAfterShift(str[i], shift);
            printf("%c", shiftedCharacter);
        }

        printf("\n");
    }
    return 0;
}