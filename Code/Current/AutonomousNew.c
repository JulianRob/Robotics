#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           RScissorLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LScissorLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LWheel,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed)


		//motor[scissorLift] = -65; //lifts scissor lift up
    //motor[FLift] = 100; //Down
		//motor[clawLift] = 50; //arm descends
		//motor[clawGrip] = 50; //claw grip opens
	  //motor[RFWheel] = 100; //moves forward
		//motor[RBWheel] = 100; //moves forward
		//motor[LFWheel] = 50; //moves forward

//8L closes

//motor[LScissorLift] = 100; //lifts scissor lift
//motor[RScissorLift] = 100; //lifts scissor lift

task main()
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
