#include<stdio.h>

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    int sum = 0;
    scanf("%d %d %d", &a, &b, &c);
    sum = (a + b + c) / 2;
    printf("%d %d %d\n", sum - b, sum - c, sum - a);

    return 0;
}