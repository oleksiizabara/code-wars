#include <stdio.h>


int howMuch(int a, int b) {
    return a-b;
}

int main(void) {
    int Larry;
    int Barry;

    scanf("%i", &Larry);
    scanf("%i", &Barry);


    int numberOfButles = Larry + Barry - 1;

    int noBarry = howMuch(numberOfButles, Barry);
    int noLarry = howMuch(numberOfButles, Larry);

    printf("%i %i", noBarry, noLarry);
}