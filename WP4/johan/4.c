#include <stdio.h>
#include <unistd.h>
#include <string.h>

int search_number(int number, int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == number)
        {
            return i;
        }
    }
}

void swap(int *num, int *num2)
{
    int temp = *num;
    *num = *num2;
    *num2 = temp;
}

void sort(int number, int tab[])
{
    int i, j;
    for (i = 0; i < number - 1; i++)
    {
        for (j = 0; j < number - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                swap(&tab[j], &tab[j + 1]);
            }
        }
    }
}

int main(char *argv[])
{

    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};

    printf("%d", search_number(34, test, 10));

    sort(10, test);

    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", test[i]);
    }

    return 0; // kill program
}