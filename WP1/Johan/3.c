#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUMBER 100

int main()
{
    srand(time(NULL));

    char userinput[100];
    int guessedCorrectly = 0, guessCount = 0, r, str;

    r = rand() % MAX_NUMBER + 1;
    printf("Random number: %d\n", r);

    while (1)
    {
        printf("Enter a number between 1-100: ");
        scanf("%d", &str);

        if (str > 100 || str < 1)
        {
            printf("Only enter a number between 1 and 100, sir!\n");
            continue;
        }

        guessCount++;

        if (str == r)
        {
            guessedCorrectly = 1;
            printf("Correct! You have guessed %d times.\n", guessCount);
            break;
        }
        else if (str > r)
        {
            printf("Your guess is too high.\n");
        }
        else
        {
            printf("Your guess is too low.\n");
        }

        printf("Do you want to try again? (y/n): ");
        scanf("%99s", userinput);

        if (userinput[0] != 'y')
        {
            printf("Game finished.\n");
            break;
        }
    }

    return 0;
}
