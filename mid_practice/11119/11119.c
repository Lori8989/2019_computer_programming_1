#include<stdio.h>
#include<stdlib.h>

int countCarry(int dec, int carry){
    int count = 0;
    if(dec > 1){
        count = countCarry(dec >> 1, dec & carry);
    }
    // printf("%d", (dec ^ carry) & 1);
    return count + (dec & carry);
}

void bin(int dec){
    if(dec > 1){
        bin(dec >> 1);
    }
    printf("%d", dec & 1);
}

int main(){
    int input = 0;
    int carryTimes = 0;
    scanf("%d", &input);

    bin(input + 1);
    carryTimes = countCarry(input, 1);
    printf(" %d", carryTimes);

    return 0;
}