#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    int N, A, B;
    printf("enter numbers of palels N:");
    scanf("%i", &N);

    printf("enter A:");
    scanf("%i", &A);

    printf("enter B:");
    scanf("%i", &B);

    int square = 2*A*B*N;

    printf("%i\n", square);
}