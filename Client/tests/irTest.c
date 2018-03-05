#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"

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

int main() {

    drive_speed(20, 20);
  
   for (int i = 0; i < 20; i++) {
        printf( "Left wall - %d\t||   Right wall - %d\n",
                getDistanceFromTheWall(LEFT), getDistanceFromTheWall(RIGHT) );
        pause(500);
        
   }

   return 0;
}
