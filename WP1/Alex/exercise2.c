#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char input[20];

char encryptedWord[20];

bool isActive = true;

char lowerCaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
char upperCaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        printf("Please enter an int as argument\n");
        isActive = false;
    }

    while (isActive)
    {
        printf("Enter a word: ");
        scanf("%s", input);

        // Loop over input word, and loop over alphabet/letters array. Check if current letter is upper or lowercase letter. Then loop over respective alphabet
        // array and if current input letter is equal to alphabet letter, then add (alphabet letter + argument int) to encrypted word.
        for (int i = 0; i < strlen(input); i++)
        {
            if (islower(input[i]))
            {
                for (int j = 0; j < strlen(lowerCaseLetters); j++)
                {
                    if (input[i] == lowerCaseLetters[j])
                    {
                        // Modulo 26 is used to start from beginning of alphabet if the current letter + arg int is larger than 26.
                        encryptedWord[i] = lowerCaseLetters[(j + atoi(argv[1])) % 26];
                        break;
                    }
                }
            }
            else if (isupper(input[i]))
            {
                for (int j = 0; j < strlen(upperCaseLetters); j++)
                {
                    if (input[i] == upperCaseLetters[j])
                    {
                        encryptedWord[i] = upperCaseLetters[(j + atoi(argv[1])) % 26];
                        break;
                    }
                }
            }
        }
        printf("Encrypted word: %s\n", encryptedWord);
        // Clear the encrypted and input word. If next user input word is shorter than the current one, the encrypted/input word will still have the old letters.
        for (int i = 0; i < strlen(encryptedWord); i++)
        {
            // \0 is null character, it is used to terminate strings
            encryptedWord[i] = '\0';
            input[i] = '\0';
            ;
        }
    }
    return 0;
}
