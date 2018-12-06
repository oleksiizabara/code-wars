#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initStr(char str[7]) {
    printf("enter text: ");
    gets(str);
}

int createArrays(char str[80], char letters[80], char numbers[][3]) {
    int lenStr = strlen(str);
    int indexInArray = 0;
    int indexNumber = 0;

    int lenNumbersArray = 0;


    // numbers[0][0] = str[0];
    int indexInArrayLetters = 0;
    
    for (int i = 0; i < lenStr; i++) {

        if (str[i] <= 57) {
            numbers[indexInArray][indexNumber] = str[i];
            indexNumber++;
            if (str[i+1] > 57) {
                indexInArray++;
                
            } else {
                
                lenNumbersArray--;
            }
            lenNumbersArray++;
        } else {
            letters[indexInArrayLetters] = str[i];
            indexInArrayLetters++;
            indexNumber = 0;

        }
    }
    return lenNumbersArray;
}

void initNumbers(char numbers [][3], int numbersInt[], int len) {

    for (int i = 0; i < len; i++) {
        numbersInt[i] = atoi(numbers[i]);
       
    }

  

}

int main(void) {

    char str[80];
    char letters[80];
    char numbers[80][3];
    int numbersInt[80];

    initStr(str);
    int lenNumbersArray =  createArrays(str, letters, numbers);

    initNumbers(numbers, numbersInt, lenNumbersArray);
    int EnterPosition = 0; 

    for (int i = 0; i < lenNumbersArray; i++) {
        for (int k = 0; k < numbersInt[i]; k++) {
            printf("%c", letters[i]);
            EnterPosition++; 
            if (EnterPosition%40 == 0 && EnterPosition > 0 ) {
                printf("\n");
            }
        }
    }


    
}