#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           LClaw,         tmotorVex393_MC29, openLoop)

int test = 0;
int test2 = 20;
int test3 = 0;
bool yes = false;

task main()
{
    SensorValue[leftEncoder] = 0; //The leftEncoder keeps track of the degrees turned by the wheels of the leftMotor
    SensorValue[rightEncoder] = 0;//The rightEncoder keeps track of the degrees turned by the wheels of the rightMotor
    //Sets the encoders to their default value of 0.

    int limit = 0; //Stops the while loop when the robot moves a certain distance

    //Data gathered from measured values
    float diameterOfWheel = 4.25; //Diameter of each wheel in inches
    float tile = 23.25; //Length of each tile in inches on the field

    //Applications of the measured values
    float distanceToGo = tile; //Distance the robot needs to go in inches.
    float circumference = diameterOfWheel*PI; //Finds the circumference of each wheel in inches
    float rotations = distanceToGo/circumference; //Number of rotations the wheels turn to go a certain distance
    float degreesToTurn = rotations*360; //Degrees the wheels must turn in order to go a certain distance

    while(limit == 0) //Loop will run continuously until the limit value is changed
    {
        if(test2 >= abs(SensorValue[rightEncoder]-SensorValue[leftEncoder]) && yes)
        {
            test3+=1;
            test = (SensorValue[rightEncoder]-SensorValue[leftEncoder]);
            if(SensorValue[rightEncoder] <= SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = 30.5;
            }

            if(SensorValue[leftEncoder] <= SensorValue[rightEncoder])
            {
                motor[leftMotor] = 30.5;
                motor[rightMotor] = 40;
            }

            if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
            {
            		motor[leftMotor] = 40;
                motor[rightMotor] = 40;
          	}

        }
        else
        {
            if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) //If the sensor values are equal, then all the wheels must be turning equally
            {
                motor[leftMotor] = 40;  //Sets the speed of the left wheels
                motor[rightMotor] = 40; //Sets the speed of the right wheels
            }

            if(SensorValue[rightEncoder] < SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
            {
                motor[leftMotor] = 40; //Sets the speed of the left wheels
                motor[rightMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
                /*The right motor is slowed down so that the left wheels can catch up to the speed of the right wheels
                 This is done by finding the absolue value of the cosine of the difference between the left and and right
                 encoders. The absolute value of the cosine of any number will always be between 0 and 1. This value will
                 be multiplied by the base speed of 40 in order to slow the more powerful motor.
                 */
            }
            else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
            {
                motor[leftMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder])); //Similar function as above
                motor[rightMotor] = 40; //Sets the speed of the right wheels
            }

        if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
            {
            	  limit = 1;
            	 /*If the number of degrees to turn is less than both the absolute value of
            	 the encoder values, the limit will equal 1 in order to break outside of the while loop. */
            }
   			}
     }

    while(limit == 1) //Loop will run continuously until the value of the limit changes like before.
    {
    	//If we want to place down the yellow cone, we will be using the scissor lift.
    	//Place the yellow cone onto the red cone
      limit = 2;
 	  }

    while(limit == 2)
    {
    	//Lift up the red cone
    	limit = 3;
  	}

  	while(limit == 3)
    {
    	//Move backwards by 1.5 tiles
    	limit = 4;
  	}

  	while(limit == 4)
    {
    	//Turn to the left by 135 degrees
    	limit = 5;
  	}

  	while(limit == 5)
    {
    	//Go straight for root 2 of a tile.
    	limit = 6;
  	}

  	while(limit == 6)
    {
    	//Turn 90 degrees to the left again.
    	limit = 7;
  	}

  	while(limit == 7)
    {
    	//Move the car forward for 1 tile
    	limit = 8;
  	}

  	while(limit == 8)
  	{
  		//Drop the red cone
  		limit = 9;
  		wait1Msec(5000);
  	}
  	//FINISH
  	//Simulate this team:
  	//https://www.youtube.com/watch?v=MvlU9TCRpuQ
}
