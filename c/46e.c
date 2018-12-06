#include <stdio.h>

int whereRound(int n) {
    return n + 2;
}

void roundE(char e[27]) {
    int n;
    printf("enter n: ");
    scanf("%i", &n);

   n = whereRound(n);

   printf("%s\n", e);

   if (e[n-1] != '.') {
    for (int i = 0; i < n-1; i++) {
       printf("%c", e[i]);
    }

    if (e[n] > 52) {
       printf("%c\n", e[n-1]+1);
    } else {
       printf("%c\n", e[n-1]);
    }
   } else {
       printf("3");
   }

}

int main(void) {
    char e[27] = "2.7182818284590452353602875";

    roundE(e);
}