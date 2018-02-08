#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)           //2 Opens and Closes
#pragma config(Motor,  port3,           RFWheel,       tmotorVex393_MC29, openLoop, reversed) //3 Right Front Wheel
#pragma config(Motor,  port4,           LBWheel,       tmotorVex393_MC29, openLoop)           //4 Left Back Wheel
#pragma config(Motor,  port5,           LFWheel,       tmotorVex393_MC29, openLoop, reversed) //5 Left Front Wheel
#pragma config(Motor,  port6,           RBWheel,       tmotorVex393_MC29, openLoop)           //6 Right Back Wheel
#pragma config(Motor,  port7,           scissorLift,   tmotorVex393_MC29, openLoop, reversed) //7 Scissorlift
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)					  //8 Lifts up the claw
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
  int limit = -2;

	motor[RFWheel] = 0;
	motor[RBWheel] = 0;
	motor[LFWheel] = 0;
	motor[LBWheel] = 0;

	while(limit == -2)
	{
		motor[clawLift] = 60;
		motor[clawGrip] = 10;
		wait1Msec(500);
		limit = -1;
	}

	while(limit == -1)
	{
		motor[clawLift] = -50;
		motor[clawGrip] = 10;
		wait1Msec(500);
		limit = 0;
	}

	while(limit == 0) //This turns right.
	{
	 motor[clawGrip] = -50;
	 motor[scissorLift] = -70;
	 motor[clawLift] = 0;
	 wait1Msec(1000);
	 limit = 1;
	}

	while(limit == 1)
	{
		motor[RFWheel] = -50;
		motor[RBWheel] = -50;
		motor[LFWheel] = 50;
		motor[LBWheel] = 50;

		motor[scissorLift] = 0;

	 	motor[clawLift] = 90;
		wait1Msec(5000);

		motor[RFWheel] = 30;
		motor[RBWheel] = 30;
   	motor[LFWheel] = -30;
  	motor[LBWheel] = -30;
  	wait1Msec(100);

		motor[clawLift] = 0;
		motor[clawGrip] = 0;

		motor[RFWheel] = 0;
		motor[RBWheel] = 0;
   	motor[LFWheel] = 0;
  	motor[LBWheel] = 0;

		wait1Msec(2000);
		limit = 2;
	}

	while(limit == 2)
	{
		motor[clawGrip] = 50;

		motor[RFWheel] = 50;
   	motor[RBWheel] = 50;
  	motor[LFWheel] = -50;
  	motor[LBWheel] = -50;
		wait1Msec(2000);
		limit = 3;
	}

	while(limit == 3)
	{
		motor[RFWheel] = 0;
		motor[RBWheel] = 0;
   	motor[LFWheel] = 0;
  	motor[LBWheel] = 0;
  	motor[clawGrip] = 0;
  	motor[clawLift] = 0;
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
		//Joystick #1: Movement and Lift(ports 3, 4, 5, 6, 9)

		motor[RFWheel] = vexRT(Ch2)*-1;
		motor[RBWheel] = vexRT(Ch2)*-1;

		motor[LFWheel] = vexRT(Ch3)*1;
		motor[LBWheel] = vexRT(Ch3)*1;

		if(vexRT[Btn5U] == 1) //WHEN SHOULDER BUTTON 5U IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO 20
		{
			motor[FLift] = -90;
		}

		else if(vexRT[Btn5D] == 1) //WHEN SHOULDER BUTTON 5D IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO -20
		{
			motor[FLift] = 90;
		}
		else
		{
			motor[FLift] = 0;
		}

		//Joystick #2: Claw and ScissorLift (ports 2, 6, 7, 8)

		if(vexRT[Btn5UXmtr2] == 1)
		{
			motor[clawLift] = 80;
		}
		else if(vexRT[Btn5DXmtr2] == 1)
		{
			motor[clawLift] = -80;
		}
		else
		{
			motor[clawLift] = 0;
		}

		if(vexRT(Btn8RXmtr2) == 1)
		{
			motor[clawGrip] = 50;
		}
		else if(vexRT(Btn8LXmtr2) == 1)
		{
			motor[clawGrip]	= -50;
		}
		else
		{
			motor[clawGrip] = 0;
		}

		if(vexRT[Btn6DXmtr2] == 1) //down
		{
			motor[scissorLift] = 100;
		}
		else if(vexRT[Btn6UXmtr2] == 1) //up
		{
			motor[scissorLift] = -100;
		}
		else
		{
			motor[scissorLift] = 0;
		}
	}
}
