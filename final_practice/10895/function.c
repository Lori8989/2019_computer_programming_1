// NTHUOJ 10895 - Grade report(different order)   
// Description
// Given a grade report for all students in a class, which includes student ID, Chinese grade, English grade, math grade, and science grade for each student. Please list the report sorted in two different way.
// If the order is descending, sort the grade by the total grade from high to low. If the total grade is the same between two students, then sort by order of Chinese grade, English grade, math grade, science grade, and student ID, which is from high to low for all grades and from low to high for student ID.
// If the order is ascending, sort the grade by the total grade from low to high. If the total grade is the same between two students, then sort by order of Chinese grade, English grade, math grade, science grade, and student ID, which is from low to high for all grades and from low to high for student ID.
// Note that in both two way, the student ID is sorted from low to high.
// You need to store these information in structures:
// typedef struct
// {
//    int ID;
//    int Chinese, English, math, science;
//    int total;
// } Grade;

// HINT
// Hint: While sorting, you can use qsort in <stdlib.h> or write other sorting algorithms by your self.
// function.h
// #ifndef FUNCTION_H
// #define FUNCTION_H
// typedef struct
// {
//    int ID;
//    int Chinese, English, math, science;
//    int total;
// } Grade;
// void sortGrade(Grade *gList, int n, char *order);
// #endif

// main.c
// #include <stdio.h>
// #include <stdlib.h>
// #include "function.h"
// int main(){
//     int n, i;
//     char order[20];
//     Grade gradeList[1000];
//     scanf("%d%s", &n, order);
//     for(i = 0; i < n; i++)
//         scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
//     sortGrade(gradeList, n, order);
//     for(i = 0; i < n; i++)
//         printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,gradeList[i].Chinese, gradeList[i].English,gradeList[i].math, gradeList[i].science);
//     return 0;
// }


// Input
// The first line contains an integer N and a string, which means the number of students in the class and the order which grade are sorting in respectively.
// In the following N lines, there are 5 integers: student ID, Chinese grade, English grade, math grade, and science grade in each line in order, which are separate by spaces.

// Output
// List the sorted report, while each line contains student ID, total grade, Chinese grade, English grade, math grade, and science grade in order, where there is a '\t' between each number. Note that there is a '\n' at the end of each line.

// Sample Input  
// 8 ascending 
// 104062888 100 98 100 100
// 104062444 98 100 100 100
// 104062555 100 100 98 100
// 104062222 98 100 100 100
// 104062666 100 100 100 100
// 104062111 100 100 100 98
// 104062333 100 100 100 97
// 104062777 100 99 99 100 

// Sample Output  
// 104062333   397 100 100 100 97
// 104062222   398 98  100 100 100
// 104062444   398 98  100 100 100
// 104062888   398 100 98  100 100
// 104062777   398 100 99  99  100
// 104062555   398 100 100 98  100
// 104062111   398 100 100 100 98
// 104062666   400 100 100 100 100

// Partial Judge Code
// 10895.c

// Partial Judge Header
// 10895.h

#include<stdio.h>
#include<stdlib.h>
#include"function.h"

int main(){

    return 0;
}