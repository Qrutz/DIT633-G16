#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    int guessNumber;
    int amountOfGuesses = 0;

    int randomNumber = rand() % 100 + 1;

    bool playAgain = true;
    char playAgainQuestion = 'n';

    printf("%d\n", randomNumber);

    while (playAgain)
    {
        printf("Guess the random number between 1 and 100\n");
        scanf("%d", &guessNumber);

        if (guessNumber > 100 || guessNumber < 1)
        {
            printf("Number must be in range of 1-100\n");
        }
        else if (guessNumber > randomNumber)
        {
            printf("Your guess is too high\n");
            amountOfGuesses++;
        }
        else if (guessNumber < randomNumber)
        {
            printf("Your guess is too low\n");
            amountOfGuesses++;
        }
        else
        {
            amountOfGuesses++;
            printf("You have guessed %d times and your guess is correct\n", amountOfGuesses);
            printf("Do you want to play again? y/n\n");
            scanf(" %c", &playAgainQuestion);
            if (playAgainQuestion == 'n')
            {
                playAgain = false;
                break;
            }
            else if (playAgainQuestion == 'y')
            {
                randomNumber = rand() % 100 + 1;
                amountOfGuesses = 0;
                playAgain = true;
            }
        }
    }
    return 0;
}
