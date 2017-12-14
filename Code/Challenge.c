#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)           //2 Opens and Closes
#pragma config(Motor,  port3,           RFWheel,       tmotorVex393_MC29, openLoop, reversed) //3 Right Front Wheel
#pragma config(Motor,  port4,           LBWheel,       tmotorVex393_MC29, openLoop)           //4 Left Back Wheel
#pragma config(Motor,  port5,           LFWheel,       tmotorVex393_MC29, openLoop, reversed) //5 Left Front Wheel
#pragma config(Motor,  port6,           RBWheel,       tmotorVex393_MC29, openLoop)           //6 Right Back Wheel
#pragma config(Motor,  port7,           scissorLift,   tmotorVex393_MC29, openLoop, reversed) //7 Scissorlift
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)					  //8 Lifts up the claw
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //9 Fork Lift

task main()
{

//clawGrip > 0 opens up the claw.
//RFWheel > 0 moves backwards
//LBWheel > 0 moves forward
//LFWHeel > 0 moves forward
//RBWheel > 0 moves backwards

//Plan for moving the robot around.

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
		motor[clawLift] = -60;
		motor[clawGrip] = 10;
		wait1Msec(500);
		limit = 0;
	}

	while(limit == 0) //This turns right.
	{
	 motor[clawGrip] = -50;
	 motor[scissorLift] = -50;
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
