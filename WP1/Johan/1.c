#include <stdio.h>

void takeNumber(int *currentNum)
{
    printf("Enter a number between 1-5: ");
    scanf("%d", currentNum);
}

int main()
{
    char arrOfStrings[6][20] = {"sentence1", "sentence2", "sentence3", "sentence4", "sentence5"}; // array of string sentences

    int num; // number input initialziation

    takeNumber(&num); // helper function call to call for an input
    printf("%s \n", arrOfStrings[num - 1]);

    while (num >= 1 && num <= 5) // loop and take input as long as its between 1-5
    {
        takeNumber(&num); // helper function call to call for an input
        printf("%s \n", arrOfStrings[num - 1]);
    }

    return 0;
}