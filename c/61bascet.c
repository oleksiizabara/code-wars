#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MATCHES 4
#define COMMANDS 2

    

void initTable(int results[][MATCHES]);
void resultsOfAllMatches(int results[][MATCHES]);
void whoIsWinner(int a, int b);

void initTable(int results[][4]){
    for (int i = 0; i < 4; i++) {
        printf("enter results  of %i match: \n", i+1);
        for (int k = 0; k < 2; k++) {
            scanf("%i", &results[i][k]);
        }
    }
}

void  resultsOfAllMatches(int results[][MATCHES]){
    int sum1 = 0, sum2 = 0;
    for (int k=0; k < 2; k++) {
        for (int i = 0; i < 4; i ++) {
            if (k%2==0){
                sum1 += results[i][k];
            } else {
                sum2 += results[i][k];
            }
        }
    }

    printf ("%i %i - ", sum1, sum2);
    whoIsWinner(sum1, sum2);
}

void whoIsWinner (int a, int b) {
    if (a>b) {
        printf("1 win");
    } else if (a<b) {
        printf("2 win");
    } else {
        printf("DRAW");
    }
}

int main(void) {

    int results[COMMANDS][MATCHES];
    initTable(results);
    resultsOfAllMatches(results);

}