#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10

int main(char *argv[])
{

    srand(time(NULL));
    int arr[MAX];
    int *ptr = arr;

    for (int i = 0; i < MAX; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("The value of the address of the array (pointer) is: %p\n", arr);
    printf("First integer in the array is (array[0]): %d\n", arr[0]);
    printf("The last integer in the array is: %d\n", arr[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %d\n", (int)sizeof(int));
    printf("The size of the whole array in bytes is:  %d\n", (int)sizeof(arr));

    for (int i = 0; i < MAX; i++)
    {
        printf("array[%d] = %d, 2x = %d\n", i, *ptr, *ptr * 2);
        ptr++;
    }

    return 0;
}