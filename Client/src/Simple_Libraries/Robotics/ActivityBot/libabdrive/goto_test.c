
#include "simpletools.h"

volatile int abd_ticksL=0;
volatile int abd_ticksR=0;
volatile int abd_speedL=0;      // Requested servo speed left
volatile int abd_speedR=0;      // Requested servo speed right
int abd_rampStep=4;
int abd_speedLimit=128;
volatile int abd_zeroDelay=1;
volatile int abd_dlc;      // distance left calculated
volatile int abd_drc;      // distance right calculated
volatile int abd_dlca;                                 // distance left calculated (accumulated)
volatile int abd_drca;                                 // distance right calculated (accumulated)
volatile int abd_dsr;
volatile int abd_edL;                                      // error distance left
volatile int abd_edR;                                      // error distance right
volatile int abd_pL;                                       // proportional left
volatile int abd_pR;                                       // proportional right
volatile int abd_iL;                                   // integral left
volatile int abd_iR;                                   // integral right
volatile int abd_eaL;
volatile int abd_eaR;
volatile unsigned int _servoPulseReps=0;

#define interactive_development_mode

// To-do: What if current speed > speedLimit?
void drive_goto_orig(int left, int right)
{
  int ticksLstart = abd_ticksL;
  int ticksRstart = abd_ticksR;
  int ticksLtarget = ticksLstart + left;
  int ticksRtarget = ticksRstart + right;
  int distRampL = 0, distRampR = 0, rampClampL = 0, rampClampR = 0, distCruiseL = 0;
  int tCruiseR = 0;
  int tCruiseL = 0;
  int speedReqL = 0, speedreqR = 0;
  int distCruiseR = 0; 
  int dt = 20;

  left *= 1000;
  right *= 1000;

  printf("---\n");

  // Distance to ramp down if already going forward
  if(left > 0)
  {
    if(abd_speedL)
    {
      for(int i = abd_speedL; i > 0; i -= abd_rampStep) distRampL += (i * dt);
    }
    #ifdef interactive_development_mode
    printf("F Before ramp distRampL = %d\n", distRampL);
    #endif
    for(int i = abd_speedL; i <= abd_speedLimit; i += abd_rampStep)
    {
      if(i > abd_speedLimit) i = abd_speedLimit;
      distRampL += (i * dt * 2);
      rampClampL = i;
      if(left <= distRampL)
      {
        distRampL = left;
        break;
      }
    }
    #ifdef interactive_development_mode
    printf("F After ramp distRampL = %d\n", distRampL);
    #endif
  }
  if(right > 0)
  {
    if(abd_speedR)
    {
      for(int i = abd_speedR; i > 0; i -= abd_rampStep) distRampR += (i * dt);
    }
    #ifdef interactive_development_mode
    printf("F Before ramp distRampR = %d\n", distRampR);
    #endif
    // Distance to ramp up/down
    for(int i = abd_speedR; i <= abd_speedLimit; i += abd_rampStep)
    {
      if(i > abd_speedLimit) i = abd_speedLimit;
      distRampR += (i * dt * 2);
      rampClampR = i;
      if(right <= distRampR)
      {
        distRampR = right;
        break;
      }
    }
    #ifdef interactive_development_mode
    printf("F After ramp distRampR = %d\n", distRampR);
    #endif
  }
  /*
  printf("distRampL = %d\n", distRampL);
  printf("distCruiseL = %d\n", distCruiseL);
  printf("distCruiseL + distRampL = %d\n", distCruiseL + distRampL);
  printf("rampClampL = %d\n\n", rampClampL);

  printf("distRampR = %d\n", distRampR);
  printf("distCruiseR = %d\n", distCruiseR);
  printf("distCruiseR + distRampR = %d\n", distCruiseR + distRampR);
  printf("rampClampR = %d\n\n", rampClampR);
  */

  // Distance to ramp down if already going forward
  if(left < 0)
  {
    if(abd_speedL)
    {
      for(int i = abd_speedL; i < 0; i += abd_rampStep) distRampL -= (i * dt);
    }
    #ifdef interactive_development_mode
    printf("B Before ramp distRampL = %d\n", distRampL);
    #endif
    for(int i = abd_speedL; i >= -abd_speedLimit; i -= abd_rampStep)
    {
      if(i < -abd_speedLimit) i = -abd_speedLimit;
      distRampL += (i * dt * 2);
      rampClampL = i;
      if(left >= distRampL)
      {
        distRampL = left;
        break;
      }
    }
    #ifdef interactive_development_mode
    printf("B After ramp distRampL = %d\n", distRampL);
    #endif
  }
  //printf("distRampL = %d\n", distRampL);
  //while(1);
  if(right < 0)
  {
    if(abd_speedR)
    {
      for(int i = abd_speedR; i < 0; i += abd_rampStep) distRampR -= (i * dt);
    }
    #ifdef interactive_development_mode
    printf("B Before ramp distRampR = %d\n", distRampR);
    #endif
    // Distance to ramp up/down
    for(int i = abd_speedR; i >= -abd_speedLimit; i -= abd_rampStep)
    {
      if(i < -abd_speedLimit) i = -abd_speedLimit;
      distRampR += (i * dt * 2);
      rampClampR = i;
      if(right >= distRampR)
      {
        distRampR = right;
        break;
      }
    }
    #ifdef interactive_development_mode
    printf("B After ramp distRampR = %d\n", distRampR);
    #endif
  }



  //if(rampClampL > speedLimit) rampClampL = speedLimit;
  //if(rampClampR > speedLimit) rampClampR = speedLimit;
 
  //while(1);
  // Calculate distance & time full speed
  distCruiseL = left - distRampL;  
  distCruiseR = right - distRampR;  
  //tCruiseL = distCruiseL / speedLimit;
  //tCruiseR = distCruiseR / speedLimit;
  tCruiseL = distCruiseL / rampClampL;
  tCruiseR = distCruiseR / rampClampR;


  #ifdef interactive_development_mode
  printf("distRampL = %d\n", distRampL);
  printf("distCruiseL = %d\n", distCruiseL);
  printf("distCruiseL + distRampL = %d\n", distCruiseL + distRampL);
  printf("rampClampL = %d\n\n", rampClampL);

  printf("distRampR = %d\n", distRampR);
  printf("distCruiseR = %d\n", distCruiseR);
  printf("distCruiseR + distRampR = %d\n", distCruiseR + distRampR);
  printf("rampClampR = %d\n", rampClampR);
  #endif

  return;
  
  
  //Execute maneuver
  //while(0);
  //if(rampClampL) drive_ramp(rampClampL, rampClampR); 
  drive_ramp(rampClampL, rampClampR);

  if(rampClampL < 0 && tCruiseL > 0) pause(tCruiseL);
  if(rampClampL > 0 && tCruiseL > 0) pause(tCruiseL);


  //if(rampClampR < 0 && tCruiseR < 0) pause(-tCruiseR);
  //if(rampClampR > 0 && tCruiseR > 0) pause(tCruiseR);

  //if(tCruiseL > 0) pause(tCruiseL);                // To-Do remove left dependency
  drive_ramp(0, 0);

  pause(120);
  #ifdef interactive_development_mode
  printf("tCruiseL = %d\n\n", tCruiseL);
  #endif

  //while(1);

  // Correct for small errors
  //
  abd_zeroDelay = OFF;


  abd_dlc = abd_ticksL;
  abd_dlca = abd_dlc * abd_dsr;
  abd_edL = 0;
  abd_pL = 0;

  abd_drc = abd_ticksR;
  abd_drca = abd_drc * abd_dsr;
  abd_edR = 0;
  abd_pR = 0;


  #ifdef interactive_development_mode
  printf("ticksL, ticksR before correction: %d, %d\n", abd_ticksL, abd_ticksR);
  #endif

  int reps = 0;
  int tempL = 0, tempR = 0;
  int tempTicks = _servoPulseReps;
  while(1)
  {
    while(tempTicks >= _servoPulseReps);

    if(abd_ticksL > ticksLtarget)
    {
      tempL = -10;
      if(abd_iL > 0) abd_iL = 0;
    }
    else if (abd_ticksL < ticksLtarget)
    {
      tempL = 10;
      if(abd_iL < 0) abd_iL = 0;
    }
    else 
    {
      tempL = 0;
      abd_iL = 0;
    }

    if(abd_ticksR > ticksRtarget)
    {
      tempR = -10;
      if(abd_iR > 0) abd_iR = 0;
    }
    else if (abd_ticksR < ticksRtarget)
    {
      tempR = 10;
      if(abd_iR < 0) abd_iR = 0;
    }
    else 
    {
      tempR = 0;
      abd_iR = 0;
    }
    drive_speed(tempL, tempR);
    
    if((abd_ticksL == ticksLtarget) && (abd_ticksR == ticksRtarget))
    {
      reps++;
    }
    else
    {
      reps = 0;
    }
    if(reps == 10) break;
  }
  drive_speed(0, 0);
  #ifdef interactive_development_mode
  printf("ticksL, ticksR after correction: %d, %d\n", abd_ticksL, abd_ticksR);
  #endif

  abd_dlc = abd_ticksL;
  abd_dlca = abd_dlc * abd_dsr;
  abd_edL = 0;
  abd_pL = 0;

  abd_drc = abd_ticksR;
  abd_drca = abd_drc * abd_dsr;
  abd_edR = 0;
  abd_pR = 0;

  abd_zeroDelay = ON;
  //
}


