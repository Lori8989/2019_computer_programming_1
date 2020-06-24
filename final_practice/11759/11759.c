// NTHUOJ 11759 - B - Great Depression Again   
// Description
// Writer: jjjjj19980806       Description: pclightyear        Difficulty: ★★★★★
// As you all know, Kim Jong-un is the Chairman of the Workers' Party of Korea and supreme leader of North Korea. Recently, more and more countries and international bodies have been imposing economic sanctions against North Korea. The import of the raw material of all kind decreases dramatically, and the automobile industry in North Korea is suffering from severe depression again. Reorganization of the whole industry is needed to make North Korea GREAT AGAIN.
// According to the survey, there are n factory in North Korea. Each of them can produce two kinds of cars (car A & car B). Now, the supreme leader wants to assign x factory to produce car A and y factory to produce car B (i.e. no factory will produce two kinds of car at the same time.) so that the net profit will become maximum. However, due to the shortage of the raw material, it is possible that some factory will not produce any cars (i.e. x + y <= n).
// The supreme leader will give you the net profit each factory can make by producing car A and car B. Your program need to output the name of the x factory which produce car A in lexicographical order. If there are multiple answers, you need to output the one such that the total net profit of car A is maximum. 
// DO NOT DISAPPOINT HIM!!

// Input
// The first line contains three integers n, x, y, representing the total number of factory, the number of factory planned to produce car A, and the number of factory planned to produce car B. (according to the supreme leader's demand)
// The next n lines contains one string si and two integers ai, bi, representing the name of each factory, and the net profit each factory can make by producing only car A or only car B.
// It is guaranteed that :
// 0 < n, x, y ≤ 500
// x + y <= n
// 1 ≤ | si | ≤  20
// 0 < ai, bi < 106
// ai ≠ aj, bi ≠ bj  if i ≠ j.
// No duplicate names appears.

// Output
// Please output the list of x factory that need to produce car A in lexicographical order so that it will maximum the net profit.

// Sample Input  
// 10 3 4
// TOYOTA 10 100
// GM 20 90
// FORD 30 80
// Volkswagen 40 70
// Daimler 50 60
// Honda 60 50
// Nissan 70 40
// PEUGEOT 80 30
// FIAT 90 20
// BMW 100 10

// Sample Output  
// BMW
// FIAT
// PEUGEOT

// 2020/06/23 SYC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NameLen 25

typedef struct item{
    int idx;
    char name[NameLen];
    char p;
    int val;
}Item;

int cmp(const Item *a, const Item *b){
    if(b->val > a->val){
        return 1;
    }else if(b->val < a->val){
        return 0;
    }else{
        if(b->p == 0){return 1;}
    }
    return 0;
}

int lexicalCmp(const Item *a, const Item *b){
    if(strcmp(a->name, b->name) >= 0){
        return 1;
    }
    return 0;
}

int main(){
    int n = 0, x = 0, y = 0;
    scanf("%d %d %d\n", &n, &x, &y);
    // printf("N: %d X: %d Y: %d\n", n, x, y);
    Item *order = (Item *)malloc(sizeof(Item) * n * 2);
    
    int *record = (int *)malloc(sizeof(int) * n);
    Item *xSeq = (Item *)malloc(sizeof(Item) * x);
    Item *ySeq = (Item *)malloc(sizeof(Item) * y);
    int aCount = 0, bCount = 0;
    memset((Item *)order, sizeof(Item) * n * 2, 0);
    memset((void *)record, sizeof(int) * n, 0);
    memset((void *)xSeq, sizeof(Item) * x, 0);
    memset((void *)ySeq, sizeof(Item) * y, 0);

    // Put all Factories into same array and seperate the net profit of product a and b
    for(int i = 0; i < n; i++){
        char tempName[NameLen] = {0};
        int tempA = 0, tempB = 0;
        scanf("%s %d %d\n", tempName, &(tempA), &(tempB));
        // Record Value a
        order[2 * i].idx = i;
        strncpy(order[2 * i].name, tempName, NameLen);
        order[2 * i].p = 0;
        order[2 * i].val = tempA;

        // Record Value b
        order[2 * i + 1].idx = i;
        strncpy(order[2 * i + 1].name, tempName, NameLen);
        order[2 * i + 1].p = 1;
        order[2 * i + 1].val = tempB;
    }
    // Sort with the net profit in decreasing order, combine product a and b
    qsort(order, 2 * n, sizeof(Item), (int (*)(const void *, const void *))cmp);
    
    for(int i = 0; i < 2 * n; i++){
        int factIdx = order[i].idx;
        // If the factory is picked before, skip this round and continue
        if(record[factIdx]){continue;}
        // Always pick larger profit
        if(order[i].p == 0 && aCount < x){
            xSeq[aCount].idx = factIdx;
            strncpy(xSeq[aCount].name, order[i].name, NameLen);
            xSeq[aCount].p = 0;
            xSeq[aCount].val = order[i].val;

            record[factIdx] = 1;
            aCount++;
        }else if(order[i].p == 1 && bCount < y){
            ySeq[bCount].idx = factIdx;
            strncpy(ySeq[aCount].name, order[i].name, NameLen);
            ySeq[bCount].p = 1;
            ySeq[bCount].val = order[i].val;

            record[factIdx] = 1;
            bCount++;
        }
    }
    // Sort in lexical order
    qsort(xSeq, x, sizeof(Item), (int (*)(const void *, const void *))lexicalCmp);

    for(int i = 0; i < x; i++){
        printf("%s\n", xSeq[i].name);
    }


    return 0;
}