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
  	motor[leftMotor] = 50;
  	motor[rightMotor] = -50;

  	if(SensorValue[rightEncoder] > 300 && SensorValue[leftEncoder] < -220)
  	{
  		motor[leftMotor] = 0;
  		motor[rightMotor] = 0;
  		SensorValue[leftEncoder] = 0;
     	SensorValue[rightEncoder] = 0;
  		limit = 1;
  	}
	}

	while(limit == 1)
	{
		motor[leftMotor] = 40;
		motor[rightMotor] = 66;

		if(SensorValue[rightEncoder] > 1550 && SensorValue[leftEncoder] > 1146)
		{
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			limit = 2;
		}
	}

	while(limit == 2)
	{
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{
			motor[leftMotor] = -50;
			motor[rightMotor] = -50;
		}
		else if(SensorValue[rightEncoder] > SensorValue[leftEncoder])
			{
				motor[leftMotor] = -50;
				motor[rightMotor] = -30;
			}
		else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
			{
				motor[leftMotor] = -30;
				motor[rightMotor] = -50;
			}

		if(SensorValue[leftEncoder] < -1127 && SensorValue[rightEncoder] < -1117)
		{
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
			SensorValue[leftEncoder] = 0;
			SensorValue[rightEncoder] = 0;
			limit = 3;
		}

	}
}

//300 and -220
