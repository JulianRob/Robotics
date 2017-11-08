#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop)

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
		float ratio = 0;
    SensorValue[leftEncoder] = 0; //The leftEncoder keeps track of the degrees turned by the wheels of the leftMotor
    SensorValue[rightEncoder] = 0;//The rightEncoder keeps track of the degrees turned by the wheels of the rightMotor
    //Sets the encoders to their default value of 0.

    int limit = 0; //Stops the while loop when the robot moves a certain distance
    int Turning = 650;

    //Data gathered from measured values
    float diameterOfWheel = 4.25; //Diameter of each wheel in inches
    float tile = 23.25; //Length of each tile in inches on the field

    //Applications of the measured values
    float distanceToGo = tile*2; //Distance the robot needs to go in inches.
    float circumference = diameterOfWheel*PI; //Finds the circumference of each wheel in inches
    float rotations = distanceToGo/circumference; //Number of rotations the wheels turn to go a certain distance
    float degreesToTurn = rotations*360; //Degrees the wheels must turn in order to go a certain distance

    while(limit == 0)
    {
    	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) //If the sensor values are equal, then all the wheels must be turning equally
        {
            motor[leftMotor] = 80;  //Sets the speed of the left wheels
            motor[rightMotor] = 80; //Sets the speed of the right wheels
        }

        if(SensorValue[rightEncoder] < SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
        {
            motor[leftMotor] = 80; //Sets the speed of the left wheels
            motor[rightMotor] = 80*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]-ratio));
            /*The right motor is slowed down so that the left wheels can catch up to the speed of the right wheels
             This is done by finding the absolue value of the cosine of the difference between the left and and right
             encoders. The absolute value of the cosine of any number will always be between 0 and 1. This value will
             be multiplied by the base speed of 40 in order to slow the more powerful motor.
             */
        }
        else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
        {
            motor[leftMotor] = 80*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]-ratio)); //Similar function as above
            motor[rightMotor] = 80; //Sets the speed of the right wheels
        }
         //If the number of degrees to turn is less than both the absolute value of the encoder values, the limit will increase so
         //that the while loop it's inside of will stop.

        if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
         {
        	 limit = 1;
        	 motor[rightMotor] = 0;
        	 motor[leftMotor] = 0;
        	 SensorValue[leftEncoder] = 0;
        	 SensorValue[rightEncoder] = 0;

        	  distanceToGo = tile*1.5; //Distance the robot needs to go in inches.
            rotations = distanceToGo/circumference; //Number of rotations the wheels turn to go a certain distance
            degreesToTurn = rotations*360; //Degrees the wheels must turn in order to go a certain distance

            wait1Msec(1000);
         }
    }

    while(limit == 1) //Loop will run continuously until the value of the limit changes like before.
    {
    	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) //If the sensor values are equal, then all the wheels must be turning equally
        {
            motor[leftMotor] = -80;  //Sets the speed of the left wheels
            motor[rightMotor] = -80; //Sets the speed of the right wheels
        }

        if(SensorValue[rightEncoder] > SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
        {
            motor[leftMotor] = -80; //Sets the speed of the left wheels
            motor[rightMotor] = -80*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]+ratio));
            /*The right motor is slowed down so that the left wheels can catch up to the speed of the right wheels
             This is done by finding the absolue value of the cosine of the difference between the left and and right
             encoders. The absolute value of the cosine of any number will always be between 0 and 1. This value will
             be multiplied by the base speed of 40 in order to slow the more powerful motor.
             */
        }
        else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[leftMotor] = -80*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]+ratio)); //Similar function as above
            motor[rightMotor] = -80; //Sets the speed of the right wheels
        }
         //If the number of degrees to turn is less than both the absolute value of the encoder values, the limit will increase so
         //that the while loop it's inside of will stop.

        if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
         {
        	 limit = 2;
        	 motor[rightMotor] = 0;
        	 motor[leftMotor] = 0;
        	 SensorValue[leftEncoder] = 0;
        	 SensorValue[rightEncoder] = 0;
        	 wait1Msec(1000);
         }
 	  }

    while(limit == 2)
    {
					  if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = 40;
            }

            if(abs(SensorValue[rightEncoder]) < abs(SensorValue[leftEncoder]))
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = -40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
            }
            else if(abs(SensorValue[leftEncoder]) < abs(SensorValue[rightEncoder]))
            {
                motor[leftMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
                motor[rightMotor] = -40;
            }

            if(Turning < abs(SensorValue[leftEncoder]) && Turning < abs(SensorValue[rightEncoder]))
            {
            	  limit = 3;
            	  motor[leftMotor] = 0;
            	  motor[rightMotor] = 0;
            	  SensorValue[leftEncoder] = 0;
                SensorValue[rightEncoder] = 0;

		            distanceToGo = tile*sqrt(2); //Distance the robot needs to go in inches.
		            rotations = distanceToGo/circumference; //Number of rotations the wheels turn to go a certain distance
		            degreesToTurn = rotations*360; //Degrees the wheels must turn in order to go a certain distance

            	  wait1Msec(1000);
            }
  	}

  	while(limit == 3)
    {
    	if(SensorValue[rightEncoder] ==
    		SensorValue[leftEncoder]) //If the sensor values are equal, then all the wheels must be turning equally
        {
            motor[leftMotor] = 40;  //Sets the speed of the left wheels
            motor[rightMotor] = 40; //Sets the speed of the right wheels
        }

        if(SensorValue[rightEncoder] < SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
        {
            motor[leftMotor] = 40; //Sets the speed of the left wheels
            motor[rightMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]-ratio));
            /*The right motor is slowed down so that the left wheels can catch up to the speed of the right wheels
             This is done by finding the absolue value of the cosine of the difference between the left and and right
             encoders. The absolute value of the cosine of any number will always be between 0 and 1. This value will
             be multiplied by the base speed of 40 in order to slow the more powerful motor.
             */
        }
        else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
        {
            motor[leftMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]-ratio)); //Similar function as above
            motor[rightMotor] = 40; //Sets the speed of the right wheels
        }
         //If the number of degrees to turn is less than both the absolute value of the encoder values, the limit will increase so
         //that the while loop it's inside of will stop.

        if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
         {
        	 limit = 4;
        	 motor[rightMotor] = 0;
        	 motor[leftMotor] = 0;
        	 SensorValue[leftEncoder] = 0;
        	 SensorValue[rightEncoder] = 0;
        	 Turning = 300;

        	 wait1Msec(1000);
         }
  	}

  	while(limit == 4)
    {
    				if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = 40;
            }

            if(abs(SensorValue[rightEncoder]) < abs(SensorValue[leftEncoder]))
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = -40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
            }
            else if(abs(SensorValue[leftEncoder]) < abs(SensorValue[rightEncoder]))
            {
                motor[leftMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
                motor[rightMotor] = -40;
            }

            if(Turning < abs(SensorValue[leftEncoder]) && Turning < abs(SensorValue[rightEncoder]))
            {
            	  limit = 5;
            	  motor[leftMotor] = 0;
            	  motor[rightMotor] = 0;
            	  SensorValue[leftEncoder] = 0;
                SensorValue[rightEncoder] = 0;

                distanceToGo = tile*2; //Distance the robot needs to go in inches.
		            rotations = distanceToGo/circumference; //Number of rotations the wheels turn to go a certain distance
		            degreesToTurn = rotations*360; //Degrees the wheels must turn in order to go a certain distance

            	  wait1Msec(1000);
            }
  	}

  	while(limit == 5)
    {
    	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) //If the sensor values are equal, then all the wheels must be turning equally
        {
            motor[leftMotor] = 100;  //Sets the speed of the left wheels
            motor[rightMotor] = 100; //Sets the speed of the right wheels
        }

        if(SensorValue[rightEncoder] < SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
        {
            motor[leftMotor] = 100; //Sets the speed of the left wheels
            motor[rightMotor] = 100*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]-ratio));
            /*The right motor is slowed down so that the left wheels can catch up to the speed of the right wheels
             This is done by finding the absolue value of the cosine of the difference between the left and and right
             encoders. The absolute value of the cosine of any number will always be between 0 and 1. This value will
             be multiplied by the base speed of 40 in order to slow the more powerful motor.
             */
        }
        else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
        {
            motor[leftMotor] = 100*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]-ratio)); //Similar function as above
            motor[rightMotor] = 100; //Sets the speed of the right wheels
        }
         //If the number of degrees to turn is less than both the absolute value of the encoder values, the limit will increase so
         //that the while loop it's inside of will stop.

        if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
         {
        	 limit = 6;
        	 motor[rightMotor] = 0;
        	 motor[leftMotor] = 0;
        	 SensorValue[leftEncoder] = 0;
        	 SensorValue[rightEncoder] = 0;
        	 wait1Msec(1000);
         }
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

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  	while (1 == 1)
	{
	motor[leftMotor] = vexRT(Ch2)*2;
	motor[rightMotor] = vexRT(Ch3)*1;

	if(vexRT[Btn6U] == 1) //WHEN BUTTON 5U IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO 20
	{
		motor[FLift] = -90;
		//motor[LClaw] = -90;
		//motor[RClaw] = 85;
	}

	else if(vexRT[Btn6D] == 1) //WHEN BUTTON 5D IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO -20
	{
		motor[FLift] = 90;
		//motor[LClaw] = 85;
		//motor[RClaw] = -90;
	}
	else
		{
			motor[FLift] = 0;
		//motor[LClaw] = 0;
		//motor[RClaw] = 0;
		}

	}
}
