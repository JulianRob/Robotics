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
  	motor[FLift] = 100; //Down
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
		wait1Msec(1000); //Change time for lowering (used to be 3000)

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
  	wait1Msec(1000); //Change time for lowering (used to be 3000)

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
/* GOAL

Life up the claw
Move the robot forward.
Drop the yellow cone onto the colored cone
Pick up the colored cone.
Move backwards
Make a 360 degree turn
Move forwards until bars are reached
Lower the lift
Move backwards.

*/
