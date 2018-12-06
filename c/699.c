#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct mushroom {
    int x;
    int y;
    int radius;
};

struct rainyDay {
    int numberOfMushrooms;
    float rainTime;
};

struct rainyDay initRainyDay() {

    struct rainyDay strct;

    printf("enter mumber of mushrooms: ");
    scanf("%i", &strct.numberOfMushrooms);

    printf("enter rain time: ");
    scanf("%f", &strct.rainTime);

    return strct;
}

void initCoordsAndRadius(struct mushroom arrayOfMushrooms[10], int number) {

    for( int i = 0; i < number; i++){
        printf("enter X coord %i musroom: ", i+1);
        scanf("%i", &arrayOfMushrooms[i].x);

        printf("enter Y coord %i musroom: ", i+1);
        scanf("%i", &arrayOfMushrooms[i].y);

        printf("enter RADIUS %i musroom: ", i+1);
        scanf("%i", &arrayOfMushrooms[i].radius);
    }
}

float distance(struct mushroom  strct_I, struct mushroom  strct_K) {

    return sqrtf((strct_I.x - strct_K.x)*(strct_I.x - strct_K.x) + (strct_I.y - strct_K.y)*(strct_I.y - strct_K.y)) - strct_I.radius - strct_K.radius;
}

float findMinimalDistance(struct mushroom arrayOfMushrooms[10], int number) {

    float distanceBetween[number*(number - 1)];
    
    float minimalDistance;
    int index = 0;
    
    for(int i = 0; i < number; i++){
        for(int k = 0; k < number; k++){
            if(k != i){
                distanceBetween[index] = distance(arrayOfMushrooms[i], arrayOfMushrooms[k]);
                index++;
            }
        }
    }

    minimalDistance = distanceBetween[0];

    for(int i = 1; i < number*(number-1); i++) {
        if (minimalDistance > distanceBetween[i]) {
            minimalDistance = distanceBetween[i];
        }
    }

    return minimalDistance;
}

void howMuch(float minimalDistance, float rainTime) {
    
    if(minimalDistance/2 > rainTime) {
        printf("\n%.2f\n", rainTime);
    } else {
        printf("\n%.2f\n", minimalDistance/2);
    }
}

int main(void) {

    struct rainyDay rainyForestDay = initRainyDay();

    int numberOfMushrooms = rainyForestDay.numberOfMushrooms;
    float rainTime = rainyForestDay.rainTime;

    struct mushroom arrayOfMushrooms[10];

    initCoordsAndRadius(arrayOfMushrooms, numberOfMushrooms);

    float minimalDistance = findMinimalDistance(arrayOfMushrooms, numberOfMushrooms);

    howMuch(minimalDistance, rainTime);
}