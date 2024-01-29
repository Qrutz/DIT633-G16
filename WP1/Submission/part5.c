// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 14 __ (2022)
// Work package 1
// Exercise 5
// Submission code: XXXX (provided by your TA-s)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);

// ------ Function definitions ----------
// defining creation of array of random ints
void create_random(int *tab)
{
    // from 0 to MAXNUMBER, fill that spot with a random number from 0 to MAX
    for (int i = 0; i < MAX; i++)
    {
        tab[i] = rand() % (MAXNUMBER);
    }
}

// defining counting frequencies function
void count_frequency(int *tab, int *freq)
{
    // for every number in the table, add 1 to that number's position in frequency
    for (int i = 0; i < MAX; i++)
    {
        freq[tab[i]]++;
    }
}

// defining function to draw histograms
void draw_histogram(int *freq)
{
    // get every frequency that is above 0
    for (int i = 0; i < MAXNUMBER; i++)
    {
        if (freq[i] != 0)
        { // dont print out 0s
            printf("%d", i);
            // Ensure clean formatting
            if (i < 10)
            {
                printf("    ");
            }
            else
            {
                printf("   ");
            }
            // for every count, print out an x
            for (int j = 0; j < freq[i]; j++)
            {
                printf("x");
            }
            printf("\n");
        }
    }
}

// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{
    int table[MAX];                 // initialize table
    int frequency[MAXNUMBER] = {0}; // initialize frequency table to 0

    // seed the random function
    srand(time(NULL));

    create_random(table);              // create random table
    count_frequency(table, frequency); // count frequencies

    // Printing frequency table
    /*
    for (int i = 0; i < MAXNUMBER; i++) {
        printf("%d: %d\n", i, frequency[i]);
    }
    */

    draw_histogram(frequency);

    return 0;
}