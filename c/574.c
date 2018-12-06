#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void initStr(char str1[100000], char str2[100000]) {

    printf("enter first str: ");
    gets(str1);

    printf("enter second str: ");
    gets(str2);
}

bool findLetter(char letter, char str[100000]) {

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if(str[i] == letter) {
            str[i] = '*';
            return true;
        }
    }
    return false;
}

bool analiseStr(char str1[100000], char str2[100000]) {

    int len = strlen(str1);
  
    for (int i = 0; i < len; i++) {
        if(!findLetter(str1[i], str2)){
            return false;
        }
    }
    return true;
}

void printResults(char str1[100000], char str2[100000]) {

        if (analiseStr(str1, str2)) {
        printf("YES");
    } else {
        printf("NO");
    }
}


int main(void) {

    char firstStr[100000];
    char secondStr[100000];

    initStr(firstStr, secondStr);
    printResults(firstStr, secondStr);    
}