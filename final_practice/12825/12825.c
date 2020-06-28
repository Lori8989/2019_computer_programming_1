// NTHUOJ 12825 - knuckle's name   
// Description
// Do you know de way?
// by uganda knuckles
// Knuckles are magical animals and I don't know how to descripe such non-sense
// google it yourself :) 
// Two string belongs to same group if :
// there exists a character that exist in both string.
// there exists a character in both string A and B,
// and there exists another character in both string B and C,
// then A, B, C belong to same group.
// Now, given n strings, you need to answer how many groups are there?
// A group can have members from 1 to n.

// Example:
// Given n=4
// strings are "a", "b", "ab", "d".
// "a" and "ab" and "b" belong to same group.
// "d" form a group by it self.
// Therefore there are 2 groups.

// Hint:
// Your first thought might be that if there exist a character in both string you can create an edge between both string .
// Then you can use DFS to find out how many connected components(連通塊) are in the graph.

// It's similar to 12155 - Cat-Toast Crisis .
// But in this problem, this way will cause TLE.
// You need to change the way you construct the graph, 
// you can't just easily connect two string, think another way (:

// Input
// First line contains only one integer t( 1<= t <= 30) which means the number of testcases.
// In each testcase:
// First line contains one integer n( 1 <= n <= 2000 ).
// And the following n lines, each line contains one string( 1 <= length of string <= 1000 )

 
// Output
// For each testcase output the number of groups.
// Remember to print '\n' at the end of each output.

 
// Sample Input  
// 3
// 4
// a
// b
// ab
// d
// 3
// ab
// bc
// abc
// 1
// htisgood

// Sample Output  
// 2
// 1
// 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StrSize 1005
#define RecordSize 250

typedef struct node{
    char str[StrSize];
    int label; // if = 0, no one visit before. If >= 1, represent the Label of the group belongs to.
    // char *record;
}Node;

void recordStr(Node *a, char *record){
    for(int k = 0; a->str[k] != '\0'; k++){
        record[a->str[k]] = 1;
    }
}

int isJoin(Node *a, char *record){
    for(int i = 0; a->str[i] != '\0' && i < StrSize; i++){
        if(record[a->str[i]]){
            return 1;
        }
    }
    return 0;
}

int dfs(Node *nodes, const int n, const int startIdx, char *record, const int label){
    if(nodes[startIdx].label) return 0;
    nodes[startIdx].label = label;
    recordStr(&(nodes[startIdx]), record);

    int nodeSum = 1;
    for(int i = 0; i < n; i++){
        if(nodes[i].label) continue;
        if(isJoin(&(nodes[i]), record)){
            nodeSum += dfs(nodes, n, i, record, label);
        }
    }

    return nodeSum;
}

int solve(Node *nodes, const int n){
    int labelCount = 0;
    char record[RecordSize] = {0};
    for(int i = 0; i < n; i++){
        if(!nodes[i].label){
            int dfsRes = 0;
            labelCount++;
            dfsRes = dfs(nodes, n, i, record, labelCount);
            memset(record, sizeof(char) * RecordSize, 0);
        }
    }
    printf("%d\n", labelCount);
}

int main(){
    int t = 0;
    scanf("%d\n", &t);

    for(int i = 0; i < t; i++){
        int n = 0;
        scanf("%d\n", &n);
        Node *nodes = (Node *)malloc(sizeof(Node) * n);
        memset(nodes, sizeof(Node) * n, 0);

        for(int j = 0; j < n; j++){
            scanf("%s\n", nodes[j].str);
        }

        solve(nodes, n);

    }

    return 0;
}