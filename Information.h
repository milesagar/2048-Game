//
//  Information.h
//  2048
//
//  Created by Miles Agar on 2/12/15.
//  Copyright (c) 2015 Miles Agar. All rights reserved.
//

#ifndef _048_Information_h
#define _048_Information_h

// Forward Declarations
int  Digit_Count        ( int num );
int  Board_Sum          ( int ** arry );
void Print_Arry         ( int ** arry );
int  Are_Boards_Equal   ( int ** Board, int ** Test );
void Score_Info         ( int score, int moves );

int Digit_Count ( int num )
{
    
    int count = 0;
    
    if ( num == 0 )
        count++;
    
    while ( num != 0 )
    {
        
        num = num / 10;
        count++;
        
    }
    
    return count;
    
}

int Board_Sum ( int ** arry )
{
    int i, a, sum = 0;
    
    for ( i = 0; i < 4; i++ )
        for ( a = 0; a < 4; a++ )
            sum += arry[i][a];
    
    return sum;
    
}

void Print_Arry( int ** arry )
{
    
    int i, a, b;
    
    
    for (i = 0; i < 4; i++)
    {
        
        for (a = 0; a < 4; a++)
        {
            
            printf("%d", arry[i][a]);
            for ( b = 0; b < 7 - Digit_Count( arry[i][a] ); b++ )
                printf(" ");
            
        }
        
        printf("\n");
        
    }
    
}

int Are_Boards_Equal ( int ** Board, int ** Test )
{
    int i, a, equality_Failures = 0;
    for ( i = 0; i < 4; i++ )
        for ( a = 0; a < 4; a++ )
            if ( Board[i][a] != Test[i][a] )
                equality_Failures++;
    
    if ( equality_Failures )
        return 0;
    else
        return 1;
    
}

void Score_Info ( int score, int moves )
{
    
    printf("You have earned %d points in %d moves\n", score, moves );
    printf("Good job!\n\n");
    
}


#endif