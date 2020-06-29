// Another AC Version
#include<stdlib.h>
#include<stdio.h>

#define MaxLen 1000005

int binSearch(long long int *seq, const int start, const int end, const long long int target){
    int startI = start;
    int endI = end;
    int midI = (startI + endI) / 2;
    // You need to ensure that the potential answer is in the picked section
    while(endI - startI > 0){
        if(target <= seq[midI]){
            endI = midI;
        }else{
            startI = midI + 1;
        }
        midI = (startI + endI) / 2;
    }

    return midI;
}

int main(){
    long long int n = 0, k = 0, q = 0;
    long long int seq[MaxLen] = {0};

    scanf("%lld %lld %lld\n", &n, &k, &q);
    for(long long int i = 0; i < n; i++){
        scanf("%lld", &(seq[i]));
    }

    for(long long int i = 0; i < q; i++){
        long long int f = 0;
        
        scanf("%lld", &f);

        if(seq[n - 1] < f){
            printf("gan ni nya sai bau\n");
        }else{
            int resIdxLeft = binSearch(seq, 0, k - 1, f);
            int resIdxRight = binSearch(seq, k, n - 1, f);
            int ans = 0;

            // Conditions:
            // 1. ai >= f
            // 2. |ai - f| is smallest
            // 3. ai has smallest index after shift

            if(seq[resIdxRight] >= f && seq[resIdxLeft] >= f){
                if((seq[resIdxLeft] - f) < (seq[resIdxRight] - f)){
                    ans = resIdxLeft + 1 + (n - k);
                }else{
                    ans = resIdxRight - k + 1;
                }
            }else{
                ans = resIdxRight - k + 1;
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}