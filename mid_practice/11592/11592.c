#include<stdio.h>
#include<stdlib.h>

int countFBs(int input){
    int remain = input;
    int getFBs = input;
    while(remain > 2){
        getFBs += remain / 3;
        remain = (remain / 3) + (remain % 3);
    }

    return getFBs;
}

int main(){
    int target = 0;
    scanf("%d", &target);

    for(int i = target; i >= 0; i--){
        // printf("%d: %d\n", i, countFBs(i));
        if(countFBs(i) < target){
            printf("%d\n", i + 1);
            break;
        }
    }

    return 0;
}