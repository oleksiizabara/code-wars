#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initNumber(char number[1000]) {
    printf("enter number: ");
    scanf("%s", number);
    
}

void help(char number[1000]) {
    int len = strlen(number);
    
    int sum = 0;
    int index = 0;

    if (len > 1) {
        index = 1;
    }

     for (int i = 0; i < len; i++) {
            sum = sum + (int)number[i] - 48;
        }
    
    itoa(sum, number, 10);
    len = strlen(number);

    while(sum > 9) {
        sum = 0;

        for (int i = 0; i < len; i++) {
            sum += (int)number[i] - 48;
        }
            
        if(sum > 9) {
            itoa(sum, number, 10);
            len = strlen(number);
         }
         index++;
    }

    printf("%i %i\n", sum, index);
}

int main(void) {
    char number[1000];
    initNumber(number);

    help(number);
}