// NTHUOJ 12220 - McDonald's fries   
// Description
// I worked at McDonald. My principle of selling fries is:
// "ガンニニヤサイバウ ( gan ni nya sai bau )"
// Yeah... "ガンニニヤサイバウ". I don't care if deficit of McDonald occurs or not. The fries sold each time are extremely large. Small size to large size, medium size to giant size, large size to another free one, just like give all the fries in the French fries station away.
// I still remember, that month, I worked 25 days. The manager came to ask me, they got 26 boxes of French fries of deficit, do you have any clue?
// How the hell could I know.
// ── Unknown McDonald's ex-employee
// Every time that employee thinks of that, he/she always wonders why couldn't he/she stuff more fries, which makes him/her feel bad. 
// The employee finds an old record about importing fries each day. The amount of the imported fries increases day by day. 
// The employee wonders that whether he/she could left shift the record by a number, and he/she could stuff more and more fries in the first few days. What about the last few days? Who cares. 
// The employee couldn't wait to imagine how happy he/she would be if getting the chance! He/She would stuff all the fries out! ​The employee will give you some numbers and ask you how he/she could stuff this much fries.
// You are given a non-decreasing sequence named a and a number k. 
// The sequence will left shift (左移) k slots and the first k elements will shift to the end of the sequence. For example: a={1,3,6,8,9}, k=2. After left shifting, new a will be {6,8,9,1,3}.
// Each query has one number f, and you're going to find out the index i such that f <= ai and |f - ai| is the smallest. If there's no such i, output "gan ni nya sai bau". If there are multiple i you could pick, choose the i with the smallest index. Note that this is katakana(片假名), not Chinese or something else.

// Input
// The first line contains three integers n, k, q.
// The second line contains n integers, which indicate the elements of sequence a.
// There are q lines below. Each line contains one integer f.
// 1 <= n, q <= 106, 1 <= ai, f <= 1015, 0 <= k < n.

// Output
// For each query, output the index i that f <= ai and | f - ai| is the smallest. If there are multiple answers i being the smallest, choose the i with smallest index. If there's no such i, output "gan ni nya sai bau".
// Remember to output a '\n' at the end of the output. 

// Sample Input  
// 5 2 5
// 1 3 6 8 9
// 5
// 7
// 1
// 4
// 10

// Sample Output  
// 1
// 2
// 4
// 1
// gan ni nya sai bau

// 2020/05/19 SYC

#include<stdlib.h>
#include<stdio.h>

int main(){

    return 0;
}