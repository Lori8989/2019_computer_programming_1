#include <stdio.h>
#include <stdlib.h>
#define MaxCoffees 200010

int binSearch(long int *coffees, const int start, const int end, const long int m){
    int startI = start, endI = end;
    int midI = (start + end) / 2;

    while(startI < endI){
        if(coffees[midI] < m){
            endI = midI;
        }else{
            startI = midI + 1;
        }
        midI = (startI + endI) / 2;
    }

    return midI;
}

int solve(long int *coffees, long int *prefixSum, const int n, const long int m){
    for(int d = 1; d <= n; d++){
        // 
        int maxRound = n / d;
        for(int r = 1; r < maxRound; r++){

        }
    }
}

int main(){
    int t = 0;
    scanf("%d\n", &t);

    for(int i = 0; i < t; i++){
        // n: Number of coffees, m: Traget of codes
        int n = 0;
        long int m = 0;
        long int coffees[MaxCoffees] = {0}, prefixSum[MaxCoffees] = {0};
        scanf("%d %ld\n", &n, &m);

        scanf("%ld", &(coffees[0]));
        prefixSum[0] = coffees[0];
        for(int j = 1; j < n; j++){
            scanf("%ld", &(coffees[j]));
            prefixSum[j] = prefixSum[j - 1] + coffees[j];
        }

        solve(coffees, prefixSum, n, m);
    }

    return 0;
}