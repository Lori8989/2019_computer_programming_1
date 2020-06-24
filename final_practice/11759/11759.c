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

typedef struct Fact{
    char name[NameLen];
    int a;
    int b;
    int aMinusB;
}Fact;

typedef struct item{
    int idx;
    int val;
}Item;

int aMinusBCmp(const Fact *a, const Fact *b){
    return b->aMinusB > a->aMinusB;
}

int aCmp(const Item *a, const Item *b){
    return b->val < a->val;
}

int lexicalCmp(const Fact *a, const Fact *b){
    if(strcmp(a->name, b->name) >= 0){
        return 1;
    }
    return 0;
}

int main(){
    int n = 0, x = 0, y = 0, ySeqLen = 0;
    scanf("%d %d %d\n", &n, &x, &y);
    ySeqLen = n - y;
    // printf("N: %d X: %d Y: %d\n", n, x, y);
    Fact *facts = (Fact *)malloc(sizeof(Fact) * n);
    // Fact *ySeq = (Fact *)malloc(sizeof(Fact) * ySeqLen);
    Item *assemble = (Item *)malloc(sizeof(Item) * n);
    int *record = (int *)malloc(sizeof(int) * n);
    Fact *res = (Fact *)malloc(sizeof(Fact) * x);
    memset((void *)facts, sizeof(Fact) * n, 0);
    // memset((void *)ySeq, sizeof(Fact) * ySeqLen, 0);
    memset((void *)assemble, sizeof(Item) * n, 0);
    memset((void *)record, sizeof(int) * n, 0);
    memset((void *)res, sizeof(Fact) * x, 0);

    for(int i = 0; i < n; i++){
        scanf("%s %d %d\n", facts[i].name, &(facts[i].a), &(facts[i].b));
        facts[i].aMinusB = facts[i].a - facts[i].b;
    }

    // Sort with the value a - b in decreasing order
    qsort(facts, n, sizeof(Fact), (int (*)(const void *, const void *))aMinusBCmp);
    for(int i = 0; i < n; i++){
        assemble[i].idx = i;
        if(i < x){
            assemble[i].val = facts[i].a;
        }else{
            assemble[i].val = facts[i].b;
        }
        // printf("%d ", ySeq[i].aMinusB);
    }

    // printf("\n");

    // Sort with the value a in increasing order
    qsort(assemble, n, sizeof(Item), (int (*)(const void *, const void *))aCmp);
    for(int i = 0; i < n - x - y; i++){
        record[assemble[i].idx] = 1;
        // printf("%d ", res[i].a);
    }
    int count = 0;
    for(int i = 0; i < n && count < x; i++){
        if(!record[i]){
            strncpy(res[count].name, facts[i].name, NameLen);
            count++;
        }
    }
    // printf("\n");
    
    // Sort in lexical order
    qsort(res, x, sizeof(Fact), (int (*)(const void *, const void *))lexicalCmp);
    for(int i = 0; i < x; i++){
        printf("%s\n", res[i].name);
    }


    return 0;
}