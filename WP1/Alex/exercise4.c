#include <stdlib.h>
#include <stdio.h>

#define BIT4 4
#define BIT8 8
#define BIT16 16
#define BIT32 32

unsigned char charDecToBinary(unsigned char n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = BIT8; i > 0; i--)
    {
        int k = n >> i; // right shift
        if (k & 1)      // helps us know the state of first bit
            printf("1");
        else
            printf("0");
    }
}

short unsignedShortDecToBinary(unsigned short n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = BIT16; i > 0; i--)
    {
        int k = n >> i; // right shift
        if (k & 1)      // helps us know the state of first bit
            printf("1");
        else
            printf("0");
    }
}

unsigned int unsignedIntDecToBinary(unsigned int n)
{
    // Size of an integer is assumed to be 32 bits
    for (int i = BIT32; i > 0; i--)
    {
        int k = n >> i; // right shift
        if (k & 1)      // helps us know the state of first bit
            printf("1");
        else
            printf("0");
    }
}

int main(int argc, char const *argv[])
{

    long arg = strtol(argv[1], NULL, 10);

    if (arg <= 255)
    {
        charDecToBinary((unsigned char)arg);
    }
    else if (arg <= 65535)
    {
        unsignedShortDecToBinary((unsigned short)arg);
    }
    else if (arg <= 4294967295)
    {
        unsignedIntDecToBinary((unsigned int)arg);
    }

    return 0;
}
