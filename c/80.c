#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void initFormula(char formula[100]) {

    printf("enter formula: "); 
    gets(formula);
    
}

int initArrayFormula(char formula[100], char arrayFormulaElements[][5]) {

    int indexInArray = 0;
    int indexInElemenet = 0;
    int numberOfElements = 0;

    int len = strlen(formula);

    for(int i = 0; i < len; i++) {
        if(formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == '='){
            indexInArray++;
            numberOfElements++;
            indexInElemenet = 0;
            arrayFormulaElements[indexInArray][0] = formula[i];
            arrayFormulaElements[indexInArray][1] = '\0';

            indexInArray++;
        } else {
            arrayFormulaElements[indexInArray][indexInElemenet] = formula[i];
            
            if (indexInElemenet == 0){
                numberOfElements++;
            }

            indexInElemenet++;
        }
    }
    return numberOfElements;
}

bool ifNumberstr(char str[5]) {

    for(int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool correctElements(char arr[][5], int n) {
  
    if (n == 5 && (arr[1][0] == '+' || arr[1][0] == '-' || arr[1][0] == '*' || arr[1][0] == '/') && 
        arr[3][0] == '=' && (ifNumberstr(arr[0]) && ifNumberstr(arr[2]) && ifNumberstr(arr[4]) )) {
            return true;
        }
    return false;
}

void checkFormula(char arrayFormulaElements[][5]) {

    int number_1 = atoi(arrayFormulaElements[0]);
    int number_2 = atoi(arrayFormulaElements[2]);
    int number_3 = atoi(arrayFormulaElements[4]);

    if(arrayFormulaElements[1][0] == '+') {
        if(number_1 + number_2 == number_3) {
            printf("YES");
        } else {
            printf("NO");
        }
    }
    if(arrayFormulaElements[1][0] == '-') {
        if(number_1 - number_2 == number_3) {
            printf("YES");
        } else {
            printf("NO");
        }
    }

    if(arrayFormulaElements[1][0] == '*') {
        if(number_1 * number_2 == number_3) {
            printf("YES");
        } else {
            printf("NO");
        }
    }

    if(arrayFormulaElements[1][0] == '/') {
        if(number_1 / number_2 == number_3) {
            printf("YES");
        } else {
            printf("NO");
        }
    }
}

int main(void) {

    char formula[100];

    initFormula(formula);

    char arrayFormulaElements[5][5];

    int numberOfElements = initArrayFormula(formula, arrayFormulaElements);

    if (correctElements(arrayFormulaElements, numberOfElements)) {
        checkFormula(arrayFormulaElements);
    } else {
        printf("ERROR");
    }
}