#pragma config(Motor,  port7,           LWheel,  			 tmotorVex393_MC29, openLoop) 					//7 Left wheels
#pragma config(Motor,  port6,           RWheel,        tmotorVex393_MC29, openLoop)           //3 Right Wheels

task main()
{

	while (1==1)
	{
		motor[RWheel] = vexRT(Ch3)*1;
		motor[LWheel] = vexRT(Ch2)*1;
	}

}
