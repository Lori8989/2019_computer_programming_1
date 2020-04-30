#include<stdio.h>
#include<stdlib.h>

int gcd(int m, int n){
    int t = 1;
    while(t != 0){
        t = m % n;
        m = n;
        n = t;
    }

    return m;
}

int main(){
    int n = 0;
    int max = 0;
    int array[1005] = {0};
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++){
        int t = 0;
        scanf("%d", &t);
        array[i] = t;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                int gcdRes = gcd(array[i], array[j]);
                if(max < gcdRes){
                    max = gcdRes;
                }
            }
        }
    }
    // printf("%d\n", gcd(12, 1024));
    printf("%d\n", max);

    return 0;
}