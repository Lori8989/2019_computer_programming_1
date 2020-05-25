// NTHUOJ 12797 - Unlimited Triangle Work   
// Description
// Recently, Gilgamesh found that he's almost lack of swords in his vault, so he wants to forge a lot of swords with different shapes. He command you to forge for him!
// Gilgamesh's sword can only be forged by triangle. Different triangle can be forged into a unique sword. He will give you the intervals of the edges of triangles, you have to calculate how many swords with different shape can he get?
// king
// Gilgamesh threats you with his "Gate of Babylon".
// You are given four positive integer , you're going to count how many triangle that can be build by edges with length , where .
// For example: 
// You can build triangles with edges : .
// So the answer is 4.

// Input
// The first line contains one integer , there are  testcases below.
// For each testcase, the four integer  is given respectively.
// .
// .

// Output
// For each testcase, output its answer, followed by a newline character.

// Sample Input  
// 5
// 1 2 3 4
// 1 5 9 16
// 1 50 100 2000
// 10 1364 9841 50000
// 50000 50000 50000 50000

// Sample Output  
// 4
// 35
// 22100
// 423883295
// 1

#include<stdlib.h>
#include<stdio.h>

int main(){
    int T = 0;
    scanf("%d\n", &T);

    for(itn i = 0; i < T; i++){
        int A = 0, B = 0, C = 0, D = 0;
        scanf("%d %d %d %d\n", A, B, C, D);

        long int count = 0;
        int third_edge_max = 0
        int third_edge = 0;
        int first_and_sec_edge = 0;

        // Find Range of Third Edge
        if(B + C > D){
            third_edge_max = D;
            third_edge = D - C + 1;
        }else{
            third_edge_max = B + C - 1;
            third_edge = B;
        }

        // 
        if(A + B > C){
            (B - A + 1) * 
        }



    }

    return 0;
}