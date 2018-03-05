#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "ping.h

int compensation = 0;

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

static int LEFT = 0, RIGHT = 1;

int getDistanceFromTheWall(int wall) {

    low(26);
    low(27);

    int irLeft = 0;
    int irRight = 0;

    for(int dacVal = 0; dacVal < 160; dacVal += 8) {

        dac_ctr(26, 0, dacVal);
        freqout(11, 1, 38000);
        irLeft += input(10);

        dac_ctr(27, 1, dacVal);
        freqout(1, 1, 38000);
        irRight += input(2);
    }

    if (wall == LEFT) {

        return irLeft;
    } else if (wall == RIGHT) {

        return irRight;
    }

    //in case of the wrong input
    printf("ERROR in 'getDistanceFromTheWall' function \n");
    return -1;
}

int main(int argc, const char* argv[])
{
  // Drive ahead nice and slow
  int x = 18;
  int temp = 0;
  float pi = 3.14159265;

  while(ping_cm(8) > 10)
  {
    drive_goto(x, x);

    // Read the left and right sensors
    int irLeft =  getDistanceFromTheWall(LEFT);
    if (temp == 0)
    {
      temp = irLeft;
    }
    
    printf("%d\n", temp);
    printf("%d\n", irLeft);

    if (temp != irLeft)
    {
      printf("THis is x1 : %d", temp);
      printf("THis is x2 : %d", irLeft);
      float angleinradian = atan((temp*10 - irLeft*10)/(x*3.25));

      int angle = (int) (angleinradian * 180.0 /pi);
      printf("ANGLE TO TURN %d\n", angle);
      turnThroughAngle(angle * -1);
    }
    temp = irLeft;
    pause(5);
  }
  
  return 0;
}