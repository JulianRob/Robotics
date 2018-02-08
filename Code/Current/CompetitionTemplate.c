#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RScissorLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LScissorLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LWheel,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//left front and left back are now port 7 (OK)
//left scissorlift is port 4 and right scissor lift is port 5. (OK)
//right front and right back are now in 6 (3 and 6 are in 3) (OK)

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
 	int run = true;

	while(run == true)
	{
		motor[clawGrip]	= -20; //closes
		motor[clawLift] = 50; //lowers the arm
		wait1Msec(1000);

		motor[clawGrip]	= -50; //closes
		motor[clawLift] = -80; //lifts the arm
		motor[RScissorLift] = 100; //lifts scissor lift
		motor[LScissorLift] = 100; //lifts scissor lift
		wait1Msec(2500);

		motor[RScissorLift] = 0;
		motor[LScissorLift] = 0;
		motor[RWheel] = 40;
		motor[LWheel] = 40;
		wait1Msec(2000);

		motor[RWheel] = 0;
		motor[LWheel] = 0;
		motor[clawLift] = 50; //lowers the arm
		wait1Msec(1000);

		motor[clawGrip]	= 60; //opens
		motor[clawLift] = 0;
		wait1Msec(400);

		motor[clawGrip] = 0;
		motor[RWheel] = -50;
		motor[LWheel] = -50;
		wait1Msec(1000);

		motor[RWheel] = 0;
		motor[LWheel] = 0;
		motor[clawGrip]	= -30;
		wait1Msec(1000);

		motor[LScissorLift] = -100;
		motor[RScissorLift] = -100;
		motor[clawLift] = 50;
		wait1Msec(2500);

		motor[LScissorLift] = 0;
		motor[RScissorLift] = 0;
		motor[clawLift] = 0;
		motor[clawGrip]	= 80;
		wait1Msec(500);

		motor[clawGrip]	= 0;
		motor[RWheel] = 50;
		motor[LWheel] = 0;
		wait1Msec(2000);

		motor[RWheel] = 50;
		motor[LWheel] = 50;
		wait1Msec(1500);

		motor[RWheel] = 0;
		motor[LWheel] = 0;
		motor[clawGrip]	= -80;
		wait1Msec(700);

		motor[clawGrip]	= 0;

		run = false;
	}

	while(run == false)
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
  while (1 == 1)
	{
		motor[RWheel] = vexRT(Ch2)*1;

		motor[LWheel] = vexRT(Ch3)*1;

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

		if(vexRT(Btn8R) == 1) //opens
		{
			motor[clawGrip] = 50;
		}
		else if(vexRT(Btn8L) == 1) //closes
		{
			motor[clawGrip]	= -50;
		}
		else
		{
			motor[clawGrip] = 0;
		}

		if(vexRT[Btn6U] == 1)
		{
			motor[LScissorLift] = 100;
			motor[RScissorLift] = 100;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[LScissorLift] = -100;
			motor[RScissorLift] = -100;
		}
		else
		{
			motor[LScissorLift] = 0;
			motor[RScissorLift] = 0;
		}
	}
}
