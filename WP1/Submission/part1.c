// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 1
// Submission code: XXXX (provided by your TA-s)
#include <stdio.h>

int main() {
    int choice = 1; //variable to store user's choice

    //runs while choice is valid
    while (choice >= 1 && choice <= 5) {
        //Prompt for input from user
        printf("Please enter a number between 1 and 5: ");
        scanf("%d", &choice);

        //Deciding which statement to output based on the user's choice
        switch (choice) {
            case 1:
                printf("Wow, 1 nice choice.");
                break;
            case 2:
                printf("Ooo 2, fantastic choice.");
                break;
            case 3:
                printf("Whoa! 3!? Awesome choice.");
                break;
            case 4:
                printf("Hey, 4? Nice, what a choice.");
                break;
            case 5:
                printf("Niiiiice, 5, nice choice.");
                break;
            default:
                printf("Error: Please enter a number between 1 and 5");
                return 1;
        }
        printf("\n");
    }
}