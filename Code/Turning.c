#pragma config(Motor,  port1,           FRWheel,       tmotorVex393_HBridge, openLoop)

//This turns the robot to the left.
void turnLeft()
{
		motor[FRWheel] = 100; //127 is the highest speed.
		wait1Msec(1300);
}

//This turns the robot to the right.
void turnRight()
{
		motor[FRWheel] = -100; //127 is the highest speed.
		wait1Msec(1300);
}

task main()
{
	int x = 0;
	if(x == 0)
	{
		//We should get a jyro for turning for more consistency
		turnLeft();
		turnRight();
		x+=1;
	}

}
