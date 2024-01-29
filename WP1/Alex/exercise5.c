#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 100 // Defines the maximum number of the values in the table

#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab)
{
    for (int i = 0; i < MAX; i++)
    {
        tab[i] = rand() % MAXNUMBER;
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq)
{
    for (int i = 0; i < MAX; i++)
    {
        freq[tab[i]]++;
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq)
{
    for (int i = 0; i < MAXNUMBER; i++)
    {
        if (freq[i] != 0)
        {
            printf("%d", i);
            for (int j = 0; j < freq[i]; j++)
            {
                printf("x");
            }
            printf("\n");
        }
    }
}

// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly

int *pI = &i;

int main(void)
{

    srand(time(NULL));

    int i = 0;

    int table[MAX], n;
    int frequency[MAXNUMBER];

    create_random(table);

    count_frequency(table, frequency);

    for (int i = 0; i < MAX; i++)
    {
        printf("%d", table[i]);
    }

    draw_histogram(frequency);

    printf("%d\n", CHAR_MAX);
    printf("%p", table);
}