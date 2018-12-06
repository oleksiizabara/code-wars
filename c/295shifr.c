#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define ZinASCII    90
#define ABClen      25

 
struct elemen {
    int q;
    int index;
};

void init( char shifr[40], char word[40]) {
    printf("enter shifr: ");
    scanf("%s", shifr);

    printf("enter word: ");
    scanf("%s", word);
}

struct elemen findQ(char shifr[40], char word[40], struct elemen elem) {

    int lenShifr = strlen(shifr);
    int lenWord = strlen(word);

    for(int i = 0; i < lenShifr - 1; i++) {
        if (shifr[i] - word[0] == shifr[i+1] - word[1]) {
            elem.index = i;
            elem.q = shifr[i] - word[0];
        
            break;
        }
    }

    return elem;
}

bool checkShifr(char shifr[40], char word[40], struct elemen elem) {

    int lenWord = strlen(word);
    
    int index = elem.index;
    int q = elem.q;

    for (int i = 0; i < lenWord; i++) {
        if(shifr[index + i] - q != word[i]) {

            return false;
        }
    }
    return true;
}

void recoding(char shifr[40], struct elemen elem) {

    int len = strlen(shifr);
    int q = elem.q;

    for (int i = 0; i < len; i++) {
        shifr[i] = shifr[i] - q;
        if( shifr[i] > ZinASCII) {
            shifr[i] -= ABClen;
        }
        printf("%c", shifr[i]);
    }
}

int main(void) {

   struct elemen elem;

   char shifr[40];
   char word[40];

   init(shifr, word);

   elem = findQ(shifr, word, elem);

   if(!checkShifr(shifr, word, elem)) {
       printf("IMPOSSIBLE");
   } else 
       recoding(shifr, elem);
}