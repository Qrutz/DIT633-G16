#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

void create_random(int *tab)
{
    for (int i = 0; i < MAX; i++)
    {
        tab[i] = rand() % MAXNUMBER;
    }
}

void count_frequency(int *tab, int *freq)
{
    for (int i = 0; i < MAXNUMBER; i++) // fill with zeros
    {
        freq[i] = 0;
    }
    for (int i = 0; i < MAX; i++)
    {
        freq[tab[i]]++;
    }
}

void draw_histogram(int *freq)
{
    for (int i = 0; i < MAXNUMBER; i++)
    {

        if (freq[i] > 0)
        { // Check if the frequency is greater than 0
            printf("%d: ", i);
            for (int j = 0; j < freq[i]; j++)
            {
                putchar('*');
            }
            putchar('\n');
        }
    }
}

int main(void)
{
    srand(time(NULL));
    int table[MAX], n;
    int frequency[MAXNUMBER];

    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);

    return 0;
}