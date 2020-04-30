#include<stdio.h>
#include<stdlib.h>

int countOccur(char *A, int sizeOfA, char *Bi, int sizeOfBi){
    int occurTimes = 0;

    for(int i = 0; i <= sizeOfBi - sizeOfA; i++){ // Inside Bi
        int isSame = 1;

        for(int j = 0; j < sizeOfA; j++){ // Inside A
            // printf("%c %c\n", A[j], Bi[i + j]);
            if(A[j] != Bi[i + j]){isSame = 0;}
        }

        if(isSame){occurTimes++;}
    }
    // printf("A: %d, B: %d, %d\n", sizeOfA, sizeOfBi, occurTimes);
    return occurTimes;
}

int main(){
    int n = 0;
    char A[6] = {0};
    int sizeOfA = 0;

    scanf("%s\n", A);
    scanf("%d\n", &n);
    while(A[sizeOfA] != '\0'){
        sizeOfA++;
    }

    int maxOccur = 0;
    for(int i = 0; i < n; i++){
        char Bi[15] = {0};
        int sizeOfBi = 0;
        scanf("%s\n", Bi);

        while(Bi[sizeOfBi] != '\0'){
            sizeOfBi++;
        }
        
        // printf("%s\n", Bi);

        int occurOfA = countOccur(A, sizeOfA, Bi, sizeOfBi);
        if(maxOccur < occurOfA){maxOccur = occurOfA;}
    }

    printf("%d", maxOccur);

    return 0;
}