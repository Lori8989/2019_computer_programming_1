// NTHUOJ 12678 - Count 1s   
// SYC
// 2020 / 4 / 13

#include<stdlib.h>
#include<stdio.h>

int main(){
    long int n = 0;

    long int prefixSum[1000002];
    long int count = 0;
    for(long int i = 1; i < 1000002; i++){
        
        char strInt[10];
        sprintf(strInt, "%ld", i);
        // printf("%s\n", strInt);
        // printf("%ld\n", sizeof(strInt));
        for(long int j = 0; j < 10; j++){
            // printf("%c", strInt[j]);
            if(strInt[j] == '1'){
                count++;
            }
        }

        prefixSum[i] = count;
    }

    scanf("%ld", &n);
    for(long int i = 0; i < n; i++){
        long int a = 0;
        long int b = 0;

        scanf("%ld", &a);
        scanf("%ld", &b);

        printf("%ld\n", prefixSum[b] - prefixSum[a-1]);
    }

    return 0;
}