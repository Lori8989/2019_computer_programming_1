// NTHUOJ 11758 - A - Markov Matrix   
// Description
// Writer: jjjjj19980806       Description: pclightyear        Difficulty: ★★★☆☆
// In mathematics, a Markov matrix is a square matrix used to describe the transitions of a Markov chain. Each of its entries is a nonnegative real number representing a probability. It has found use throughout a wide variety of scientific fields, including population genetics.
// Consider a country with n cities. Originally, each city has its own population, which can be described as a state vector X0. As the time pass by, the population will move from one city to another. The whole progress can be described as a n × n Markov matrix A.
// In this problem, if the state vector of the city population now is Xn, after a year, the state vector will become Xn+1, where Xn+1 = AXn.
// Now, you are given the original population in each city by a state vector X0 and the Markov matrix A. You need to calculate how many years it takes to let the first city’s population to drop below or equal to a specific number p, or it will never drop below p.

// Input
// The first line contains an integer T, representing the number of test cases.
// For each test case:
// The first line contains an integer n, representing the number of the cities.
// The next n lines contain n floating-point number aij, representing each entry in the Markov matrix A.
// The next line contains n integers Xi, representing each entry in the state vector X0.
// The next line contains an integer p, representing the specific number of population.
// It is guaranteed that:
// 1 ≤ T ≤ 5
// 1 ≤ n ≤ 5
// 0 ≤ X0i ≤ 106

// Output
// Please output how many years it takes to let the first city’s population to drop below p, or output "Never" if it will never drop below p.

// Sample Input  
// 3
// 
// 2
// 0.5 0.5
// 0.5 0.5
// 1000 0
// 500
// 
// 3
// 0.4 0.5 0.3
// 0.4 0.3 0
// 0.2 0.2 0.7
// 6000 3000 1000
// 1000
// 
// 2
// 0.9 0.8
// 0.1 0.2
// 1000 0
// 889

// Sample Output  
// 1
// Never
// 3

// 2020/06/19 SYC

#include <stdio.h>
#include <stdlib.h>

int main(){

    return 0;
}