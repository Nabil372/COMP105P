#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include "midterm.h"



int main()
{       //here we type cast with (int*), integer pointer. To access heap memory we must use malloc, occurs in memory.
    L = (int*)malloc(1*sizeof(int)); // drive_getTicks(L,R) only accepts pointers. to learn more google c memory model.
    R = (int*)malloc(1*sizeof(int));
    drive_getTicks(L, R); // s

    
    short signed int margin;  
    short signed int speedDiff;
    int startSpeed=30;
    int backSpeed=30; 
    
    low(26);
    low(27);
    
    while (front==0)
    {
        infraRed();
        
        margin=irLeft-irRight; // negative towards left wall. And if its positive towards the right wall
        speedDiff=margin*3;  // calibration for margins.
        
        if (speedDiff>10) {
            speedDiff=10;
        }

        if (speedDiff<-10) {
         speedDiff=-10;
        }
        // If margin is between this, just travel normally
        if (margin<=1 && margin>=-1) {
            drive_speed(startSpeed,startSpeed);
            push(0);
        }
        else if (margin>1) { // Closer to right, therefore turn left
            drive_speed(startSpeed,startSpeed+speedDiff+2);
            push(speedDiff + 2);
        }
        else if (margin<-1) { // Closer to left, therefore turn right
            drive_speed((startSpeed-speedDiff) + 2,startSpeed);
            push(speedDiff - 2);
        }
        DeadEnd(20); // If deadend is found then exit the main loop and come back
    
        deadReckon();
  
    }
    
    printDisAndAng();
    drive_goto(51,-51);
    pause(1500);
    
    /* ALL SENSORS ARE NOW TURNED OFF! */
    while(speedBack != -10100101) {
        speedBack = pop(); //here we use the most recent values of the linkedlist to drivespeed back.
        pause(138); // 2nd last map- 135, turn map - 140, both work with 140 to, 145 - 2nd map 138
        if (speedBack == 0) drive_speed(backSpeed,backSpeed); // if the robot is somewhere in the middle drive straight.
        else if (speedBack > 0) drive_speed(backSpeed + speedBack, backSpeed);
        else if (speedBack < 0) drive_speed(backSpeed, backSpeed - speedBack);
    }
    drive_speed(0,0);
    pause(300);
    return 0;
}

