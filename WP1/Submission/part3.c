// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 3
// Submission code: XXXX (provided by your TA-s)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //seed the random number with the current time
    srand(time(NULL));
    int not_done = 1;
    //loop while the user wants to play
    while (not_done) {
        //pick a number between 1 and 100
        int num = rand() % 100 + 1;
        int guess = 0;
        int count = 0;
        //loop while the user has not guess the number for the round
        while (guess != num) {
            printf("Enter your guess (1-100): ");
            scanf("%d", &guess);
            //check if guess is valid
            if (guess >= 1 && guess <= 100) {
                count++;
                //guess is below number
                if (guess < num) {
                    printf("Sorry that guess was too low\n");
                //guess is above number
                } else if (guess > num) {
                    printf("Sorry that guess was too high\n");
                }
            //guess is invalid
            } else {
                printf("Please enter a valid guess\n");
            }
        }
        //guess was correct
        printf("You guessed it! it only took you %d tries\n", count);
        printf("Play again? (0 - no, 1 - yes): ");
        scanf("%d", &not_done);
    }
    return 0;
}