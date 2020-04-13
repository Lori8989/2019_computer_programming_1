#include<stdio.h>
#include<stdlib.h>

long long int prefix_current_idx = 0;
long long int prefix_current_sum = 0;
long long int *prefix_sum = NULL;

long long int push_prefix(long long int input){
    if(prefix_sum == NULL){
        // printf("prefix_sum is NULL\n");
        return 0;
    }else{
        prefix_sum[prefix_current_idx] = input + prefix_current_sum;
        prefix_current_sum += input;
        prefix_current_idx++;
        return 1;
    }

}

long long int get_sum(long long int a, long long int b){
    long long int idx_a = a - 2;
    long long int idx_b = b - 1;
    if(prefix_sum != NULL){
        if(idx_a < 0){
            return prefix_sum[idx_b];
        }else{
            return prefix_sum[idx_b] - prefix_sum[idx_a];
        }
    }else{
        // printf("prefix_sum is NULL\n");
        return 0;
    }
}

long long int main(){
    long long int n = 0;
    long long int q = 0;

    scanf("%lld %lld", &n, &q);
    prefix_sum = (long long int *)malloc(sizeof(long long int) * n);

    for(long long int i = 0; i < n; i++){
        
        long long int input = 0;
        scanf("%lld(/`A`)/ ~I__I", &input);
        // if(i % 2 == 0){    
            
            // long long int k = 0;
            // char integer[1000];
            
            // while(input[k] != '('){
            //     integer[k] = input[k];
            //     k++;
            // }
            // push_prefix(atoi(integer));
            // printf("%lld\n", input);
            push_prefix(input);
            
        // }
    }

    for(long long int i = 0; i < q; i++){
        long long int qa = 0;
        long long int qb = 0;
        scanf("%lld %lld", &qa, &qb);
        printf("%lld\n", get_sum(qa, qb));
    }


    return 0;
}