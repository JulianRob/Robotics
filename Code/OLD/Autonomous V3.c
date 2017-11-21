#pragma config(Sensor, dgtl7,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl10, leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port3,           rightMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftMotor,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RClaw,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           FLift,         tmotorVex393_MC29, openLoop, reversed) //Should not be reversed?

task main()
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	int limit = 0;

	float diameterOfWheel = 4.25; //inches
	float tile = 23.25;

	float distanceToGo = tile*0.5; //inches
  float circumference = diameterOfWheel*PI;
  float rotations = distanceToGo/circumference;
  float degreesToTurn = rotations*360; //Degrees to turn to go distance.

	while(limit == 0)
	{
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{
			motor[leftMotor] = 50;
			motor[rightMotor] = 50;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
			{
				motor[leftMotor] = 50;
				motor[rightMotor] = 30;
			}
		else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
			{
				motor[leftMotor] = 30;
				motor[rightMotor] = 50;
			}

			if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
			{
				limit = 1;
				motor[rightMotor] = 0;
				motor[leftMotor] = 0;
				SensorValue[leftEncoder] = 0;
				SensorValue[rightEncoder] = 0;
				wait1Msec(1000);
			}
	}

	while(limit == 1)
	{
		motor[leftMotor] = 50;
		motor[rightMotor] = -50;

		if(SensorValue[rightEncoder] > 400)
		{
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			limit = 2;

			wait1Msec(1000);
		}
	}

	while(limit == 2)
	{
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{
			motor[leftMotor] = 50;
			motor[rightMotor] = 50;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
			{
				motor[leftMotor] = 50;
				motor[rightMotor] = 30;
			}
		else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
			{
				motor[leftMotor] = 30;
				motor[rightMotor] = 50;
			}

			if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
			{
				limit = 3;
				motor[rightMotor] = 0;
				motor[leftMotor] = 0;
				SensorValue[leftEncoder] = 0;
				SensorValue[rightEncoder] = 0;
				wait1Msec(1000);
			}
	}

	while(limit == 3)
	{
		motor[leftMotor] = -50;
		motor[rightMotor] = 50;

		if(SensorValue[rightEncoder] < -250)
		{
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
		  SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			limit = 4;
		}
	}
}
