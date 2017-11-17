#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LWheel,        tmotorVex393_MC29, openLoop, reversed)

task main()
{
	int limit = 0;
	motor[RWheel] = 0;
	motor[LWheel] = 0;

	while(limit == 0)
	{
		motor[RWheel] = -50;
		motor[LWheel] = 50;
		wait1Msec(1600);
		limit = 1;
	}


}
