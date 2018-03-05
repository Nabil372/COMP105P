#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "ping.h"

int DO = 22, CLK = 23, DI = 24, CS = 25;      // SD card pins on Propeller BOE

int main(int argc, const char* argv[])
{
  low(26);                  
  low(27);
       // Open a file for writing

  int irLeftInitial = 0;
  for(int dacVal = 0; dacVal <= 160; dacVal += 8)  // <- add
    {                                               // <- add
      dac_ctr(26, 0, dacVal);                       // <- add          freqout(11, 1, 38000);                        // <- add
      irLeftInitial += input(10);
    }

  // Drive ahead nice and slow
  drive_speed(32, 32);
  
  while(ping_cm(8) > 8)
    {
      // Read the left and right sensors
      int irLeft;
      for(int dacVal = 0; dacVal <= 160; dacVal += 8)  // <- add
        {                                               // <- add
          dac_ctr(26, 0, dacVal);                       // <- add
          freqout(11, 1, 38000);                        // <- add
          irLeft += input(10);
        }

      //print("%f\n", (1.0 * (CNT - lastCNT)) / ms);
      

      int irRight = 0;
      for(int dacVal = 0; dacVal <= 160; dacVal += 8)  // <- add
        {                                               // <- add
          dac_ctr(27, 1, dacVal);                       // <- add
          freqout(1, 1, 38000);                        // <- add
          irRight += input(2);
        }

    
      //fflush(fp);
      
      if (irLeft > irLeftInitial)
        {
          drive_speed(20, 15);
        }
      else if (irLeft < irLeftInitial)
        {
          drive_speed(15,20);
        }
      else
        {
          drive_speed(20, 20);
        }

      pause(20);
    }
  
  // Stop
  drive_speed(0, 0);


  
  return 0;
}
