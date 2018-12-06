#include <stdio.h>

void init(int arr[3]) {
    for (int i = 0; i < 3; i++) {
        scanf("%i", &arr[i]);
    }
}

void sort(int arr[3]) {

    int timeVar = 0;
    for (int n = 0; n < 3; n++) {
        for(int m = 2; m >= 1; m--){
            if(arr[m] > arr[m-1]) {
                timeVar = arr[m];
                arr[m] = arr[m-1];
                arr[m-1] = timeVar;
            }
        }
    }
} 

void depozit(int prise[3], int massa[3]) {
    int sum = 0, n = 3;
    for (int i = 0; i < 3; i ++) {
        sum += prise[i]*massa[i];
    }
    printf("%i", sum);
}

int main(void) {
    int prise[3], massa[3];

    printf("enter prise: \n");
    init(prise);

    printf("enter massa: \n");
    init(massa);

    sort(prise);
    sort(massa);

    depozit(prise, massa);
}