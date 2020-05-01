// NTHUOJ 11618 pB - Birthday Party   
// Description
// Princess Twilight Sparkle's birthday is around the corner. As a good friend of Twilight, the best party pony Pinkie Pie decides to throw a birthday party for her! Pinkie plans to invite n  ponies to join this big party. At the beginning of the party, Pinkie will give away a bunch of balloons, and here's how it will work :
// First, all ​ ponies, labelled from 1 to n, will sit in a circle. Pinkie will then give away three different colors of balloons -- red, blue and yellow. For each color, Pinkie will randomly choose a number x​. Counting begins at the pony labelled 1 and proceeds around the circle. After skipping x​ ponies, Pinkie will give that pony a balloon. The whole round stops when any pony could get two same balloons, and Pinkie won't give that pony the same balloon again. That is, there are three round of giveaway in total, and each pony will get three different colors of balloons at most.
// For example, if there are 6 ponies in the party:
// The first time Pinkie choose x = 2 and gives red balloons, so ponies labelled 2, 4 and 6 will get red balloons.
// The second time Pinkie choose x = 3 and gives blue balloons, so ponies labelled 3 and 6 will get blue balloons.
// The last time Pinkie choose x = 5 and gives yellow balloons, so all ponies will get yellow balloons.
// (The order of getting the yellow balloons is : 5, 4, 3, 2, 1, 6)
// Pinkie is wondering how many ponies will get three different kinds of balloons, so she can prepare for the following game she wants to play in the party. If you can help Pinkie, maybe she will teach you how to make a mouth-watering cupcake.

// Input
// First line contains one integer ​T, representing the number of testcases (or the parties Pinkie will throw, who doesn't like parties?).
// The next T lines contains four integers n, x1, x2, x3, representing the number of ponies who are invited to the party, and the three random number Pinkie chooses in the party.
// ​1 ≤ T ≤ 10
// Testcase #1 ~ #4 : 1 ≤ x1, x2, x3 ≤ n ≤ 105
// Testcase #5 Bonus : 1 ≤ x1, x2, x3 ≤ n ≤ 1018
 
// Output
// For each testcase (party), please output a line contains one integer representing the number of ponies who get three balloons.
// (i.e. Please print '\n' after each answer.)

// Sample Input  
// 2
// 6 2 3 5
// 10 2 3 7

// Sample Output  
// 1
// 5

// 2020/05/01 SYC

#include<stdio.h>
#include<stdlib.h>

long long int gcd(long long int a, long long int b){
    while(b > 0){
        long long int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long int triGcd(long long int a, long long int b, long long int c){
    return gcd(gcd(a, b), c);
}

int main(){
    int T = 0;
    scanf("%d\n", &T);

    for(int i = 0; i < T; i++){
        long long int n = 0, x1 = 0, x2 = 0, x3 = 0;
        int isX1Divide = 0, isX2Divide = 0, isX3Divide = 0;
        scanf("%lld %lld %lld %lld\n", &n, &x1, &x2, &x3);

        if(gcd(n, x1) != 1){isX1Divide = 1;}
        if(gcd(n, x2) != 1){isX2Divide = 1;}
        if(gcd(n, x3) != 1){isX3Divide = 1;}

        int needGcd = isX1Divide + isX2Divide + isX3Divide;
        long long int gcdForAll = 0;
        long long int get3BalloonPonies = 0;

        if(needGcd == 3){// Find Least Common Multiple
            gcdForAll = triGcd(x1, x2, x3);
            get3BalloonPonies = n / gcdForAll;
        }else if(needGcd == 2){// Find Least Common Multiple: lcm = (Xi / gcd) * (Xj / gcd) * gcd = Xi / gcd * Xj
            long long int lcm = 0;
            if(isX1Divide && isX2Divide){
                gcdForAll = gcd(x1, x2);
                lcm = x1 / gcdForAll * x2;
                // printf("%lld %lld\n", x1, x2);
                // printf("%lld\n", gcdForAll);
                get3BalloonPonies = n / lcm;
            }else if(isX2Divide && isX3Divide){
                gcdForAll = gcd(x2, x3);
                lcm = x2 / gcdForAll * x3;
                get3BalloonPonies = n / lcm;
            }else if(isX1Divide && isX3Divide){
                gcdForAll = gcd(x1, x3);
                lcm = x1 / gcdForAll * x3;
                get3BalloonPonies = n / lcm;
            }
        }else if(needGcd == 1){
            if(isX1Divide){
                get3BalloonPonies = n / x1;
            }else if(isX2Divide){
                get3BalloonPonies = n / x2;
            }else if(isX3Divide){
                get3BalloonPonies = n / x3;
            }
        }else{
            get3BalloonPonies = n;
        }

        printf("%lld\n", get3BalloonPonies);
    }
    return 0;
}