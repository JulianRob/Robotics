#pragma config(Motor,  port1,           RWheel,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port10,          LWheel,       tmotorVex393_HBridge, openLoop)

//This turns the robot to the left.
void turnLeft()
{
		motor[RWheel] = 100;
		wait1Msec(1300);
}

//This turns the robot to the right.
void turnRight()
{
		motor[RWheel] = -100;
		wait1Msec(1300);
}

//The robot moves forward
void moveForward()
{
	motor[RWheel] = 100;
	motor[LWheel] = -100;
	wait1Msec(400);
}

//The robot moves back
void moveBack()
{
	motor[RWheel] = -100;
	motor[LWheel] = 100;
	wait1Msec(400);
}

/* NOTES
****************************************
//127 is the highest speed.
//We should get a jyro for turning for more turning consistency.
****************************************
*/
task main()
{
	int x = 0;
	while(x == 0)
	{
		moveBack();
		x+=1;
	}

}
