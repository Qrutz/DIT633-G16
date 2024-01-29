// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 2
// Submission code: XXXX (provided by your TA-s)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int rotation;
    char *check;
    //check arguments are correct
    if (argc != 2) {
        printf("Error: Invalid number of arguments. Please enter only 1 argument, the encryption offset.");
        return 2;
    }

    //check that string value is a number
    check = argv[1];
    while (*check) {
        //check if the value at the current position is not a number
        if (isdigit(*check++) == 0) {
            printf("Error: Invalid number.");
            return 2;
        }
    } 

    //check that value is between 1 and 25
    rotation = atoi(argv[1]);
    if (rotation < 1 || rotation > 25) {
        printf("%d", rotation);
        printf("Error: Invalid number. Please enter an integer between 1 and 25");
        return 2;
    }

    //will run until an EOF is entered
    while (1) {
        //stores the plaintext string
        char plaintext[50] = "\032";
        //prompts the user to enter a string
        printf("Please enter the text that you would like to be encrypted: ");
        scanf("%s", plaintext);

        if(*plaintext == '\032') {
            return 0;
        }

        //performs caesar cipher encryption according to argument input
        for (int i = 0; plaintext[i] != '\0'; i++) {
            int temp = (int)plaintext[i];
            if (temp >= 65 && temp <= 90) {
                temp += rotation - 65;
                temp %= 26;
                printf("%d", temp + 65);
            } else if (temp >= 97 && temp <= 122) {
                temp += rotation - 97;
                temp %= 26;
                printf("%c", temp + 97);
            } else {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
}