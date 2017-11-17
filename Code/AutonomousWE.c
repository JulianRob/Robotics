#pragma config(Motor,  port3,           RWheel,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LWheel,        tmotorVex393_MC29, openLoop, reversed)

task main()
{
	int limit = 0;
	motor[RWheel] = 0;
	motor[LWheel] = 0;

	while(limit == 0) //This goes straight.
	{
		motor[RWheel] = 50;
		motor[LWheel] = 50;
		wait1Msec(1700);
		limit = 1;
	}

	while(limit == 1)
	{
			motor[RWheel] = -50;
			motor[LWheel] = 60;
			wait1Msec(4000);
			limit = 2;
	}

	while (limit == 2)
	{
		motor[RWheel] = -50;
		motor[LWheel] = -50;
		wait1Msec(450);
		limit = 3;
	}

	while(limit == 3)
	{
		motor[RWheel] = -50;
		motor[LWheel] = 50;
		wait1Msec(3000);
		limit = 4;
	}

	while(limit == 4)
	{
		motor[RWheel] = 0;
		motor[LWheel] = 0;
	}
}
