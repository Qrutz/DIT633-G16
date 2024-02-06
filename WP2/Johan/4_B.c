#include <stdio.h>
#include <string.h>

// function to transform hex decimal character into integer
// ex: A has ascii value 65 => (A - A) + 10 = 10
// ex: 5 has ascii value 53 => (53 - 48) = 5;
int hexDecToInt(char c)
{
    // if char is between A and F (uppercase)
    if (c >= 'A' && c <= 'F')
    { // between A and F, add 10 + ascii value of char
        return (c - 'A') + 10;
    }
    else if (c >= 'a' && c <= 'f')
    {
        return (c - 'a') + 10;
    }
    else // else we can assume the char is between 0-9
    {
        return c - '0';
    }
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Only one argument allowed sir! \n");
        return 0;
    }

    // Convert the input from hexadecimal string to an integer
    // unsigned int packedByte = (hexDecToInt(argv[1][0]) << 4) | hexDecToInt(argv[1][1]);

    unsigned int packedByte = 0; // initlaize packedbyte with 0000 0000

    // loop over chars in input
    // ex: input 0xAB, packedbyte initial state is 0000 0000
    // so after first iteration with A, packedByte is 0000 1010
    // next iteration we first off need to shift left by 4 to make room for new values, 1010 0000
    // after b we have => 1010 1011
    for (int i = 0; i < strlen(argv[1]); i++)
    {

        packedByte <<= 4;                      // shift 4 left to make room for new values
        packedByte |= hexDecToInt(argv[1][i]); // put each hexdecimal digit into packedbyte
                                               // ex: packedByte |= 1010 => 0000 0000 |= 1010 => 0000 1010
                                               // then we just shift, next iteration to do the same thing
    }

    // Here we extract binary values from the packedBytes value with bitwise OR and bit shifting.
    unsigned int engine_on = (packedByte >> 7) & 0x01; // Extract MSB (bit 8) by shifting right by 7 and bitwise AND'ing it
                                                       // so 1010 1010 becomes 0000 0001 & 0000 0001 == 1 is extracted.
    unsigned int gear_pos = (packedByte >> 4) & 0x07;  // Extracts bit 7-5 using above method.
    unsigned int key_pos = (packedByte >> 2) & 0x03;   // Extracts bit 4-3
    unsigned int brake1 = (packedByte >> 1) & 0x01;    // Extracts bit 2
    unsigned int brake2 = packedByte & 0x01;           // Extracts LSB (Bit 1) // no need to shift since we are already at lsb bit

    printf("Name            Value\n");
    printf("---------------------------------\n");
    printf("engine_on:       %d\n", engine_on);
    printf("gear_pos:        %d\n", gear_pos);
    printf("key_pos:         %d\n", key_pos);
    printf("brake1:          %d\n", brake1);
    printf("brake2:          %d\n", brake2);

    return 0; // kill program
}