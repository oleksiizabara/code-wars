#include <stdio.h>
#include <stdbool.h>

bool f(int a) {
    int b = 1; 
    while (b <= 1024) {
        if (b == a) {
            return true;
            break;
             
        }
        b*=2;
    }
    return false;
}

int checkNumber (int a) {
    if (a == 1) {
        
        return a;
    } else if (f(a)) {
      
        return a/2;
    } else if (!f(a) && a%2 ==0){
       
        return a-1;
    } else {
  
        return a;
    }
}

int main(void) {
    int numbersOfGuests, a;
    printf("enter number of guests: ");
    scanf("%i", &numbersOfGuests);

    a = checkNumber(numbersOfGuests);
    printf("%i", a);
}