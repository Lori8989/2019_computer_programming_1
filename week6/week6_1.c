#include<stdlib.h>
#include<stdio.h>

int main(){
    char t = '0';
    while((t = getchar()) != EOF){
        putchar(t);
    }

    return 0;
}