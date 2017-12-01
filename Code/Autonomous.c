#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop) //Opens and close
#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed) //Right Wheel
#pragma config(Motor,  port5,           LWheel,        tmotorVex393_MC29, openLoop, reversed) //Left Wheel
#pragma config(Motor,  port6,           scissorLift1,  tmotorVex393_MC29, openLoop) //One scissor lift
#pragma config(Motor,  port7,           scissorLift2,  tmotorVex393_MC29, openLoop, reversed) //The other scissor lift.
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop) // Lifts up the claw.
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //Fork Lift

task main()
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
}
