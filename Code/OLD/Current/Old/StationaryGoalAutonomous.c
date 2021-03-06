#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)           //2 Opens and Closes
#pragma config(Motor,  port3,           RFWheel,       tmotorVex393_MC29, openLoop, reversed) //3 Right Front Wheel
#pragma config(Motor,  port4,           LBWheel,       tmotorVex393_MC29, openLoop)           //4 Left Back Wheel
#pragma config(Motor,  port5,           LFWheel,       tmotorVex393_MC29, openLoop)					  //5 Left Front Wheel
#pragma config(Motor,  port6,           RBWheel,       tmotorVex393_MC29, openLoop, reversed) //6 Right Back Wheel
#pragma config(Motor,  port7,           scissorLift,   tmotorVex393_MC29, openLoop, reversed) //7 Scissorlift
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)           //8 Lifts up the claw
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //9 Fork Lift


task main()
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
		motor[scissorLift] = -65;
		wait1Msec(2000);

		motor[scissorLift] = 0;
		motor[RFWheel] = 50; //goes forward
		motor[RBWheel] = 50;
		motor[LFWheel] = 50;
		motor[LBWheel] = 50;
		wait1Msec(1000);

		motor[clawGrip] = 50;
		motor[RFWheel] = 0; //goes forward
		motor[RBWheel] = 0;
		motor[LFWheel] = 0;
		motor[LBWheel] = 0;
		wait1Msec(20000);
	}
}
