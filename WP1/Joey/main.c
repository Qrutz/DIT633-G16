//Joey Karlsson

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//main function in the program
int main (int argc, char *argv[]) {
    //will store the location of the string input
    char *check;
    //stores the value of input
    int num;
    //binary operator
    int bin_op = 1;
    //0 counter
    int c_0 = 0;
    //1 counter
    int c_1 = 0;

    //checks to make sure there is exactly 1 argument
	if (argc < 2) {
        printf("Error: No number provided. Please provide a number as a command line argument.");
        return 0;
    }

    if (argc > 2) {
        printf("Error: Too many arguments provided. Please provide a number as a command line argument.");
        return 0;
    }

    //checks to make sure that the given input is an integer
    check = argv[1];
    while (*check) {
        //check if the value at the current position is not a number
        if (isdigit(*check++) == 0) {
            printf("Error: Invalid number.");
            return 0;
        }
    }

    //converts string to int
    num = atoi(argv[1]);
    printf("Number: %d\n", num);
    //sets up binary operator
    while (bin_op * 2 <= num) {
        bin_op *= 2;
    }

    //preparing to print binary output
    printf("Binary: 0b");

    //bit operation
    while (bin_op >= 1) {
        //subtracts binary operator when num > bin_op, output a 1
        if (num >= bin_op) {
            num -= bin_op;
            printf("1");
            c_1++;
        //num < op, output a 0
        } else {
            printf("0");
            c_0++;
        }
        bin_op /= 2;
    }

    
    printf("\nNumber of 0s: %d\n", c_0);
    printf("Number of 1s: %d\n", c_1);
    return 0;    
}