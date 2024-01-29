#include <stdio.h>
#include <stdlib.h> // so we can we atoi.

// function to get position in alphabet of character
// taking into account uppercase because they have different ASCII values
// example: c='D', D = 68, and A is equal to 65 => 68-65 = 3, 3rd in alphabet
// example: c='d', d = 100 and a is equal to 97 => 100 - 97 = 3, 3rd in alphabet.
int getPositionInAlphabet(char c)
{
    if (c >= 'A' && c <= 'Z') // Check if the character is uppercase
    {
        return c - 'A'; // calculate the position (0-25)
    }
    else if (c >= 'a' && c <= 'z') // Check if the character is lowercase
    {
        return c - 'a'; // calculate the position (0-25)
    }
    else // handle errors
    {
        return -1;
    }
}

// function to get the letter after shifting by a certain number.
char getLetterAfterShift(char c, int shift)
{
    int positionInAlphabet = getPositionInAlphabet(c); // Get the character's position

    int newPosition = (positionInAlphabet + shift) % 26; // calcualte new position,
                                                         // using modulo to 'wrap' around alphabet, so we get no unwanted chars like numbers

    if (c >= 'A' && c <= 'Z') // Check if the character is an uppercase letter.
    {
        return 'A' + newPosition; // Calculate the shifted uppercase letter
    }
    else
    {
        return 'a' + newPosition; // Calculate the shifted lowercase letter
    }
}

int main(int argc, char *argv[])
{
    char str[100];             // Buffer for user input
    int shift = atoi(argv[1]); // Convert argument to integer

    // Infinite loop until ctrl-z is pressed.
    while (1)
    {
        str[0] = '\0'; // Clear the input buffer.

        scanf("%s", str); // Read string from user.

        for (int i = 0; str[i] != '\0'; i++) // Loop through each character in the input string.
        {
            char shiftedCharacter = getLetterAfterShift(str[i], shift); // Get the shifted character
            printf("%c", shiftedCharacter);
        }

        printf("\n");
    }
    return 0;
}