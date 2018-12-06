#include <stdio.h>
#include <string.h>

void maxFromThree(char * field) {
    int len = strlen(field);

    char newField[len + 2];

    for (int i = 0; i < len; i++) {
        newField[i] = field[i];
    }

    newField[len] = field[0];
    newField[len+1] = field[1];

    int maxField = newField[0] + newField[1] + newField[2] - 144;

    for (int i = 1; i < len; i++) {
        int custom = newField[i] + newField[i+1] + newField[i+2] - 144;
        if(custom > maxField) {
            maxField = custom;
        }
    }
    printf("%i", maxField);
}

int main(void) {
    char * field = "123";
    maxFromThree(field);
}