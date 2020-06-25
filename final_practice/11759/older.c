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

int aMinusBCmp(const Fact *a, const Fact *b){
    return b->aMinusB > a->aMinusB;
}

int aCmp(const Fact *a, const Fact *b){
    return b->a > a->a;
}

int lexicalCmp(const Fact *a, const Fact *b){
    if(strcmp(a->name, b->name) >= 0){
        return 1;
    }
    return 0;
}

int main(){
    int n = 0, x = 0, y = 0, xSeqLen = 0;
    scanf("%d %d %d\n", &n, &x, &y);
    xSeqLen = n - y > n - x? n - y : n - x;
    // printf("N: %d X: %d Y: %d\n", n, x, y);
    Fact *facts = (Fact *)malloc(sizeof(Fact) * n);
    Fact *xSeq = (Fact *)malloc(sizeof(Fact) * xSeqLen);
    Fact *res = (Fact *)malloc(sizeof(Fact) * x);
    memset((void *)facts, sizeof(Fact) * n, 0);
    memset((void *)xSeq, sizeof(Fact) * xSeqLen, 0);
    memset((void *)res, sizeof(Fact) * x, 0);

    for(int i = 0; i < n; i++){
        scanf("%s %d %d\n", facts[i].name, &(facts[i].a), &(facts[i].b));
        facts[i].aMinusB = facts[i].a - facts[i].b;
    }

    // Sort with the value a - b in decreasing order
    qsort(facts, n, sizeof(Fact), (int (*)(const void *, const void *))aMinusBCmp);
    for(int i = 0; i < xSeqLen; i++){
        xSeq[i] = facts[i];
        // printf("%d ", xSeq[i].aMinusB);
    }
    // printf("\n");

    // Sort with the value a in decreasing order
    qsort(xSeq, xSeqLen, sizeof(Fact), (int (*)(const void *, const void *))aCmp);
    for(int i = 0; i < x; i++){
        res[i] = xSeq[i];
        // printf("%d ", res[i].a);
    }
    // printf("\n");
    
    // Sort in lexical order
    qsort(res, x, sizeof(Fact), (int (*)(const void *, const void *))lexicalCmp);
    for(int i = 0; i < x; i++){
        printf("%s\n", res[i].name);
    }


    return 0;
}