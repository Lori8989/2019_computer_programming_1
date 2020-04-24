#include<stdio.h>
#include<stdlib.h>

int accum(long int *seq, int layer, int limit, long int sum, long int target, int *count){
    long int newSumAdded = seq[layer] + sum;
    // printf("%ld", seq[layer]);
    if(newSumAdded == target){
        (*count)++;
    }else if(layer <= limit){
        accum(seq, layer + 1, limit, newSumAdded, target, count);
    }
    if(layer <= limit){
        accum(seq, layer + 1, limit, sum, target, count);
    }
}

int main(){
    int n = 0, k = 0;
    long int seq[23] = {0};
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%ld", &(seq[i]));
        // printf("%ld", (seq[i]));
    }

    int *count = (int *)malloc(sizeof(int));
    accum(seq, 0, n, 0, k, count);
    printf("%d\n", (*count));

    return 0;
}
