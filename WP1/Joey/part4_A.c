// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 1
// Submission code: XXXX (provided by your TA-s)

//This script will turn a base 10 number to binary
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int* dec_2_bin(char *input, int *size) {
    //error checker
    char *check;
    //sets up binary operator
    int bin_op = pow(2, *size - 1);
    //stores input as long
    long int_input;

    //Check the number for validity
    check = input;
    while (*check) {
        //check if the value at the current position is not a number
        if (isdigit(*check++) == 0) {
            printf("Error: Invalid number.");
            return NULL;
        }
    }   
    int_input = atoi(input);

    //Calculating size of bit array
    while (bin_op * 2 <= int_input) {
        *size += 8;
        bin_op = pow(2, *size - 1);
    }
    //defining bit array for output
    int *bit_array = (int *)malloc(*size * sizeof(int));
    //bit operation
    int c = 0;
    while (bin_op >= 1) {
        //printf("%d and %d\n", bin_op, num);
        //subtracts binary operator when num > bin_op, output a 1
        if (int_input >= bin_op) {
            int_input -= bin_op;
            bit_array[c] = 1;
        //num < op, output a 0
        } else {
            bit_array[c] = 0;
        }
        bin_op /= 2;
        c++;
    }
    return bit_array;
}

int main(int argc, char *argv[]) {
    //Smallest bit array size
    int size = 8;
    //check to ensure correct number of arguments have been entered
    if (argc != 2) {
        printf("Error, invalid number of arguments");
        return 2;
    }

    //temp storage of bit array
    int *temp_storage = dec_2_bin(argv[1], &size);

    if (temp_storage == NULL) {
        return 2;
    }

    //stdout for bit array
    for (int i = 0; i < size; i++) {
        printf("%d", temp_storage[i]);
    }

    return 0;
}