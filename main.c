//
//  main.c
//  2048
//
//  Created by Miles Agar on 1/22/15.
//  Copyright (c) 2015 Miles Agar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Movement.h"
#include "Manipulation.h"
#include "Information.h"



int Game_Start ();
void Game_Help ( int ** Board, int ** Test );


// Begin Main
int main( int argc, char *argv[] )
{
    
    time_t t;
    srand( (unsigned) time(&t) );
    
    int finalScore;
    
    finalScore = Game_Start();
    
    printf("Your final score was: %d\n", finalScore);
    
    return 0;
    
}


// The Game
int Game_Start () {
    
    int i, gameOver = 0, score = 0, isInputValid = 0, numMoves = 0;
    char user_Move;
    
    int ** Board = (int **) malloc( sizeof(int *) * 32 );
    for ( i = 0; i < 4; i++ )
        Board[i] = (int *) malloc(4 * sizeof(int));
    
    int ** Test = (int **) malloc( sizeof(int *) * 32 );
    for ( i = 0; i < 4; i++ )
        Test[i] = (int *) malloc(4 * sizeof(int));
    
    Board_Create(Board);
    Board_Create(Test);
    
    Game_Help( Board, Test );
    Print_Arry(Board);
    
    while ( !gameOver )
    {
        
        printf("Score: %d\n", score);
        printf("Moves: %d\n", numMoves);
        
        while ( !isInputValid )
        {
            
            Board_Transfer( Board, Test );
            
            printf("> ");
            scanf("%c", &user_Move);
            while ( user_Move == '\n' )
                scanf("%c", &user_Move);
            
            printf("\n------\n");
        
            switch ( user_Move )
            {
                case 'a':
                case 'A':
                case 'h':
                case 'H':
                    score += Move( Board, 'a' );
                    
                    if ( Are_Boards_Equal( Board, Test ) )
                    {
                        printf("\nThat Move didn't do anything!\n");
                        printf("Let me show you want you can do.\n\n");
                        Move_Test( Board, Test, 'y' );
                        
                        isInputValid = 0;
                    }
                    else
                        isInputValid = 1;
                    
                    break;
                
                case 's':
                case 'S':
                case 'j':
                case 'J':
                    score += Move( Board, 's' );
                    
                    if ( Are_Boards_Equal( Board, Test ) )
                    {
                        printf("\nThat Move didn't do anything!\n");
                        printf("Let me show you want you can do.\n\n");
                        Move_Test( Board, Test, 'y' );
                        
                        isInputValid = 0;
                    }
                    else
                        isInputValid = 1;
                    
                    break;
                
                case 'w':
                case 'W':
                case 'k':
                case 'K':
                    score += Move( Board, 'w' );
                    
                    if ( Are_Boards_Equal( Board, Test ) )
                    {
                        printf("\nThat Move didn't do anything!\n");
                        printf("Let me show you want you can do.\n\n");
                        Move_Test( Board, Test, 'y' );
                        
                        isInputValid = 0;
                    }
                    else
                        isInputValid = 1;
                    
                    break;
                
                case 'd':
                case 'D':
                case 'l':
                case 'L':
                    score += Move( Board, 'd' );
                    
                    if ( Are_Boards_Equal( Board, Test ) )
                    {
                        printf("\nThat Move didn't do anything!\n");
                        printf("Let me show you want you can do.\n\n");
                        Move_Test( Board, Test, 'y' );
                        
                        isInputValid = 0;
                    }
                    else
                        isInputValid = 1;
                    
                    break;
                    
                case 'o':
                case 'O':
                    printf("\n");
                    Score_Info( score, numMoves );
                    break;
                
                case 'i':
                case 'I':
                case '?':
                    Game_Help( Board, Test );
                    break;
                
                case 'q':
                case 'Q':
                    printf("Sorry to see you go so soon!\n");
                    gameOver = 2;
                    isInputValid = 2;
                    break;
                
                
                default:
                    printf("Seems like you entered an invalid command.\n");
                
            }
            
        }
        numMoves++;
        isInputValid = 0;
        
        Random_Fill( Board );
        Print_Arry( Board );
        
        gameOver = Move_Test(Board, Test, 'n');
        
    }
    
    return score;
    
}

void Game_Help ( int ** Board, int ** Test )
{
    
    printf("Welcome!\n");
    printf("The controls are as follows:\n");
    
    printf("\n");
    
    printf("\tleft: \ta or h\n");
    printf("\tdown: \ts or j\n");
    printf("\tup:   \tw or k\n");
    printf("\tright:\td or l\n");
    
    printf("\n");
    
    printf("\tscore:\ts\n");
    printf("\thelp: \ti or ?\n");
    printf("\tquit: \tq\n");
    
    printf("\n");
    
    printf("And by the way...\n");
    Move_Test(Board, Test, 'y');
    
}