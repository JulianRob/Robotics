#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop) //Opens and close
#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed) //Right Wheel
#pragma config(Motor,  port5,           LWheel,        tmotorVex393_MC29, openLoop, reversed) //Left Wheel
#pragma config(Motor,  port6,           scissorLift1,  tmotorVex393_MC29, openLoop) //One scissor lift
#pragma config(Motor,  port7,           scissorLift2,  tmotorVex393_MC29, openLoop, reversed) //The other scissor lift.
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop) // Lifts up the claw.
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //Fork Lift

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
  int limit = 0;
	motor[RWheel] = 0;
	motor[LWheel] = 0;
	while(limit == 0) //This turns right.
	{
	 motor[clawGrip] = -50;
	 wait1Msec(1000);
	 limit = 1;
	}

	while(limit == 1)
	{
		motor[RWheel] = -50;
	 	motor[LWheel] = 50;
	 	motor[clawLift] = 90;
		wait1Msec(6200);
		motor[clawLift] = 0;
		motor[clawGrip] = 0;
		motor[RWheel] = 0;
	 	motor[LWheel] = 0;
		wait1Msec(2000);
		limit = 2;
	}

	while(limit == 2)
	{
		motor[clawGrip] = 50;
		motor[RWheel] = 50;
		motor[LWheel] = -50;
		wait1Msec(2000);
		limit = 3;
	}

	while(limit == 3)
	{

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
  while (true)
  {
  	motor[RWheel] = vexRT(Ch2)*-1; //-2?
		motor[LWheel] = vexRT(Ch3)*1;

		if(vexRT[Btn7U] == 1) //WHEN SHOULDER BUTTON 5U IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO 20
		{
			motor[FLift] = -90;
		}

		else if(vexRT[Btn7D] == 1) //WHEN SHOULDER BUTTON 5D IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO -20
		{
			motor[FLift] = 90;
		}
		else
		{
			motor[FLift] = 0;
		}

		if(vexRT[Btn5U] == 1)
		{
			motor[clawLift] = 50;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[clawLift] = -50;
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
			motor[scissorLift1] = 100;
			motor[scissorLift2] = 100;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[scissorLift1] = -100;
			motor[scissorLift2] = -100;
		}
		else
		{
			motor[scissorLift1] = 0;
			motor[scissorLift2] = 0;
		}
  }
}
