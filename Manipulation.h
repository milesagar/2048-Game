//
//  Manipulation.h
//  2048
//
//  Created by Miles Agar on 2/12/15.
//  Copyright (c) 2015 Miles Agar. All rights reserved.
//

// Board Creation/Manipulation

#include "Information.h"

#ifndef _048_Manipulation_h
#define _048_Manipulation_h

void Board_Create   ( int ** arry );
void Random_Fill    ( int ** arry );
void Board_Transfer ( int ** input, int ** output );


void Board_Create ( int ** arry )
{
    
    int i, a;
    for ( i = 0; i < 4; i++ )
        for ( a = 0; a < 4; a++ )
            arry[i][a] = 0;
    
    Random_Fill( arry );
    Random_Fill( arry );
    
}

void Random_Fill ( int ** arry )
{
    
    int place1, place2, wait = 1;
    
    while ( wait )
    {
        
        place1 = rand() % 4;
        place2 = rand() % 4;
        
        if ( arry[place1][place2] == 0 )
        {
            
            if ( rand() % ( 12 - ( Board_Sum( arry ) / 1024 ) ) == 0 )
                arry[place1][place2] = 4;
            else
                arry[place1][place2] = 2;
            
            wait = 0;
            
        }
        
    }
    
}

void Board_Transfer ( int ** input, int ** output )
{
    
    int i, a;
    for ( i = 0; i < 4; i++ )
        for ( a = 0; a < 4; a++ )
            output[i][a] = input[i][a];
    
}

#endif