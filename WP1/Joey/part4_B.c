// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 1
// Submission code: XXXX (provided by your TA-s)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

char* bin_2_hex(int *input, int *size) {
    //Ensure that character array is no bigger than necessary
    *size /= 4;
    //defining hex array for output
    char *hex_array = (char *)malloc(*size * sizeof(char));
    //defining digits of hex
    char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    //counter for allocating digits to correct positin
    int c = 0;

    for (int i = 0; i < *size * 4; i += 4) {
        //temporary store for calculations
        int temp_calc = 0;
        for (int j = 0; j < 4; j++) {
            temp_calc += pow(2, 3 - j) * input[j + i];
        }
        hex_array[c++] = digits[temp_calc];
    }

    return hex_array;
}

int main(int argc, char *argv[]) {
    //help flag
    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0) {
            printf("Run the program then enter the binary number that you would like to convert to hexadecimal.\n");
            printf("It is possible to use this program in conjunction with dec2bin.exe in the following format:\n");
            printf("> .\\dec2bin.exe <decimal number> | .\\bin2hex.exe");
            return 0;
        } else {
            printf("Error: Please run the program THEN enter the number in binary:\n\n");
            printf("> .\\bin2hex.exe\n");
            printf("> <binary number here>\n\n");
            printf("Use the program in conjunction with the dec2bin complementary program if unclear:\n");
            printf("> .\\dec2bin.exe <decimal number> | .\\bin2hex.exe");
            return 2;
        }
    }

    int size = 0;
    int *bit_array;
    char input[100];
    char *check;

    //cleaning up input
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';
    size = strlen(input);

    //Check the number for validity
    check = input;
    while (*check) {
        //check if the value at the current position is not a bit
        if (*check != '0' && *check != '1') {
            printf("Error: Invalid binary number. Make sure your number contains only 1's and 0's");
            return 2;
        } else {
            *bit_array = *check - '0';
            check++;
            bit_array++;
        }
    }

    //check size formatting matches specification
    if (size % 4 != 0) {
        printf("Error: invalid bit size. Include trailing 0's so that the bit size is a multiple of 4");
        return 2;
    } 

    //reset pointer
    bit_array -= size;

    //temporary store of array for testing
    char *temp_array = bin_2_hex(bit_array, &size);

    for (int i = 0; i < size; i++) {
        printf("%c", temp_array[i]);
    }
    return 0;
}