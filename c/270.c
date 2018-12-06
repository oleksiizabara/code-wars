#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void initName(char name[100]) {
   
    printf("enter var name: ");
    gets(name);
}

bool findCpp(char name[100]) {

    int len = strlen(name);
    for(int i = 0; i < len; i++) {
        if(name[i] == '_') {
            return true;
        }
    }
    return false;
}

bool findJava(char name[100]) {

    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

void makeJava(char name[100]) {

    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if(name[i] == '_') {
            printf("%c", toupper(name[i+1]));
            i++;
        } else {
            printf("%c", name[i]);
        }
    }
}

void makeCpp(char name[100]) {

    int len = strlen(name);
    for(int i = 0; i < len; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            printf("_");
            printf("%c", tolower(name[i]));
        } else {
            printf("%c", name[i]);
        }
    }
}

void justPrint(char name[100]) {
    
   printf("%s", name);
}

void convertName(char name[100]) {

     if (findCpp(name)) {
    
        if(!findJava(name)){
            makeJava(name);
        } else {
            printf("Error!");
        }
    } else if(findJava(name)) {
  
        if (!findCpp(name)) {
            printf("okJava\n");
            makeCpp(name);
        } else {
            printf("Error!");
        }
    } else {
     
        justPrint(name);
    }
}

int main(void) {

    char name[100];
    initName(name);
    convertName(name);
   
}