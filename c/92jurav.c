#include <stdio.h>

int howMuch(void) {
    int s;
    printf("Enter numbers of juravl: ");
    scanf("%i", &s);

    return s;
}

int howMuchPetyaAndSerg(int s) {
    return s/6;
}

int howMuchKate(int s) {
    return 2*s/3;
}

int main(void) {
    int s = howMuch();
    printf("%i %i %i", howMuchPetyaAndSerg(s),howMuchKate(s), howMuchPetyaAndSerg(s) );
}