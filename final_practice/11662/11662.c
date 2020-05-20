// NTHUOJ 11662 - Fill containers with water   
// Description
// Suppose that you have an infinite number of containers with different sizes, already filled with water. Given another empty container with size N liters, you need to find the best way to fill this N-liter empty container using the provided smaller containers. By ‘best’, we mean that the total number of used containers should be as small as possible. For example, assume that we have containers in 1, 5, and 10 liters. To get the 17 liters of water, we need 2 containers of 1 liter, 1 container of 5 liters, and 1 container of 10 liters. Another example: assume that we have containers in 1, 5, 10 and 50 liters. To get the 57 liters of water, we need 1 container of 50 liters, 1 container of 5 liters, and 2 containers of 1 liter. Note that, to avoid water wastage, if you choose to use a container, all the water in this container should be poured.
// The following is an excerpt of incomplete code:
// #include <stdio.h>
// #define MAXNV 5
// int DONE = 0;
// int liters[MAXNV];
// int numbers[MAXNV];
// void show(int nv);
// void filling(int amount, int cur, int nv);
// int j=0;
// int water;
// int min=100;
// int min_numbers[MAXNV]={0};
// int main(void)
// {
//     int nv, i;

//     scanf("%d", &nv);
//     for (i=0; i<nv; i++) {
//         scanf("%d", &liters[i]);
//     }
//     scanf("%d", &water);
//     filling(water, 0, nv);

//     for(i=0;i<nv;i++)
//         numbers[i]=min_numbers[i];
//     show(nv);
//     return 0;
// }

// void show(int nv)
// {
//     int i;
//     printf("(%d", numbers[0]);
//     for (i=1; i<nv; i++) {
//         printf(",%d", numbers[i]);
//     }
//     printf(")\n");
// }

// void filling(int amount, int cur, int nv)
// {
//     /* your code */
// }

// Input
// The input contains three lines.
// The first line contains an integer N, indicating that how many containers you have.
// The second line gives you each container's size.
// The last line is the total amount of water you have to pour.

// Output
// The result can be displayed by calling the function show().
// Only the best way to fill the empty container should be displayed.

// Sample Input  
// 4
// 50 10 5 1
// 57

// Sample Output  
// (1,0,1,2)
 
// 2020/05/19 SYC

#include<stdlib.h>
#include<stdio.h>

typedef struct container{
    int size;
    int used_times;
}Container;

void showCon(Container *con_arr, int N){
    printf("\nSize: ");
    for(int i = 0; i < N; i++){
        printf("%d\t", con_arr[i].size);
    }

    printf("\nUsed: ");
    for(int i = 0; i < N; i++){
        printf(" %d\t", con_arr[i].used_times);
    }
    printf("\n=======================================\n");
}

void sort_con(Container *con_arr, int n){
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(con_arr[i].size > con_arr[j].size){
                // swap i, j
                Container temp = con_arr[i];
                con_arr[i] = con_arr[j];
                con_arr[j] = temp;
            }else{
                break;
            }
        }
    }
}

int fill(Container *con_arr, int target, int layer, int con_num){
    if(target == 0){
        return 1;
    }else if(target < 0 || layer >= con_num){
        return 0;
    }

    int max = target / con_arr[layer].size;

    for(int i = max; i >= 0; i--){
        con_arr[layer].used_times = i;
        // showCon(con_arr, con_num);
        if(fill(con_arr, target - (i * con_arr[layer].size), layer + 1, con_num)){
            return 1;
        }
    }
    
    return 0;
}

int main(){
    int N = 0;
    scanf("%d", &N);

    Container *con_arr = (Container *)malloc(sizeof(Container) * N);

    for(int i = 0; i < N; i++){
        scanf("%d", &(con_arr[i].size));
        con_arr[i].used_times = 0;
    }

    int target = 0;
    scanf("%d", &target);
    
    sort_con(con_arr, N);
    fill(con_arr, target, 0, N);

    printf("(");
    for(int i = 0; i < N - 1; i++){
        printf("%d,", con_arr[i].used_times);
    }
    printf("%d)\n", con_arr[N - 1].used_times);

    return 0;
}