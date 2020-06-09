// NTHUOJ 12178 - Queens and Castles   
// Description
// Long long long long long long long long long long time ago, there's a lovely kingdom named "Chess". There's King, Queen, Knight, Castle, Bishop, ...etc. Just like the modern game "chess". 
// A king possessed one or more castles, and likewise a king could have two or more queens (same as queen, a queen is able to have two or more kings). Now in this kingdom, the king has N queens and M castles. All the castles are male, and of course, all the queens are female. 
// Moreover, the queen would eventually fall in love with castles, castles would eventually fall in love with queens, queens would eventually fall in love with other queens, castles would eventually fall in love with other castles.(This is a diversified world, BL or GL could happen.) Queens and castles concerned that if the king found betrayal by which giving a large green hat, they will not be forgiven. 
// Queens and castles assign a secret mission to you, the mightily programming knight. They'd like to figure out the possibilities that the king was unaware their relationship in the palace.
// There are N queens and M castles in the palace.
// The palace is just like a chessboard with size (N+M)*(N+M). 
// Queen can see all people in 8 directions(←, ↑, →, ↓, ↖, ↗, ↘, and ↙. Just like what queen in the chess does). If any queen see castles or other queens, the mission will fail. 
// Castle can see all people in 4 directions(←, ↑, →, and ↓. Just like what castle in the chess does). If any castle see queens or other castles, the mission will fail. 
// Find out the total amount of states that all queens and castles are placed in the palace and mission isn't fail.

// Input
// The input contains exactly two numbers N and M, each seperated by a space. 
// 1 <= N+M <= 9.

// Output
// Output only one number ── the total amount of states that queens and castles are placed in the palace and mission isn't fail.
// Remember to print a '\n' at the end of the output.

// Sample Input  
// 8 0

// Sample Output  
// 92

#include <stdio.h>
#include <stdlib.h>
#define MaxTableSize 10

void showTable(int chessNum, int (*table)[MaxTableSize]){
    printf("\n=====================================\n");
    for(int i = 0; i < chessNum; i++){
        for(int j = 0; j < chessNum; j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n=====================================\n");
}

int checkCol(const int idx, const int chessNum, int (*table)[MaxTableSize]){
    for(int i = 0; i < chessNum; i++){
        if(table[i][idx]){return 0;}
    }

    return 1;
}

int checkDia(const int row, const int col, const int chessNum, int (*table)[MaxTableSize]){
    int res = 0;

    // row++ && col++, bottom right direction
    for(int i = row + 1, j = col + 1; i < chessNum && j < chessNum; i++, j++){
        if(table[i][j] == 2){
            return 2;
        }else if(table[i][j] == 1){
            res = 1;
        }
    }

    // row-- && col--, upper left direction
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(table[i][j] == 2){
            return 2;
        }else if(table[i][j] == 1){
            res = 1;
        }
    }

    // row++ && col--, bottom left direction
    for(int i = row + 1, j = col - 1; i < chessNum && j >= 0; i++, j--){
        if(table[i][j] == 2){
            return 2;
        }else if(table[i][j] == 1){
            res = 1;
        }
    }

    // row-- && col++, upper right direction
    for(int i = row - 1, j = col + 1; i >= 0 && j < chessNum; i--, j++){
        if(table[i][j] == 2){
            return 2;
        }else if(table[i][j] == 1){
            res = 1;
        }
    }

    return res;
}

int search(const int n, const int m, const int chessNum, int (*table)[MaxTableSize], const int layer){
    // printf("n: %d m: %d chessNum: %d layer: %d", n, m, chessNum, layer);
    if(layer >= chessNum){
        // showTable(chessNum, table);
        return 1;
    }

    int count = 0;
    
    for(int i = 0; i < chessNum; i++){
        if((!table[layer][i]) && checkCol(i, chessNum, table)){
            // printf("Pass checkCol\n");
            int checkDiaRes = checkDia(layer, i, chessNum, table);
            table[layer][i] = 1;

            // Iterate Castles (m)
            if(m > 0 && checkDiaRes < 2){count += search(n, m - 1, chessNum, table, layer + 1);}
            
            // Iterate Queens (n)
            if(checkDiaRes == 0 && n > 0){
                // printf("Pass checkDia\n");
                table[layer][i] = 2;
                count += search(n - 1, m, chessNum, table, layer + 1);
            }
            table[layer][i] = 0;
        }
    }

    return count;
}

int main(){
    // n Queens, m Castles
    int n = 0, m = 0, count = 0;
    int table[MaxTableSize][MaxTableSize] = {0};

    scanf("%d %d\n", &n, &m);
    
    count = search(n, m, n + m, table, 0);

    printf("%d\n", count);

    return 0;
}