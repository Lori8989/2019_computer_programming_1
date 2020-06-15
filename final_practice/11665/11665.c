// NTHUOJ 11665 - World war   
// Description
// Country H upgrades the tank in order to defeat Country T in world war. 
// You're a soldier in great Country H and have received secret tasks : Collect the military secrets related to Country T. 
// You wil get a map of Country T like this:
//  is your tank with size 3x3 (xox is the head of the tank). 
// '$' represents a military secrets,  '#' represents the wall, '^' represents the hill.
// If you tank (3x3 body) is overlaped with the '$', you will pick it up ($ can't be counted again). If '#' or '^' is in front of the tank(in front of the xox, tank's front part), you can not move. Military secrets' position don't appear at initial tank's position.
// The tank has four forward directions(South, East, North, West). Its direction is where xox heads. Notice that the upper of the map is the North, and the initial direction of tank is not always North.
// And you will receive a sequence of instructions, which contains F (takes a step along the tank's head direction), R(tank's head turns right), and L(tank's head turns left). Instructions like R and L only change tank's head direction, and don't affect tank's position(would not cause moving). 
// Since the tank is upgraded, the tank can now execute instruction J (takes two step along the tanks head direction). However, you should NOT execute J when the tank may collides with hill or wall (in this case, you pick up nothing, and stand still at the original position).
// Your will collect the military secrets within the valid instruction as many as possible. Then report the number of it to your boss, HT, immediately !
// Fighting ! 

// There are sample codes for you:
// #include <stdio.h>
// #include <string.h>

// #define EAST 0
// #define SOUTH 1
// #define WEST 2
// #define NORTH 3

// char map[100][100];
// char actions[100]={};
// int coin_amount = 0;

// // tank's initial direction
// char init_dir;
// // tank's direction now
// int dir_now;
// // tank's center x and y
// int center_x, center_y;

// void decide_initial_direction()
// {
//     /// Decide tank's initial direction
//     /// Using init_dir
//     /// To determine dir_now

 

// }

// void take_a_step()
// {
//     if (dir_now == NORTH){
//         /// Detect wall first
//         if ( ??? ){

//         }
//         /// And then detect hill
//         else if (( ??? )) {

//         }
//         /// If there is no obstacle, take a step
//         else {

//         }
//     }
//     else if (dir_now == SOUTH){

//     }
//     else if (dir_now == EAST){

//     }
//     else if (dir_now == WEST){

//     }
// }

// void pick_the_coins()
// {
//     int j, k;
//     for (j = center_x - 1; j <= center_x + 1; j++){
//         for (k = center_y - 1; k <= center_y + 1; k++){
//             /// determine whether there are coins under the tank

 

//         }
//     }
// }

// void turn_right()
// {
//     /// Change direction depending on dir_now
// }

 

// void turn_left()
// {
//     /// Change direction depending on dir_now
// }

// int main()
// {
//     int i, j, k, rows, cols;
//     int actions_number;
//     int component = 0;

//     /// Raed problem's input
//     scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
//     while (getchar() != '\n');
//     for (i = 0; i < actions_number; i++){
//         scanf("%c", &actions[i]);
//     }

//     /// Read map
//     for (i = 1; i <= rows; i++){
//         while (getchar() != '\n');
//         for (j = 1; j <= cols; j++){
//             scanf("%c", &map[i][j]);
//             /// Find tank's center x and y
//             if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
//                 component++;
//                 if (component == 5){
//                     center_x = i;
//                     center_y = j;
//                 }
//             }
//         }
//     }

//     decide_initial_direction();

//     for (i = 0; i < actions_number; i++){
//         if (actions[i] == 'F'){
//             take_a_step();
//             pick_the_coins();
//         }

//         else if (  ){

//            /* TODO : Implement the instruction "J" here */

//        }         
//         else{
//             if (actions[i] == 'R'){
//                 turn_right();
//             }
//             if (actions[i] == 'L'){
//                 turn_left();
//             }
//         }
//     }

//     printf("%d\n", coin_amount);

//     return 0;
// }

 

// Input
// The first line of the input contains four things: 
// 1. The rows of the map (0 < rows < 100)
// 2. The columns of the map (0 < cols < 100)
// 3. The total length of instructions (0 < instructions's length < 100)
// 4. The initial tank's direction(N, S, E, W)
// The second line is the content of instructions.
// For the next lines, they illustrate the map.

// Output
// The number of military informations you get. (printf "\n" in the end)

// Sample Input  
// 6 8 10 N
// JFFRJFFJRJ
// ########
// #=^$^==#
// #=xox==#
// #$OOO$$#
// #=OOO==#
// ########

// Sample Output  
// 2

#include<stdio.h>
#include<stdlib.h>

int main(){

}