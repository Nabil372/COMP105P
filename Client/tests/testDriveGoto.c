#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "ping.h"

int main(int argc, const char* argv[])
{
  int lastL, lastR, currentL, currentR;

  // Store the first encoder values
  drive_getTicks(&lastL, &lastR);
  
  for (int k = 0; k < 20; ++k)
    {

      // Distance to drive 
      int driveL = rand() % 100 - 50;
      int driveR = rand() % 100 - 50;

      // Drive it
      drive_goto(driveL, driveR);

      // Get the encoder values now
      drive_getTicks(&currentL, &currentR);

      // Print encoder value and error
      printf("%d %d\n", (currentL - lastL - driveL), (currentR - lastR - driveR));

      // Set to new values
      lastL = currentL;
      lastR = currentR;
    }
}
