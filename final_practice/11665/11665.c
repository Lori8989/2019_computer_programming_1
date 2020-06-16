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
#define North 'N'
#define South 'S'
#define East 'E'
#define West 'W'
#define Forward 'F'
#define Right 'R'
#define Left 'L'
#define Jump 'J'
#define Border '#'
#define Secret '$'
#define Hill '^'
#define Ground '='
#define MaxMapSize 100
#define MaxInstrSize 105

typedef struct pos{
    int r;
    int c;
}Pos;

void showMap(char (*map)[MaxMapSize], const Pos head, Pos head1, Pos head2, Pos cen, int rows, int cols){
    // printf("===================\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == head.r && j == head.c){
                printf("o");
            }else if((i == head1.r && j == head1.c) || (i == head2.r && j == head2.c)){
                printf("x");
            }else if(i == cen.r && j == cen.c){
                printf("O");
            }else{
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("===================\n");
}

int forward(char (*map)[MaxMapSize], Pos *head, Pos *head1, Pos *head2, Pos *cen){
    Pos forward, tempHead, tempHead1, tempHead2;
    int addSecret = 0;
    forward.r = head->r - cen->r;
    forward.c = head->c - cen->c;

    // Forward Move Head
    tempHead.r = head->r + forward.r;
    tempHead.c = head->c + forward.c;

    // Forward Move Head1
    tempHead1.r = head1->r + forward.r;
    tempHead1.c = head1->c + forward.c;
    
    // Forward Move Head2
    tempHead2.r = head2->r + forward.r;
    tempHead2.c = head2->c + forward.c;

    if((map[tempHead.r][tempHead.c] != Border && map[tempHead.r][tempHead.c] != Hill) &&
       (map[tempHead1.r][tempHead1.c] != Border && map[tempHead1.r][tempHead1.c] != Hill) &&
       (map[tempHead2.r][tempHead2.c] != Border && map[tempHead2.r][tempHead2.c] != Hill)){
           (*head) = tempHead;
           (*head1) = tempHead1;
           (*head2) = tempHead2;
           // Forward Move Center
            cen->r = cen->r + forward.r;
            cen->c = cen->c + forward.c;

           if(map[tempHead.r][tempHead.c] == Secret){addSecret++; map[tempHead.r][tempHead.c] = Ground;}
           if(map[tempHead1.r][tempHead1.c] == Secret){addSecret++; map[tempHead1.r][tempHead1.c] = Ground;}
           if(map[tempHead2.r][tempHead2.c] == Secret){addSecret++; map[tempHead2.r][tempHead2.c] = Ground;}
    }

    printf("Forward Head: R: %d, C: %d\n", head->r, head->c);

    return addSecret;
}

void turnRight(Pos *head, const Pos cen){
    // int headPos = {*headC, *headR}; // [0]: X, [1]: Y
    // For X&Y Coordinate
    // X = cos(t) * X - sin(t) * Y; Y = sin(t) * X + cos(t) * Y;
    // t = -90 deg
    // X = (-1) * Y; Y = X;
    // As for Row&Col coordinate, left&Right Reverse
    // C = -R; R = C;
    int headPosX = -(head->r - cen.r);
    int headPosY = (head->c - cen.c);
    head->c = headPosX + cen.r;
    head->r = headPosY + cen.c;
    printf("Turn Right Head: R: %d, C: %d\n", headPosY, headPosX);
}

void turnLeft(Pos *head, const Pos cen){
    // int headPos = {*headC, *headR}; // [0]: X, [1]: Y
    // For X&Y Coordinate
    // X = cos(t) * X - sin(t) * Y; Y = sin(t) * X + cos(t) * Y;
    // t = 90 deg
    // X = (-1) * Y; Y = X;
    // As for Row&Col coordinate, left&Right Reverse
    // C = R; R = -C;
    int headPosX = head->r;
    int headPosY = -(head->c);
    head->c = headPosX;
    head->r = headPosY;
    printf("Turn Left Head: R: %d, C: %d\n", headPosY, headPosX);
}

int main(){
    char dir = North;
    int rows = 0, cols = 0, n = 0;
    int secretsCount = 0;
    Pos cen, head, head1, head2;
    char map[MaxMapSize][MaxMapSize] = {0};
    char instrs[MaxInstrSize] = {0};
    scanf("%d %d %d %c\n", &rows, &cols, &n, &dir);
    scanf("%s", instrs);

    printf("Rows:%d Cols:%d N:%d Dir:%c\n", rows, cols, n, dir);

    for(int i = 0; i < rows; i++){
        int isHead1Occur = 0;
        char tempbuff[105] = {0};
        scanf("%s", tempbuff);
        for(int j = 0; j < cols; j++){
            char tempC = tempbuff[j];
            // scanf("%c", &tempC);
            // printf("%c", tempC);

            if(tempC == '\n'){continue;}

            if(tempC == 'o'){
                head.r = i;
                head.c = j;
                map[i][j] = '=';
            }else if(tempC == 'x' && (!isHead1Occur)){
                head1.r = i;
                head1.c = j;
                isHead1Occur = 1;
                map[i][j] = '=';
            }else if(tempC == 'x' && isHead1Occur){
                head2.r = i;
                head2.c = j;
                map[i][j] = '=';
            }else if(tempC == 'O'){
                map[i][j] = '=';
            }else{
                map[i][j] = tempC;
            }
        }
        // scanf("\n");
    }

    if(dir == North){cen.r = head.r + 1; cen.c = head.c;}
    else if(dir == South){cen.r = head.r - 1; cen.c = head.c;}
    else if(dir == East){cen.r = head.r; cen.c = head.c - 1;}
    else if(dir == West){cen.r = head.r; cen.r = head.c + 1;}

    showMap(map, head, head1, head2, cen, rows, cols);

    for(int i = 0; i < n; i++){
        printf("%dth %c\n", i, instrs[i]);
        switch(instrs[i]){
            case Forward:
                // printf("%dth %c\n", i, instrs[i]);
                secretsCount += forward(map, &head, &head1, &head2, &cen);
                break;
            case Right:
                turnRight(&head, cen);
                turnRight(&head1, cen);
                turnRight(&head2, cen);
                break;
            case Left:
                turnLeft(&head, cen);
                turnLeft(&head1, cen);
                turnLeft(&head2, cen);
                break;
            case Jump:
                secretsCount += forward(map, &head, &head1, &head2, &cen);
                secretsCount += forward(map, &head, &head1, &head2, &cen);
                break;
        }
        showMap(map, head, head1, head2, cen, rows, cols);
    }

    printf("%d\n", secretsCount);
}