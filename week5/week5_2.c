// NTHUOJ 12674 - Eat candies
// SYC
// 2020 / 4 / 13

#include<stdlib.h>
#include<stdio.h>

int *triSort(int a, int b, int c){
    int *re = (int *)malloc(sizeof(int) * 3);

    if(a >= b){
        if(b >= c){
            re[0] = a;
            re[1] = b;
            re[2] = c;
            return re;
        }else{
            if(a >= c){
                // re = {a, c, b};
                re[0] = a;
                re[1] = c;
                re[2] = b;
                return re;
            }else{
                // int re[3] = {c, a, b};
                re[0] = c;
                re[1] = a;
                re[2] = b;
                return re;
            }
        }
    }else{
        if(a >= c){
            // int re[3] = {b, a, c};
            re[0] = b;
            re[1] = a;
            re[2] = c;
            return re;
        }else{
            if(b >= c){
                // int re[3] = {b, c, a};
                re[0] = b;
                re[1] = c;
                re[2] = a;
                return re;
            }else{
                // int re[3] = {c, b, a};
                re[0] = c;
                re[1] = b;
                re[2] = a;
                return re;
            }
        }
    }
}

int main(){
    int max = 0;
    int min = 0;
    int middle = 0;

    int n = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a = 0;
        int b = 0;
        int c = 0;

        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);

        int *sorted = triSort(a, b, c);

        max = sorted[0];
        middle = sorted[1];
        min = sorted[2];

        if(middle + min >= max){
            printf("%d\n", (max + middle + min) / 2);
        }else{
            printf("%d\n", middle + min);
        }
    }

    return 0;
}