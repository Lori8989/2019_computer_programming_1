// NTHUOJ 11763 - F - Bipartite Graph   
// Description
// Writer: jjjjj19980806       Description: pclightyear        Difficulty: ★★★★☆
// Given an undirected graph G, you have to check whether it is a bipartite graph (二分圖) or not.

// Input
// The first line contains an integer T, representing the number of test cases.
// For each test case:
// The first line contains two integers n, m, representing the number of vertices and the number of edges.
// The next m lines contain two integers u, v, representing that there is an undirected edge between vertex u and vertex v.
// It is guaranteed that:
// 1 ≤ T ≤ 10
// 2 ≤ n ≤ 1000
// n-1 ≤ m ≤ n2
// 1 ≤ u, v ≤ 1000
// NO multiple edge
// NO self cycle
// the graph is connected
 

// Output
// For each graph G, if G is a bipartite graph, please output "Yes", otherwise please output "No".

// Sample Input  
// 3

// 2 1
// 1 2

// 4 4
// 1 2
// 2 3
// 3 4
// 4 1

// 3 3
// 1 2
// 1 3
// 2 3

// Sample Output  
// Yes
// Yes
// No

#include<stdio.h>
#include<stdlib.h>
#define Red 1
#define Blue 2
#define Unlabel 0

void **malloc2d(const int unitSize, const int rows, const int cols){
    void **mat = (void **)malloc(sizeof(void*) * rows);
    for(int i = 0; i < rows; i++){
        mat[i] = (void *)malloc(unitSize * cols);
        memset(mat[i], 0, cols);
    }
    return mat;
}

void free2d(void **mat ,const int rows){
    for(int i = 0; i < rows; i++){
        free(mat[i]);
    }
}

int solve(int **graph, const int n){
    // Color: Red, Blue
    int current = 0;
    int *record = (int *)malloc(sizeof(int) * n);

    memset(record, 0, n);
    record[current] = 1;
    while(){
        int neighborNumber = 0;
        int *buff = (int *)malloc(sizeof(int) * n);
        memset(buff, 0, n);

        for(int neighbor = 0; neighbor < n; neighbor++){
            if(graph[current][neighbor]){
                buff[neighborNumber] = neighbor;
                neighborNumber++;
            }
        }
    }
}

int main(){
    int T = 0;
    scanf("%d\n", &T);
    for(int i = 0; i < T; i++){
        // Read number of Vertice(n) and number of Edges(m)
        int n = 0, m = 0;
        scnaf("%d %d\n", &n, &m);
        int **graph = (int **)malloc2d(sizeof(int), n, n);

        // Read Edges
        for(int j = 0; j < m; j++){
            int a = 0, b = 0;
            scanf("%d %d\n", &a, &b);
            graph[a][b] = graph[b][a] = 1;
        }

        free2d((void **)graph, n);
    }


    return 0;
}