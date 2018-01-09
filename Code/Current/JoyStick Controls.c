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
	while (1 == 1)
	{
		motor[RFWheel] = vexRT(Ch2)*1; //-2? lol
		motor[RBWheel] = vexRT(Ch2)*1;

		motor[LFWheel] = vexRT(Ch3)*1;
		motor[LBWheel] = vexRT(Ch3)*1;

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
			motor[clawLift] = 80;
		}
		else if(vexRT[Btn5D] == 1)
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
