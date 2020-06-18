// NTHUOJ 12662 - I got a perfect body   
// Description
// I got a young body.
// ~by anonymous coroner
// You are a coroner, and you need to buy some Formalin to keep your body in good condition. There're n kinds of Formalin, and you have p dollars. Luckily the Formalin is on sale. If you buy exactly k kinds of Formalin, you only need to pay the most expensive one of them.
// You got n products and p dollars.
// Everytime you buy exactly k products at once, you only need to pay the most expensive product among the k products.
// For the i-th product, the price equals to ai.
// Find the maximum number of products you can buy with p dollars.

// Example:
// If n=5 and you got p=6 dollars.
// If you buy exactly k=2 products, you only need to pay the most expensive one of them.
// Products' price: 2, 4, 3, 5, 7.
// In this case, you can buy products of price 4, 3 then you only need to pay 4 dollars.
// You left with 2 dollars, then you can buy products of price 2.
// The maximum number of products you can buy in this case is 3.

// Input
// The input start with t(1<= t <=10) means number of testcases.
// Each testcase contains two lines.
// First line contains three numbers n(2<=n<=3*10^5), p(1<= p <= 10^9), k(2 <= k <= n).
// Second line contains n integer ai(1 <= ai <= 10000).

// Output
// For each testcase print the maximum number of products you can buy with p dollars.
// Remember to print \n at the end of each output.

// Sample Input  
// 8
// 5 6 2
// 2 4 3 5 7
// 5 11 2
// 2 4 3 5 7
// 3 2 3
// 4 2 6
// 5 2 3
// 10 1 3 9 2
// 2 10000 2
// 10000 10000
// 2 9999 2
// 10000 10000
// 4 6 4
// 3 2 3 2
// 5 5 3
// 1 2 2 1 2

// Sample Output  
// 3
// 4
// 1
// 1
// 2
// 0
// 4
// 5

// 2020/06/19 SYC

#include<stdio.h>
#include<stdlib.h>

int main(){
    int t = 0;
    scanf("%d\n", &t);

    for(int i = 0; i < t; i++){
        int n = 0, p = 0, k = 0;
        scanf("%d %d %d\n", &n, &p, &k);
        // printf("N: %d P: %d K: %d\n", n, p, k);

        int *a = (int *)malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            scanf("%d", &(a[j]));
            // printf("%d ", a[j]);
        }
        // printf("\n");

        free(a);
    }

    return 0;
}