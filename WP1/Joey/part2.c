// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 2
// Submission code: XXXX (provided by your TA-s)
#include <stdio.h>

int main() {
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

        //performs rot13 encryption
        for (int i = 0; plaintext[i] != '\0'; i++) {
            //subtracts 13 if the letter is n - z
            if ((plaintext[i] >= 'n' && plaintext[i] <= 'z') || (plaintext[i] >= 'N' && plaintext[i] <= 'Z')) {
                plaintext[i] -= 13;
            //adds 13 if the letter is a - m
            } else if ((plaintext[i] >= 'a' && plaintext[i] <= 'm') || (plaintext[i] >= 'A' && plaintext[i] <= 'M')) {
                plaintext[i] += 13;
            }
        }

        printf("%s\n", plaintext);
    }
}