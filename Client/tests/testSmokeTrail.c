#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "ping.h"

#ifdef BUILDING_IN_SIMULATOR
#include "simulator.h"
#endif

int main(int argc, const char* argv[])
{
  int lastL, lastR, currentL, currentR;

  // Enable the smoke trail
#ifdef BUILDING_IN_SIMULATOR
  simulator_startNewSmokeTrail();
#endif
  high(26);
  high(27);

  int showTrail = 1;
  
  for (int k = 0; k < 200; ++k)
    {

      // Random drive speed
      int driveL = rand() % 200 - 100;
      int driveR = driveL + rand() % 50 - 25;

      // Drive it
      drive_speed(driveL, driveR);

      // Sleep for 1 second
      pause(1000);
      

      // Randomly flip whether we show the trail
      int randomSample = rand() % 100;
      printf("%d\n", randomSample);
      if (showTrail == 0)
	{
	  if (randomSample > 50)
	    {
	      printf("add\n");
#ifdef BUILDING_IN_SIMULATOR
	      simulator_startNewSmokeTrail();
#endif
              high(26);
              high(27);
	      showTrail = 1;
	    }
	}
      else
	{
	  if (randomSample > 80)
	    {
	      printf("remove\n");
#ifdef BUILDING_IN_SIMULATOR
	      simulator_stopSmokeTrail();
#endif
              low(26);
              low(27);
	      showTrail = 0;
	    }
	}	
    }
}
