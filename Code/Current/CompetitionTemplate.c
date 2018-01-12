#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)           //2 Opens and Closes
#pragma config(Motor,  port3,           RFWheel,       tmotorVex393_MC29, openLoop, reversed) //3 Right Front Wheel
#pragma config(Motor,  port4,           LBWheel,       tmotorVex393_MC29, openLoop)           //4 Left Back Wheel
#pragma config(Motor,  port5,           LFWheel,       tmotorVex393_MC29, openLoop)					  //5 Left Front Wheel
#pragma config(Motor,  port6,           RBWheel,       tmotorVex393_MC29, openLoop, reversed) //6 Right Back Wheel
#pragma config(Motor,  port7,           scissorLift,   tmotorVex393_MC29, openLoop, reversed) //7 Scissorlift
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)           //8 Lifts up the claw
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //9 Fork Lift

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
 	int test = -100;
	float limit = -2; //-2

	motor[RFWheel] = 0;
	motor[RBWheel] = 0;
	motor[LFWheel] = 0;
	motor[LBWheel] = 0;

	while (limit == test)
	{
		//motor[scissorLift] = -65; //lifts scissor lift up
  	motor[FLift] = 50; //Down
		//motor[clawLift] = 50; //arm descends
		//motor[clawGrip] = 50; //claw grip opens
	  //motor[RFWheel] = 100; //moves forward
		//motor[RBWheel] = 100; //moves forward
		//motor[LFWheel] = 50; //moves forward
		//motor[LBWheel] = 50; //moves forward
	}

	while(limit == -2)
	{
		motor[clawLift] = -60; //arm lifts
		motor[clawGrip] = -17; //grips closes
		wait1Msec(500);
		limit = -1;
	}

	while(limit == -1)
	{
		motor[clawLift] = 65; //arm lowers
		motor[clawGrip] = -10; //grip closes
		wait1Msec(1000);
		limit = -0.5;
	}

	while(limit == -0.5)
	{
			motor[clawGrip] = -50;
			wait1Msec(500);
			limit = -0.2;
	}

	while(limit == -0.2)
	{
		motor[clawLift] = -50;
		wait1Msec(500);
		limit = 0;
	}

	while(limit == 0) //This turns right.
	{
	 motor[clawGrip] = -50;
	 motor[clawLift] = 0;
	 limit = 1;
	}

	while(limit == 1)
	{
		motor[RFWheel] = 80; //goes forward
		motor[RBWheel] = 80;
		motor[LFWheel] = 80;
		motor[LBWheel] = 80;

		motor[scissorLift] = 0;

	 	motor[clawLift] = -90;
		wait1Msec(3300); //3046

		motor[RFWheel] = -25;
		motor[RBWheel] = -25;
   	motor[LFWheel] = -25;
  	motor[LBWheel] = -25;
  	wait1Msec(500);

		motor[clawLift] = 0;
		motor[clawGrip] = 0;

		motor[RFWheel] = 0;
		motor[RBWheel] = 0;
   	motor[LFWheel] = 0;
  	motor[LBWheel] = 0;
		limit = 2.1;
	}

	while(limit == 2.1)
	{
		motor[clawGrip] = 45;
		wait1Msec(500);

		motor[clawGrip] = 0;
		motor[scissorLift] = -100;
		wait1Msec(2000);

		motor[scissorLift] = 0;
		motor[RFWheel] = 50;
		motor[RBWheel] = 50;
		motor[LFWheel] = 50;
		motor[LBWheel] = 50;
		wait1Msec(500);

		motor[RFWheel] = 0;
		motor[RBWheel] = 0;
		motor[LFWheel] = 0;
		motor[LBWheel] = 0;
		motor[FLift] = -100;
		wait1Msec(3000);

		motor[FLift] = 0;
		motor[RFWheel] = -80;
		motor[RBWheel] = -80;
   	motor[LFWheel] = -80;
  	motor[LBWheel] = -80;
		wait1Msec(2000);

		motor[RFWheel] = 80;
		motor[RBWheel] = 80;
		motor[LFWheel] = -10;
  	motor[LBWheel] = -10;
  	wait1Msec(3000);

  	motor[RFWheel] = 100;
		motor[RBWheel] = 100;
		motor[LFWheel] = 100;
  	motor[LBWheel] = 100;
		wait1Msec(2000);

		motor[RFWheel] = 0;
		motor[RBWheel] = 0;
		motor[LFWheel] = 0;
  	motor[LBWheel] = 0;
  	motor[FLift] = 100;
  	wait1Msec(3000);

  	motor[FLift] = 0;
  	motor[RFWheel] = -50;
		motor[RBWheel] = -50;
		motor[LFWheel] = -50;
  	motor[LBWheel] = -50;
  	wait1Msec(2000);

  	motor[RFWheel] = 0;
		motor[RBWheel] = 0;
		motor[LFWheel] = 0;
  	motor[LBWheel] = 0;

		limit = 2.2;
  }
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
		motor[RFWheel] = vexRT(Ch2)*1; //-2? lol
		motor[RBWheel] = vexRT(Ch2)*1;

		motor[LFWheel] = vexRT(Ch3)*1;
		motor[LBWheel] = vexRT(Ch3)*1;

		if(vexRT[Btn7U] == 1) //WHEN SHOULDER BUTTON 5U IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO 20
		{
			motor[FLift] = -100;
		}

		else if(vexRT[Btn7D] == 1) //WHEN SHOULDER BUTTON 5D IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO -20
		{
			motor[FLift] = 100;
		}
		else
		{
			motor[FLift] = 0;
		}

		if(vexRT[Btn5D] == 1)
		{
			motor[clawLift] = 80;
		}
		else if(vexRT[Btn5U] == 1)
		{
			motor[clawLift] = -80;
		}
		else
		{
			motor[clawLift] = 0;
		}

		if(vexRT(Btn8R) == 1)
		{
			motor[clawGrip] = 50;
		}
		else if(vexRT(Btn8L) == 1)
		{
			motor[clawGrip]	= -50;
		}
		else
		{
			motor[clawGrip] = 0;
		}

		if(vexRT[Btn6D] == 1)
		{
			motor[scissorLift] = 100;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[scissorLift] = -100;
		}
		else
		{
			motor[scissorLift] = 0;
		}
	}
}
