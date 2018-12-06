#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void init(char formula[1000]) {
    printf("enter formula: ");
    scanf("%s", formula);
}

int findElements(char formula[1000], char elements[][3]) {

    int indexInElementsArray = 0;
    int len = strlen(formula);
    int lenElements = 0;

    for (int i = 0; i < len; i++) {

        if(formula[i] >= 'A' && formula[i] <= 'Z' && formula[i+1] >= 'a' && formula[i+1] <= 'z') {
           
            elements[indexInElementsArray][0] = formula[i];
            elements[indexInElementsArray][1] = formula[i+1];
            elements[indexInElementsArray][2] = '\0';

            indexInElementsArray++;
            i++;
            lenElements++;
        }

        if(formula[i] >= 'A' && formula[i] <= 'Z' && formula[i+1] <= 'a') {
            
            elements[indexInElementsArray][0] = formula[i];
            elements[indexInElementsArray][1] = '\0';

            indexInElementsArray++;
            lenElements++;
        }
    }

    return lenElements;   
}

bool checkFormula(char elements[][3], int len) {
    
    for(int i = 0; i < len; i++) {
        if(strcmp(elements[i], elements[i+1]) == 0) {
            
            return false;
        }
    }
    return true;
}

int main(void) {
    char formula[1000];

    init(formula);

    char elements[1000][3];

    int lenElements = findElements(formula, elements);

    if(checkFormula(elements, lenElements)) {
        printf("YES");
    } else {
        printf("NO");
    }
}