#include<stdio.h>
#include<stdlib.h>

int main(){
    long int t = 0;
    long long int mod = 1000000007;

    scanf("%ld\n", &t);
    // printf("%ld\n", t);
    for(long int i = 0; i < t; i++){
        long int x = 0;
        long int strLen = 0;
        long long int storedStrLen = 0;
        char tempC;
        char str[1000005] = {0};

        scanf("%ld\n", &x);
        while((tempC = getchar()) != EOF){
            if(tempC == '\n') break;

            str[strLen] = tempC;
            // printf("%c", str[strLen]);
            strLen++;
            storedStrLen++;
        }
        // printf("\nStrLen: %ld\n", strLen);

        long long int lenCount = strLen;
        for(long int j = 0; j < x; j++){
            char copyTimesChar = str[j];
            int copyTimes = atoi(&copyTimesChar);
            long long int copiedStrLen = (lenCount - j - 1) % mod;
            // printf("%ldth Copy\n", j + 1);
            // printf("CopyTimes: %d\n", copyTimes);

            // Update Stored String
            int escFlag = 0;
            long long int copyStrStart = j + 1;
            for(int h = 0; h < copyTimes - 1; h++){
                // printf("Copy Recursive%d\n", h + 1);
                for(long long int k = 0; k < copiedStrLen; k++){
                    if(storedStrLen < x){
                        // printf("storedStrLen: %lld < x: %ld\n", storedStrLen, x);
                        str[storedStrLen] = str[copyStrStart + k];
                        storedStrLen++;
                        // printf("UPDATED storedStrLen: %lld < x: %ld\n", storedStrLen, x);
                    }else{
                        escFlag = 1;
                        break;
                    }
                }
                if(escFlag){break;}
            }

            // Update the counter
            lenCount += (copiedStrLen * (copyTimes - 1)) % mod;
            // printf("Add Len: %lld * (%d - 1) =  %lld -> %lld\n", copiedStrLen, copyTimes, copiedStrLen * (copyTimes - 1), lenCount);
            // lenCount = lenCount % (1000000007);
            // printf("Moded LenCount: %lld\n", lenCount);
            // printf("----------------------------------------------------------------------------------\n");
        }

        printf("%lld\n", lenCount % mod);
        // printf("======================================================================================\n");
    }

    return 0;
}