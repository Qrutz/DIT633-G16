// (C) __Alexander Helsing, Joey Karlsson, Johan Sandgren, group: 16 __ (2022)
// Work package 3
// Exercise 6
// Submission code: XXXX (provided by your TA-s)
//this program will copy a string to another location, from input and from a file redirect
#include <stdio.h>
#include <string.h>

#define MAX 20

//custom copy function
void copyString(char *destination, char *value) {
    int i = 0;
    while (value[i] != '\0') {
        destination[i] = value[i];
        i++;
    }
    //copy null terminator
    destination[i] = value[i];
}

//main
int main () {
    char str1[MAX];
    char str2[MAX];
    char str3[MAX];

    //getting user input
    printf("Enter the string you'd like copied to a new location: ");
    fgets(str1, MAX, stdin);

    //baselining
    printf("String \"%s\" received to location: %p\n", str1, (void*)str1);

    //copying using own method
    copyString(str2, str1);
    printf("String \"%s\" copied to new location: %p\n", str2, (void*)str2);

    //copying using strcpy method
    strcpy(str3, str2);
    printf("String \"%s\" copied to new location: %p (strcpy)\n", str3, (void*)str3);
    return 0;
}