// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 16 __ (2022)
// Work package 3
// Exercise 5
// Submission code: XXXX (provided by your TA-s)
//this program will create an array of MAX random numbers, and output various data about the array
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10

//function to generate an array of random numbers between 1 and 99
void gen_numbers(int *ptr) {
    for (int i = 0; i < MAX; i++) {
        ptr[i] = (rand() % 99) + 1;
    }
}

//main
int main () {
    int arr[MAX];

    //seed random, generate numbers
    srand(time(NULL));
    gen_numbers(arr);

    //printing data
    printf("The value of the address of the array (pointer) is: %d\n", arr);
    printf("First integer in the array is (array[0]): %d\n", arr[0]);
    printf("The last integer in the array is: %d\n", arr[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %d\n", sizeof(int));
    printf("The size of the whole array in bytes is: %d\n", sizeof(int) * MAX);

    printf("Now printing every value multiplied by 2:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d\n", arr[i] * 2);
    }

    return 0;
}