#include <stdio.h>
#include <stdlib.h> // so we can we atoi.

int calculateBitsNeeded(unsigned int number)
{
    if (number >= 1 && number <= 255)
    {
        return 8;
    }
    else if (number > 255 && number <= 65535)
    {
        return 16;
    }
    else
    {
        return 32;
    }
}

int main(int argc, char *argv[])
{
    unsigned int num = atoi(argv[1]); // convert argument number to int.

    int bitNeeded = calculateBitsNeeded(num);

    char binaryStr[bitNeeded + 1]; // Array to hold the binaray representation answer bits + eventual null

    int index = 0; // index tracker for binaryStr array

    unsigned int mask = 1 << (bitNeeded - 1);

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