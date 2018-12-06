#include <stdio.h>
#include <ctype.h>
#include <string.h>

void initNames(char command[50], char name1[50], char name2[50], char name3[50]) {

    printf("enter command: ");
    gets(command);

    printf("enter name1: ");
    gets(name1);

    printf("enter name2: ");
    gets(name2);

    printf("enter name3: ");
    gets(name3);
}

void addNameToArray(char arr[][50], char name1[50], char name2[50], char name3[50]) {
    strcpy(arr[0],name1);
    strcpy(arr[1],name2);
    strcpy(arr[2],name3);
}

void sort( char arr[][50]) {

    char timeVar[50];
    for (int n = 0; n < 3; n++) {
        for(int m = 2; m >= 1; m--){
            if (strcmp(arr[m], arr[m-1]) > 0){
                strcpy(timeVar, arr[m]);
                strcpy(arr[m], arr[m-1]);
                strcpy(arr[m-1], timeVar);
            }
        }
    }
}

int main(void) {
    char command[50];
    char name1[50];
    char name2[50];
    char name3[50];

    char arr[3][50];

    initNames(command, name1, name2, name3);

    printf("%s: ",command);
    addNameToArray(arr, name1, name2, name3);
    sort(arr);

    printf("%s, ", arr[2]);
    printf("%s, ", arr[1]);
    printf("%s ", arr[0]);
}