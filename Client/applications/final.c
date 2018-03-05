#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "ping.h"

int compensation = 0;
int irRight;
int irLeft;
int block = 135;

static void turnThroughAngle(int angle)
{
    int ticks = (int) round(angle*0.284);
    if (angle > 0)
    {
        if (compensation == 0)
        {
            drive_goto(-ticks , ticks - 1);
            compensation = 1;
        }
        else
        {
            drive_goto(-ticks , ticks);
            compensation = 0;
        }
    }
    else
    {
        if (compensation == 0)
        {
        drive_goto(-ticks + 1, ticks );
        compensation = 1;
        }
        else
        {
        drive_goto(-ticks , ticks);
        compensation = 0;
        }
    } 

}

void InfaRed() 
{    
   	irLeft = 0;
    irRight = 0;
    
    for(int dacVal = 0; dacVal < 256; dacVal += 8)
    {
        dac_ctr(26, 0, dacVal);
        freqout(11, 1, 38000);
        irLeft += input(10);   
        
        dac_ctr(27, 1, dacVal);
        freqout(1, 1, 38000);
        irRight += input(2);
    }
	return;    
}


int main(int argc, const char* argv[])
{
    low(26);
    low(27);
    drive_goto(20,20);
    while(1)
    {
    	drive_goto(block,block);
    	InfaRed();
;    	printf("left = %d\n", irLeft);
    	if (irLeft == 20) 
    	{
    		turnThroughAngle(90);
    	} 
    	else if (ping_cm(8) > 25) 
    	{
    	continue;

    	}
    	else if (irRight == 20) 
    	{
    		turnThroughAngle(-90);
    	}
    	else 
    	{
    		turnThroughAngle(180);
    	}

    }
}