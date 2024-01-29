// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 4.a
// Submission code: XXXX (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h> // so we can we atoi.
#include <ctype.h>  // so we can use isdigit

int calculateBitsNeeded(unsigned int number)
{
    // 8 bits needed for decimals in range [1-225]
    if (number >= 1 && number <= 255)
    {
        return 8;
    }
    // 16 bits needed for decimals in range [256-65535]
    else if (number > 255 && number <= 65535)
    {
        return 16;
    }
    // 32 bits needed for numbers outside above ranges.
    else
    {
        return 32;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) // if 2 arguments are not provided
    {
        printf("Error, invalid number of arguments");
        return 2; // Return error code 2 indicating unsuccessful conversion.
    }

    char *input = argv[1]; // Stores the input as a string;

    for (int i = 0; input[i] != '\0'; i++) // loop over input
    {
        if (!isdigit(input[i])) // check if the value at the current position is not a number
        {
            printf("Error: Input is not a valid decimal number\n");
            return 2;
        }
    }

    unsigned int num = atoi(input); // convert argument number to int.

    int bitNeeded = calculateBitsNeeded(num); // Calculate the number of bits needed

    char binaryStr[bitNeeded + 1]; // Array to hold the binaray representation answer bits + eventual null

    int index = 0; // index tracker for binaryStr array

    unsigned int mask = 1 << (bitNeeded - 1); // Initialize mask for bitwise operations

    for (int i = 0; i < bitNeeded; i++)
    {
        if ((num & mask) == 0) // Check if bit is zero
        {
            binaryStr[index++] = '0'; // Add 0 to binaryStr array;
        }
        else if ((num & mask) != 0) // Check if bit is one. example: num: 0011 & 0011 == 0011 == 3 == bit is 1.
        {
            binaryStr[index++] = '1'; // Add a '1' to our binaryStr array.
        }

        mask >>= 1; // Shift mask right by 1
    }

    binaryStr[index] = '\0'; // terminate string

    printf("%s", binaryStr);

    return 0;
}