#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "abdrive.h"
#include "simpletext.h"
#include "simpletools.h"
#include "ping.h"
#include "dijk.h"

int irRight;
int irLeft;
int distanceFromFront;
int block = 125; //126 125
int block_back = 123;
int left_counter = 0;
int right_counter = 0;
//int left_counter180 = 0;
//int right_counter180 = 0;

int drivespeed = 60;
int driveturn = 40;

int direction = 1; //we are initially facing forwards, so 1 is used to represent goin forwards.
int position = 0; // our initial postion is at 0
int last_turn = 0; // last_turn = 0 means that our last was a left turn and last turn being right means last_turn = 1. 

int Connected[150]; //This is a list in which we store Connected blocks.
int ConnectedCount = 0; //This allows us to print a list of Connected blocks, and also 

double error = 0.0;

void AngleCorrection(){
    int counts = right_counter-left_counter ;
    double turnby = ((-(double)counts * 1.97)+error);
    printf("-----------------------angle %f -----------------------\n",turnby);
    //int counts180 = left_counter180 - right_counter180;
    if ( fabs(turnby) > 3.52){ //if value is like 3.94 we still get a 0.3-.4.. degree error value that builds up this needs to be corrected.
        printf("-----------------------left_counter: %d, right_counter: %d  angle %f -----------------------\n",left_counter, right_counter,turnby);
        //printf("180 counts: %d", counts180);
        printf("\n");
        printf("counts: %d\n", counts ); 
        turnThroughAngle(turnby);
        printf("turning:  %d\n",(int)(turnby*0.284));
        error = turnby-((double)((int)(turnby*0.284))/0.284);
        left_counter = 0;
        right_counter = 0;
        //right_counter180 = 0;
       // left_counter180 = 0;
    }
}

int modulo(int x,int N)
{
    return (x % N + N) %N;
}

void updateDirection(int R)
{
    direction += R;
    direction = modulo(direction,4);
}

int updatePosition(int set)
{
    if (direction == 1)
    {//front
        if (set)
        {
            position+=1;
        }
        else
        {
            return position+1;
        }
    }
    else if (direction == 2)
    {//R
        if (set)
        {
            position+=4;
        }
        else
        {
            return position+4;
        }
    }
    else if (direction == 0)
    {//L
        if (set)
        {
            position-=4;
        }
        else
        {
            return position-4;
        }
    }
    else if (direction == 3)
    {//back
        if (set)
        {
            position-=1;
        }
        else
        {
            return position-1;
        }
    }
    return 0;
}

void driveBack(int array[], int size){
    AngleCorrection();
    direction = 1;
    int i = 0;
    while (i < size)
    {
        int move = array[i+1] - array[i];
        if (move == -16){break;}

        printf("move: %d\n",move );
        printf("direction before checks: %d\n",direction );

        if (direction == 1){}
        else if (direction == 2){ turnThroughAngle(90); updateDirection(-1);}
        else if (direction == 0){turnThroughAngle(-90); updateDirection(+1);}
        printf("direction after checks: %d\n",direction );

        if (move == 1){
            int nextMove = array[i+2] - array[i+1];
            if (nextMove == 1){
                drive_goto(block_back * 2,block_back * 2);
                i = i + 2;
                continue;
            }
            else
            {
                drive_goto(block_back,block_back);
                i++;
                continue;
            }
            
        }
        else if (move == 4){
            int nextMove = array[i+2] - array[i+1];
            if (nextMove == 4){
                turnThroughAngle(-90);
                updateDirection(+1);
                drive_goto(block_back * 2,block_back * 2);
                
                i = i + 2;
                continue;
            }
            else
            {
            turnThroughAngle(-90);
            updateDirection(+1);
            drive_goto(block_back,block_back);
            
            i++;
            continue;
            }
        }
        else if (move == -4){
            int nextMove = array[i+2] - array[i+1];
            if (nextMove == -4){
                turnThroughAngle(90);
                updateDirection(-1);
                drive_goto(block_back * 2,block_back * 2);
                
                i = i + 2;
                continue;
            }
            else
            {
            updateDirection(-1);
            turnThroughAngle(90);
            drive_goto(block_back,block_back);
            
            i++;
            continue;
            }
        }else if (move == -1){
            int nextMove = array[i+2] - array[i+1];
            if (nextMove == -1){
                drive_goto(-block_back * 2,-block_back * 2);
                i = i + 2;
                continue;
            }
            else
            {
                drive_goto(-block_back,-block_back);
                i++;
                continue;
            }
        }
    }

}

void Sense() 
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
    printf("%d,%d\n", irLeft,irRight);
    if (irLeft == 20)
    {
        updateDirection(-1);
        Connected[ConnectedCount] = position;
        Connected[ConnectedCount+1] = updatePosition(0);
        printf("-------%d,%d-------\n",Connected[ConnectedCount],Connected[ConnectedCount+1]);
        ConnectedCount += 2;
        updateDirection(+1);
        printf("\n"); 
    }
    if (irRight == 20)
    {
        updateDirection(1);
        Connected[ConnectedCount] = position;
        Connected[ConnectedCount+1] = updatePosition(0);
        printf("=====%d,%d=====\n",Connected[ConnectedCount],Connected[ConnectedCount+1]);
        ConnectedCount += 2;
        updateDirection(-1);
        printf("\n"); 
    }

    int distanceFromFront = ping_cm(8);
    printf("distanceFromFront: %d\n", distanceFromFront );
    printf("\n");
    if (distanceFromFront > 39)
    {
        
        printf("Front is free:\n");
        Connected[ConnectedCount] = position;
        Connected[ConnectedCount+1] = updatePosition(0);
        printf("++++++%d,%d++++++\n",position, updatePosition(0));
        ConnectedCount += 2;
        printf("\n");
        
    }
    //there used to be a return here    
}



int main(int argc, const char* argv[])
{
    low(26);
    low(27);


    //drive_goto(30,30);

    direction = 1;//forward
    position = 0;

    while(1)
    {
        AngleCorrection();
        int distanceFromFront = ping_cm(8);

        if (distanceFromFront > (block / 3.25)) //if front is free? why is this here?
        {
            drive_goto(block,block);
            distanceFromFront = ping_cm(8);
            if ((17-distanceFromFront)>0)
            {
                drive_goto(-(17-distanceFromFront)*3.25,-(17-distanceFromFront)*3.25);
            }else if (((distanceFromFront-17)>0)&&(distanceFromFront < 40)) {
                drive_goto((distanceFromFront-17)*3.25,(distanceFromFront-17)*3.25);
            }
            updatePosition(1);
            printf("current position: %d\n", position);

            if (position == 0) //in this following code block we are checking whether the bot has returned to its original pos.
            {
                if (last_turn == 1) //if last turn was a right turn
                {
                    //turnThroughAngle(180); // turn 180 degrees left wise
                    turnThroughAngle(90);
                    turnThroughAngle(90);
                    last_turn = 0;
                    left_counter+=2;
                }
                else // if left turn
                {
                    //turnThroughAngle(-180); //turn 180 degrees right wise
                    turnThroughAngle(-90);
                    turnThroughAngle(-90);
                    right_counter+=2;
                    last_turn = 1;
                }
                position = 0;
                direction = 1;
                break;
            }

        }
        

        Sense();
        if (irLeft == 20) 
        {
            last_turn = 0;
            left_counter++;
            updateDirection(-1);
            turnThroughAngle(90);
        } 
        else if (distanceFromFront > 39) 
        {

        continue;

        }
        else if (irRight == 20) 
        {
            last_turn = 1;
            right_counter++;
            updateDirection(+1);
            turnThroughAngle(-90);
        }
        else 
        {
            if (last_turn == 1){
                updateDirection(-2);
                turnThroughAngle(90);
                turnThroughAngle(90);
                last_turn = 0;
                //left_counter180++;
                left_counter +=2;
            }else{
                updateDirection(2);
                turnThroughAngle(-90);
                turnThroughAngle(-90);
                last_turn = 1;
                //right_counter180++;
                right_counter +=2;
            }
            
            
        }

    }

    for (int i = 0;i<ConnectedCount;i+=2){
        printf("%d,%d\n", Connected[i],Connected[i+1]);
    }
    populateGraph(Connected,ConnectedCount);
    for (int i = 0;i<17;i++){
        for (int j = 0;j<17;j++){
            printf("%d,",graph[i][j]);
        }
        printf("\n");
    }
    dijkstra(0,16);
    
    pause(1000);


    driveBack(bestpath,pathsize);


    
}