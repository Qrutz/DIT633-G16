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
        if (!isdigit(input[i])) // check if the value at the current position is not a number so we can return an error.
        {
            printf("Error: Input is not a valid decimal number\n");
            return 2;
        }
    }

    unsigned int num = atoi(input); // convert argument number to int so we can use it in bitwise operations.

    int bitNeeded = calculateBitsNeeded(num); // Calculate the number of bits needed to represent the number.

    char binaryStr[bitNeeded + 1]; // Array to hold the binaray representation answer bits + eventual null termination.

    int index = 0; // index tracker for binaryStr array to keep track of where to add the next bit.

    unsigned int mask = 1 << (bitNeeded - 1); // Initialize mask for bitwise operations.

    // iterate over number of bits and use bitwise AND operation to check if bit is 0 or 1.
    // so starting with the left most bit, ex: 10000000 we do a bitwise AND to figure out if the bit is 0 or 1
    // and then keep shifting the mask right until we have checked all bits.
    for (int i = 0; i < bitNeeded; i++) //
    {
        if ((num & mask) == 0) // Check if bit is zero using bitwise AND. ex: 1000 & 0000 = 0 => bit is 0.
        {
            binaryStr[index++] = '0'; // Add 0 to binaryStr array;
        }
        else if ((num & mask) != 0) // Check if bit is one using bitwise AND. ex: 0100 & 0100 == 0100 = 4 => bit is 1.
        {
            binaryStr[index++] = '1'; // Add a '1' to our binaryStr array.
        }

        mask >>= 1; // Shift mask right by 1
    }

    binaryStr[index] = '\0'; // terminate string

    printf("%s", binaryStr);

    return 0;
}