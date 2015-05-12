//
//  Movement.h
//  2048
//
//  Created by Miles Agar on 2/12/15.
//  Copyright (c) 2015 Miles Agar. All rights reserved.
//

// Movement Functions

#include "Manipulation.h"
#include "Information.h"

#ifndef _048_Movement_h
#define _048_Movement_h

int Move        ( int ** Board, char direction );

int Move_Left   ( int ** Board, int i, int a, int row);
int Move_Down   ( int ** Board, int i, int a, int column );
int Move_Up     ( int ** Board, int i, int a, int column );
int Move_Right  ( int ** Board, int i, int a, int row );

int Move_Test   ( int ** Board, int ** Test,  char verbose );

int Move ( int ** Board, char direction )
{
    int score = 0, i;
    
    switch ( direction )
    {
            
        case 'a':
            for ( i = 0; i < 4; i++ )
                score += Move_Left( Board, 0, 1, i );
            break;
            
        case 's':
            for ( i = 0; i < 4; i++ )
                score += Move_Down( Board, 3, 2, i );
            break;
            
        case 'w':
            for ( i = 0; i < 4; i++ )
                score += Move_Up( Board, 0, 1, i );
            break;
            
        case 'd':
            for ( i = 0; i < 4; i++ )
                score += Move_Right( Board, 3, 2, i );
            break;
        
    }
    
    return score;
}

int Move_Left ( int ** Board, int i, int a, int row)
{
    int score = 0;
    
    if ( Board[row][i] )
    {
        
        if ( Board[row][a] )
        {
            
            if ( Board[row][i] == Board[row][a] )
            {
                
                Board[row][i] += Board[row][a];
                Board[row][a]  = 0;
                
                score += Board[row][i];
                
            }
            else if ( (a - i) > 1 )
            {
                
                Board[row][i + 1] = Board[row][a];
                Board[row][a]     = 0;
                
            }
            
            i++;
            
        }
        
    }
    else if ( Board[row][a] )
    {
        
        Board[row][i] = Board[row][a];
        Board[row][a] = 0;
        
    }
    
    a++;
    
    if ( a < 4 )
        score += Move_Left( Board, i, a, row );
    
    return score;
    
}

int Move_Down ( int ** Board, int i, int a, int column)
{
    int score = 0;
    
    if ( Board[i][column] )
    {
        
        if ( Board[a][column] )
        {
            
            if ( Board[i][column] == Board[a][column] )
            {
                
                Board[i][column] += Board[a][column];
                Board[a][column]  = 0;
                
                score += Board[i][column];
                
            }
            else if ( (i - a) > 1 )
            {
                
                Board[i - 1][column] = Board[a][column];
                Board[a][column]     = 0;
                
            }
            
            i--;
            
        }
        
    }
    else if ( Board[a][column] )
    {
        
        Board[i][column] = Board[a][column];
        Board[a][column] = 0;
        
    }
    
    a--;
    
    if ( a >= 0 )
        score += Move_Down( Board, i, a, column );
    
    return score;
    
}

int Move_Up ( int ** Board, int i, int a, int column)
{
    int score = 0;
    
    if ( Board[i][column] )
    {
        
        if ( Board[a][column] )
        {
            
            if ( Board[i][column] == Board[a][column] )
            {
                
                Board[i][column] += Board[a][column];
                Board[a][column]  = 0;
                
                score += Board[i][column];
                
            }
            else if ( (a - i) > 1 )
            {
                
                Board[i + 1][column] = Board[a][column];
                Board[a][column]     = 0;
                
            }
            
            i++;
            
        }
        
    }
    else if ( Board[a][column] )
    {
        
        Board[i][column] = Board[a][column];
        Board[a][column] = 0;
        
    }
    
    a++;
    
    if ( a < 4 )
        score += Move_Up( Board, i, a, column );
    
    return score;
    
}

int Move_Right ( int ** Board, int i, int a, int row)
{
    int score = 0;
    
    if ( Board[row][i] )
    {
        
        if ( Board[row][a] )
        {
            
            if ( Board[row][i] == Board[row][a] )
            {
                
                Board[row][i] += Board[row][a];
                Board[row][a]  = 0;
                
                score += Board[row][i];
                
            }
            else if ( (i - a) > 1 )
            {
                
                Board[row][i - 1] = Board[row][a];
                Board[row][a]     = 0;
                
            }
            
            i--;
            
        }
        
    }
    else if ( Board[row][a] )
    {
        
        Board[row][i] = Board[row][a];
        Board[row][a] = 0;
        
    }
    
    a--;
    
    if ( a >= 0 )
        score += Move_Right( Board, i, a, row );
    
    return score;
    
}




int Move_Test ( int ** Board, int ** Test, char verbose )
{
    
    int possible_moves = 0, game_Over = 0;
    
    if ( verbose == 'y' )
        printf("Your possible moves are:\n");
    
    Board_Transfer ( Board, Test );
    Move( Test, 'a' );
    if ( !Are_Boards_Equal ( Board, Test ) )
    {
        if ( verbose == 'y' )
            printf("\tLeft!\n");
        possible_moves++;
    }
    
    Board_Transfer ( Board, Test );
    Move( Test, 's' );
    if ( !Are_Boards_Equal ( Board, Test ) )
    {
        if ( verbose == 'y' )
            printf("\tDown!\n");
        possible_moves++;
    }
    
    Board_Transfer ( Board, Test );
    Move( Test, 'w' );
    if ( !Are_Boards_Equal ( Board, Test ) )
    {
        if ( verbose == 'y' )
            printf("\tUp!\n");
        possible_moves++;
    }
    
    Board_Transfer ( Board, Test );
    Move(Test, 'd' );
    if ( !Are_Boards_Equal ( Board, Test ) )
    {
        if ( verbose == 'y' )
            printf("\tRight!\n");
        possible_moves++;
    }
    
    
    if ( !possible_moves )
    {
        printf("Whoops! You can't move in any direction.\n");
        printf("Looks like that's game over!\n");
        game_Over = 1;
    }
    
    printf("\n");
    
    return game_Over;
    
}

#endif


// Old Functions

/*
int Move_Left ( int ** Board, int recursion_count, int row )
{
    
    int score = 0;
    
    if ( Board[row][0])
    {
        
        if ( Board[row][1])
        {
            
            if ( Board[row][0] == Board [row][1] )
            {
                
                Board[row][0] += Board[row][1];
                Board[row][1] = Board[row][2];
                Board[row][2] = Board[row][3];
                Board[row][3] = 0;
                
                score += Board[row][0];
                
                if ( Board[row][1] )
                {
                    
                    if ( Board[row][2] )
                    {
                        
                        if ( Board[row][1] == Board[row][2] )
                        {
                            
                            Board[row][1] += Board[row][2];
                            Board[row][2] = 0;
                            
                            score += Board[row][1];
                            
                        }
                        
                    }
                    
                }
                else
                {
                    
                    Board[row][1] = Board[row][2];
                    Board[row][2] = 0;
                    
                }
                
            }
            
            if ( Board[row][2] )
            {
                
                if ( Board[row][2] == Board[row][1] )
                {
                    
                    Board[row][1] += Board[row][2];
                    Board[row][2] = Board[row][3];
                    Board[row][3] = 0;
                    
                    score += Board[row][1];
                    
                }
                else if ( Board[row][3] == Board[row][2] )
                {
                    
                    Board[row][2] += Board[row][3];
                    Board[row][3] = 0;
                    
                    score += Board[row][2];
                    
                }
                
            }
            else if ( Board[row][3] )
            {
                
                if ( Board[row][3] == Board[row][1] )
                {
                    
                    Board[row][1] += Board[row][3];
                    Board[row][3] = 0;
                    
                    score += Board[row][1];
                    
                }
                else
                {
                    
                    Board[row][2] = Board[row][3];
                    Board[row][3] = 0;
                    
                }
                
            }
            
        }
        else if ( Board[row][2] )
        {
            
            if ( Board[row][2] == Board[row][0] )
            {
                
                Board[row][0] += Board[row][2];
                Board[row][1] = Board[row][3];
                Board[row][2] = 0;
                Board[row][3] = 0;
                
                score += Board[row][0];
                
            }
            else if ( Board[row][3] == Board[row][2] )
            {
                
                Board[row][1] = Board[row][2] + Board[row][3];
                Board[row][2] = 0;
                Board[row][3] = 0;
                
                score += Board[row][1];
                
            }
            else
            {
                
                Board[row][1] = Board[row][2];
                Board[row][2] = Board[row][3];
                Board[row][3] = 0;
                
            }
            
        }
        else if ( Board[row][3] == Board[row][0] )
        {
            
            Board[row][0] += Board[row][3];
            Board[row][3] = 0;
            
            score += Board[row][0];
            
        }
        else
        {
            
            Board[row][1] = Board[row][3];
            Board[row][3] = 0;
            
        }
        
    }
    else if ( recursion_count <= 4 )
    {
        
        Board[row][0] = Board[row][1];
        Board[row][1] = Board[row][2];
        Board[row][2] = Board[row][3];
        Board[row][3] = 0;
        recursion_count++;
        
        score += Move_Left( Board, recursion_count, row );
        
    }
        
    return score;
    
}

int Move_Up ( int ** Board, int recursion_count, int column )
{
    
    int score = 0;
    
    if ( Board[0][column])
    {
        
        if ( Board[1][column])
        {
            
            if ( Board[0][column] == Board [1][column] )
            {
                
                Board[0][column] += Board[1][column];
                Board[1][column] = Board[2][column];
                Board[2][column] = Board[3][column];
                Board[3][column] = 0;
                
                score += Board[0][column];
                
                if ( Board[1][column] )
                {
                    
                    if ( Board[2][column] )
                    {
                        
                        if ( Board[1][column] == Board[2][column] )
                        {
                            
                            Board[1][column] += Board[2][column];
                            Board[2][column] = 0;
                            
                            score += Board[1][column];
                            
                        }
                        
                    }
                    
                }
                else
                {
                    
                    Board[1][column] = Board[2][column];
                    Board[2][column] = 0;
                    
                }
                
            }
            
            if ( Board[2][column] )
            {
                
                if ( Board[2][column] == Board[1][column] )
                {
                    
                    Board[1][column] += Board[2][column];
                    Board[2][column] = Board[3][column];
                    Board[3][column] = 0;
                    
                    score += Board[1][column];
                    
                }
                else if ( Board[3][column] == Board[2][column] )
                {
                    
                    Board[2][column] += Board[3][column];
                    Board[3][column] = 0;
                    
                    score += Board[2][column];
                    
                }
                
            }
            else if ( Board[3][column] )
            {
                
                if ( Board[3][column] == Board[1][column] )
                {
                    
                    Board[1][column] += Board[3][column];
                    Board[3][column] = 0;
                    
                    score += Board[1][column];
                    
                }
                else
                {
                    
                    Board[2][column] = Board[3][column];
                    Board[3][column] = 0;
                    
                }
                
            }
            
        }
        else if ( Board[2][column] )
        {
            
            if ( Board[2][column] == Board[0][column] )
            {
                
                Board[0][column] += Board[2][column];
                Board[1][column] = Board[3][column];
                Board[2][column] = 0;
                Board[3][column] = 0;
                
                score += Board[0][column];
                
            }
            else if ( Board[3][column] == Board[2][column] )
            {
                
                Board[1][column] = Board[2][column] + Board[3][column];
                Board[2][column] = 0;
                Board[3][column] = 0;
                
                score += Board[1][column];
                
            }
            else
            {
                
                Board[1][column] = Board[2][column];
                Board[2][column] = Board[3][column];
                Board[3][column] = 0;
                
            }
            
        }
        else if ( Board[3][column] == Board[0][column] ) {
            
            Board[0][column] += Board[3][column];
            Board[3][column] = 0;
            
            score += Board[0][column];
            
        }
        else
        {
            
            Board[1][column] = Board[3][column];
            Board[3][column] = 0;
            
        }
        
    }
    else if ( recursion_count <= 3 )
    {
        
        Board[0][column] = Board[1][column];
        Board[1][column] = Board[2][column];
        Board[2][column] = Board[3][column];
        Board[3][column] = 0;
        recursion_count++;
        
        score += Move_Up( Board, recursion_count, column );
        
    }
    
    return score;
    
}

int Move_Right ( int ** Board, int recursion_count, int row )
{
    
    int score = 0;
    
    if ( Board[row][3] )
    {
        
        if ( Board[row][2] )
        {
            
            if ( Board[row][3] == Board [row][2] )
            {
                
                Board[row][3] += Board[row][2];
                Board[row][2] = Board[row][1];
                Board[row][1] = Board[row][0];
                Board[row][0] = 0;
                
                score += Board[row][3];
                
                if ( Board[row][2] )
                {
                    
                    if ( Board[row][1] )
                    {
                        
                        if ( Board[row][2] == Board[row][1] )
                        {
                            
                            Board[row][2] += Board[row][1];
                            Board[row][1] = 0;
                            
                            score += Board[row][2];
                            
                        }
                        
                    }
                    
                }
                else
                {
                    
                    Board[row][2] = Board[row][1];
                    Board[row][1] = 0;
                    
                }
                
            }
            
            if ( Board[row][1] )
            {
                
                if ( Board[row][1] == Board[row][2] )
                {
                    
                    Board[row][2] += Board[row][1];
                    Board[row][1] = Board[row][0];
                    Board[row][0] = 0;
                    
                    score += Board[row][2];
                    
                }
                else if ( Board[row][0] == Board[row][1] )
                {
                    
                    Board[row][1] += Board[row][0];
                    Board[row][0] = 0;
                    
                    score += Board[row][1];
                    
                }
                
            }
            else if ( Board[row][0] )
            {
                
                if ( Board[row][0] == Board[row][2] )
                {
                    
                    Board[row][2] += Board[row][0];
                    Board[row][0] = 0;
                    
                    score += Board[row][2];
                    
                }
                else
                {
                    
                    Board[row][1] = Board[row][0];
                    Board[row][0] = 0;
                }
                
            }
            
        }
        else if ( Board[row][1] )
        {
            
            if ( Board[row][1] == Board[row][3] )
            {
                
                Board[row][3] += Board[row][1];
                Board[row][2] = Board[row][0];
                Board[row][1] = 0;
                Board[row][0] = 0;
                
                score += Board[row][3];
                
            }
            else if ( Board[row][0] == Board[row][1] )
            {
                
                Board[row][2] = Board[row][1] + Board[row][0];
                Board[row][1] = 0;
                Board[row][0] = 0;
                
                score += Board[row][2];
                
            }
            else
            {
                
                Board[row][2] = Board[row][1];
                Board[row][1] = Board[row][0];
                Board[row][0] = 0;
                
            }
            
        }
        else if ( Board[row][0] == Board[row][3] )
        {
            
            Board[row][3] += Board[row][0];
            Board[row][0] = 0;
            
            score += Board[row][3];
            
        }
        else
        {
            
            Board[row][2] = Board[row][0];
            Board[row][0] = 0;
            
        }
        
    }
    else if ( recursion_count <= 4 )
    {
        
        Board[row][3] = Board[row][2];
        Board[row][2] = Board[row][1];
        Board[row][1] = Board[row][0];
        Board[row][0] = 0;
        recursion_count++;
        
        score += Move_Right( Board, recursion_count, row );
        
    }
    
    return score;
    
}

int Move_Down ( int ** Board, int recursion_count, int column )
{
    
    int score = 0;
    
    if ( Board[3][column])
    {
        
        if ( Board[2][column])
        {
            
            if ( Board[3][column] == Board [2][column] )
            {
                
                Board[3][column] += Board[2][column];
                Board[2][column] = Board[1][column];
                Board[1][column] = Board[0][column];
                Board[0][column] = 0;
                
                score += Board[3][column];
                
                if ( Board[2][column] )
                {
                    
                    if ( Board[1][column] )
                    {
                    
                        if ( Board[2][column] == Board[1][column] )
                        {
                            
                            Board[2][column] += Board[1][column];
                            Board[1][column] = 0;
                            
                            score += Board[2][column];
                            
                        }
                        
                    }
                    
                }
                else
                {
                    
                    Board[2][column] = Board[1][column];
                    Board[1][column] = 0;
                    
                }
                
            }
            
            if ( Board[1][column] )
            {
                
                if ( Board[1][column] == Board[2][column] )
                {
                    
                    Board[2][column] += Board[1][column];
                    Board[1][column] = Board[0][column];
                    Board[0][column] = 0;
                    
                    score += Board[2][column];
                    
                }
                else if ( Board[0][column] == Board[1][column] )
                {
                    
                    Board[1][column] += Board[0][column];
                    Board[0][column] = 0;
                    
                    score += Board[1][column];
                    
                }
                
            }
            else if ( Board[0][column] )
            {
                
                if ( Board[0][column] == Board[2][column] )
                {
                    
                    Board[2][column] += Board[0][column];
                    Board[0][column] = 0;
                    
                    score += Board[2][column];
                    
                }
                else
                {
                    Board[1][column] = Board[0][column];
                    Board[0][column] = 0;
                }
                
            }
            
        }
        else if ( Board[1][column] )
        {
            
            if ( Board[1][column] == Board[3][column] )
            {
                
                Board[3][column] += Board[1][column];
                Board[2][column] = Board[0][column];
                Board[1][column] = 0;
                Board[0][column] = 0;
                
                score += Board[3][column];
                
            }
            else if ( Board[0][column] == Board[1][column] )
            {
                
                Board[2][column] = Board[1][column] + Board[0][column];
                Board[1][column] = 0;
                Board[0][column] = 0;
                
                score += Board[2][column];
                
            }
            else
            {
                
                Board[2][column] = Board[1][column];
                Board[1][column] = Board[0][column];
                Board[0][column] = 0;
                
            }
            
        }
        else if ( Board[0][column] == Board[3][column] )
        {
            
            Board[3][column] += Board[0][column];
            Board[0][column] = 0;
            
            score += Board[3][column];
            
        }
        else
        {
            
            Board[2][column] = Board[0][column];
            Board[0][column] = 0;
            
        }
        
    }
    else if ( recursion_count <= 3 )
    {
        
        Board[3][column] = Board[2][column];
        Board[2][column] = Board[1][column];
        Board[1][column] = Board[0][column];
        Board[0][column] = 0;
        recursion_count++;
        
        score += Move_Down( Board, recursion_count, column );
        
    }
    
    return score;
    
}

*/