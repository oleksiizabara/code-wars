#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int initN(int n) {

    printf("enter n: ");
    scanf("%i", &n);
    return n;
}

void initSudoku(int n, int sudoku[][100]) {

    for (int i = 0; i < n*n; i++) {
        for (int k = 0; k < n*n; k++) {
            printf("enter coords %i-%i: ", i, k);
            scanf("%i", &sudoku[i][k]);
        }
    }
}

bool searchNumberInRow(int i, int k, int n, int sudoku[][100] ) {

    for (int t = 0; t < n*n; t++) {
        if (sudoku[i][t] == k) {
            return true;
        }
    }
    return false;
}

bool searchInRows(int n, int sudoku[][100]){
    
    for(int i = 0; i < n*n; i++) {
        for(int k = 1; k <= n*n; k++) {
            if(!searchNumberInRow(i, k, n, sudoku)) {
                return false;
            }
        }
    }
    return true;
}

bool searchNumberInColumn(int i, int k, int n, int sudoku[][100] ) {

    for (int t = 0; t < n*n; t++) {
        if (sudoku[t][i] == k) {
            return true;
        }
    }
    return false;
}

bool searchInColumn(int n, int sudoku[][100]){
    
    for(int i = 0; i < n*n; i++) {
        for(int k = 1; k <= n*n; k++) {
            if(!searchNumberInColumn(i, k, n, sudoku)) {
                return false;
            }
        }
    }
    return true;
}

bool searchNumberInSquare(int i, int k, int n, int number, int sudoku[][100] ) {

    for (int t = i; t < n + i; t++) {
       for (int h = k; h < n + k; h++) {

            if (sudoku[t][h] == number) {
                return true;
            } 
       }
    }
    return false;
}

bool searchInSquare(int n, int sudoku[][100]){
    
    for(int i = 0; i < n*n; i+=n) {
     
        for(int k = 0; k < n*n; k+=n){
            for( int number = 1; number <= n*n; number++){
                if(!searchNumberInSquare(i, k, n, number, sudoku)){
                return false;
                }
            }
           
        }
    }
    return true;
}

void checkSudoku(int n, int sudoku[][100]){

    if (searchInColumn(n, sudoku) && searchInRows(n, sudoku) && searchInSquare(n, sudoku)) {
         printf("CORRECT");
    } else {
         printf("INCORRECT");
    }
}

int main(void) {
   
    int n = initN(n);
    
    int sudoku[100][100];
    initSudoku(n, sudoku);
    checkSudoku(n, sudoku);
}