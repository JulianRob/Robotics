#pragma config(Motor,  port2,           clawGrip,      tmotorVex393_MC29, openLoop) //Opens and closes the claw.
#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed) //Right wheel driving
#pragma config(Motor,  port5,           LWheel,        tmotorVex393_MC29, openLoop, reversed) //Left wheel driving
#pragma config(Motor,  port6,           scissorLift1,  tmotorVex393_MC29, openLoop) //Scissorlift rises or descends
#pragma config(Motor,  port7,           scissorLift2,  tmotorVex393_MC29, openLoop, reversed) //ScissorLift rises or descends.
#pragma config(Motor,  port8,           clawLift,      tmotorVex393_MC29, openLoop) //Lifts up the claw
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //Lifts the lift

task main()
{
	while(1 == 1)
	{
		//Joystick #1: Movement and Lift(ports 3, 5, 9)

			//port 3
			motor[RWheel] = vexRT(Ch2)*-1;

			//port 5
			motor[LWheel] = vexRT(Ch3)*1;

			//port 9
			if(vexRT[Btn7U] == 1)
			{
				motor[FLift] = -90;
			}

			else if(vexRT[Btn7D] == 1)
			{
				motor[FLift] = 90;
			}
			else
			{
				motor[FLift] = 0;
			}

		//Joystick #2: Claw and ScissorLift (ports 2, 6, 7, 8)

			//port 8
			if(vexRT[Btn5UXmtr2] == 1)
			{
				motor[clawLift] = 50;
			}
			else if(vexRT[Btn5DXmtr2] == 1)
			{
				motor[clawLift] = -50;
			}
			else
			{
				motor[clawLift] = 0;
			}

			//port 2
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

			//port 6 and port 7
			if(vexRT[Btn6DXmtr2] == 1)
			{
				motor[scissorLift1] = 100;
				motor[scissorLift2] = 100;
			}
			else if(vexRT[Btn6UXmtr2] == 1)
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

/*
//Main VEXNet Joystick Controller
motor[rightMotor]  = vexRT[Ch1];

//Partner VEXNet Joystick Controller
motor[rightMotor] = vexRT[Ch1Xmtr2];
*/
