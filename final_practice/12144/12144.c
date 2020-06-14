// NTHUOJ 12144 - Dark Souls   
// Description
// Dark Souls is a famous video game. The main character in Dark Souls 3 is known as
// " Ashen one ". Today you are the Ashen one.
// You are in a 5*5 room. You are at the
// position ( 1, 1 ) -- the top left corner -- and you want to reach the
// position ( 5, 5 )-- the lower right corner.
// There's no obstacle in the room but monsters. If you and the monster are at the same position, you need to fight it.
// The rule of fighting is Turn-based. You can always attack first, if the monster didn't die after your attack, then it's the monster's turn to attack you and so on. 
// There is always only two result after a fight, you died or the monster died.
// Note that once you lost your hp you can't restore it.
// Find out if you can reach the position ( 5,5 )

// Input
// input contain servel lines.
// First line contains three integers.
// The Hp, attack of Ashen one and k( 1 <= k <= 25 ) the number of monsters.
// Following k lines each lines contains four integers.
// The Hp, attack of i-th monster and the position x,y of i-th monster.
// All numbers are >= 1 and in the range of int

// Output
// If you can reach the position ( 5 ,5 ) print "HEIR OF FIRE DESTROYED"
// otherwise print "YOU DIED"
// remember to print \n at the end of output

// Sample Input  
// 100 20 5
// 41 50 5 5
// 22 24 2 4
// 30 10 1 3
// 26 25 2 5
// 28 41 1 4

// Sample Output  
// YOU DIED

#include<stdio.h>
#include<stdlib.h>

int main(){

    return 0;
}