#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // error handling
    if (argc != 6)
    {
        printf("You need to enter atleast 5 arguments!\n");
        return 0;
    }
    unsigned int engine_on = atoi(argv[1]); // 1 bits MSB
    unsigned int gear_pos = atoi(argv[2]);  // 3 bits 0 - 7
    unsigned int key_pos = atoi(argv[3]);   // 2 bits 0, 1, 2
    unsigned int brake1 = atoi(argv[4]);    // 1
    unsigned int brake2 = atoi(argv[5]);    // Bit no 1 LSB

    // Error handling for input ranges
    if (engine_on > 1) // 0 or 1
    {
        printf("engine_on must be either 0 or 1! \n");
        return 0;
    }
    // 3 bits, 7 availible positions => so should use bits 6-4
    if (gear_pos > 7)
    {
        printf("gear_pos must be between 0 and 7 \n");
        return 0;
    }
    // 2 bits max
    if (key_pos > 2)
    {
        printf("key_pos must be between 0 and 2 \n");
        return 0;
    }
    // 1 bit max
    if (brake1 > 1)
    {
        printf("brake1 must be either 0 or 1! \n");
        return 0;
    }
    // 1 bit max
    if (brake2 > 1)
    {
        printf("brake2 must be either 0 or 1! \n");
        return 0;
    }

    unsigned char packedByte = 0; // initalize empty byte

    // We need to shift each value so they dont overlap on the LSB (right most bit)
    // So we simply shift each 'value' to place them on the correct position in the byte.
    // Then we use bitwise OR to place them in the byte.
    packedByte |= engine_on << 7; // MSB, should be on first position so shift by 7 to place it there.
    packedByte |= gear_pos << 4;  // 3 bits, 7 availible positions => so should use bits 6-4, to the right of MSB
    packedByte |= key_pos << 2;   // 2 BITS, shift left by 2 to place bits on bit 3 and 2
    packedByte |= brake1 << 1;    //  should be placed on bi1
    packedByte |= brake2;         // should be placed on LSB, it already is there so we dont need to do anything.

    printf("Byte in hexdec: 0x%X\n", packedByte);

    return 0; // kill program
}