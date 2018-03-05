struct node
{
    int data;
    struct node *link;
}*top = NULL;

int front = 0;                         // To terminate the main while loop.
int *L,*R;                 // Pointers to the the number of ticks travelled (Co-Ordinates)
double *angle;            // The angle moved from the start
float BotRadius = 105.8; // radius of the wheel.
short signed int irLeft, irRight;   // Distance from Left and Right wall in terms of IR units
int speedBack; // this here is the margin value that is popped off the stack.
double average;           // Average distance the robot has moved
int counter = 0;

void DeadEnd(int wantedDistance);
void push(int change);
int  pop(void);
void infraRed(void);
void deadReckon(void);
void printDisAndAng(void);

//These are the variables used for deadreckoning.
float totalX = 0;
float totalY = 0;
int previousLeft;
int previousRight;

void DeadEnd(int wantedDistance) 
{    
    infraRed();
    int currentDistance;
    currentDistance = ping_cm(8); // 8 is the pin number for the ultrasound sensor, for the front
    if(wantedDistance > currentDistance && irRight < 18 && irLeft < 18) { //this means, that we have detected a wall on either side and infront.
        drive_speed(0,0);
        pause(300);
        front++;
    }
    return;    
}

void printDisAndAng()
{
    float angularDisplacement = atan2(totalY, totalX) * (180/M_PI);
    printf("Displacement Angle = %f degrees \n", angularDisplacement);
    printf("Distance travelled = %f mm \n", sqrt((totalY*totalY) + (totalX*totalX)));
    return;
}


void push(int change)
{
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = change;
    temp->link = top;
    top = temp;
    counter++;
    printf("%d \n", counter);
}

int pop()
{    
    struct node *temp;
    if (counter == 9)
    {
        printf("Stack is empty\n");
        return -10100101;
    }
    else
    {
        temp = top;
        top = top->link;
        counter--;
        printf("%d \n", counter);
    }
    return temp->data;
}

// Calculates the angle travelled from the inital position
void deadReckon() 
{    
    drive_getTicks(L,R); //This here, is the deadreckoning stuff improvements need to be made.
    float leftDist = (*L - previousLeft) * 3.25;
    float rightDist = (*R - previousRight) * 3.25;
    float centreDist=(leftDist+rightDist)/2;
    previousLeft = *L;
    previousRight = *R;
    float angleRotated= 90 - ((180 - ((((*L - *R) * 3.25) / BotRadius) * 180/M_PI)) / 2);
    angleRotated = angleRotated * (M_PI/180);
    float changeY=(centreDist*sin(angleRotated));
    totalY+=changeY;
    float changeX=(centreDist*cos(angleRotated));
    totalX+=changeX;
    return;
} 


void infraRed() 
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

// Used to check if the robot has reached the deadend. Uses the sensors to determine this.
