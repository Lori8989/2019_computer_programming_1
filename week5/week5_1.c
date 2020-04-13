// NTHUOJ 12138 - too many treasures   
// SYC
// 2020 / 4 / 13

#include<stdlib.h>
#include<stdio.h>

int main(){
    long int n = 0;
    long int q = 0;

    long int prefixSum[1000005] = {0};

    scanf("%ld", &n);
    scanf("%ld", &q);

    long int accSum = 0;
    // prefixSum[0] = 0;
    for(long int i = 1; i <= n; i++){
        long int temp = 0;
        scanf("%ld", &temp);
        if(temp > 0){
            accSum += temp;
            prefixSum[i] = accSum;
        }else{
            accSum += 0;
            prefixSum[i] = accSum;
        }
        // printf("%ld ", prefixSum[i]);
    }

    // printf("\n");

    for(long int i = 0; i < q; i++){
        long int a = 0;
        long int b = 0;
        long int c = 0;

        scanf("%ld", &a);
        scanf("%ld", &b);
        scanf("%ld", &c);

        // long int idxA = a - 1;
        // long int idxB = b - 1;

        // printf("%ld %ld %ld %ld %ld\n", a, b, c, a + c - 1, a - 1);
        // printf(" %ld\n", );
        printf("%ld\n", prefixSum[a + c - 1] - prefixSum[a - 1]);
    }

    return 0;
}