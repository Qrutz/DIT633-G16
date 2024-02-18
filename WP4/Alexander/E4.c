#include <stdlib.h>
#include <stdio.h>

int test[] = {1,2,34,5,67,3,23,12,13,10};

int arrayLength = sizeof(test) / sizeof(test[0]);

int num = 23;

int search_number(int number, int tab[], int size){
    for(int i = 0; i < size; i++){
        if(tab[i] == number){
            return i;
        }
    }
    return -1;
}

void swap(int* num, int* num2){
    int temp = *num;
    *num = *num2;
    *num2 = temp;
}

void sort(int number, int tab[]){
    int i, j;
    for(i = 0; i < number -1; i++){
        for(j = 0; j < number - i - 1; j++){
            if(tab[j] > tab[j + 1]){
                swap(&tab[j], &tab[j + 1]);
            }
        }
    }
}


int main(int argc, char const *argv[])
{

    sort(arrayLength, test);

    printf("%d", arrayLength);
    printf("\n");

    for(int i = 0; i < arrayLength; i++){
        printf("%d", test[i]);
        printf(" ");
    }

    int answer = search_number(num, test, arrayLength);

    printf("\n");
    printf("%d", answer);

    return 0;
}
