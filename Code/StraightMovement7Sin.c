#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)

float test = 5;

task main()
{
	int limit = 0;
	float tile = 23.25;
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	float diameterOfWheel = 4.25; //inches
  float circumference = diameterOfWheel*PI;

  float distanceToGo = tile*1; //inches

  float rotations = distanceToGo/circumference;
  float degreesToTurn = rotations*360; //Degrees to turn to go distance.
	while(limit==0)
	{
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder])
		{
			motor[leftMotor] = 40;
			motor[rightMotor] = 40;
		}
		if(SensorValue[rightEncoder] < SensorValue[leftEncoder])
			{
				motor[leftMotor] = 40;
				motor[rightMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
		//	int difference = SensorValue[rightEncoder] - SensorValue[leftEncoder]; //Degreees
		//	motor[leftMotor] += difference;
			}
		else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
			{
				motor[leftMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
				motor[rightMotor] = 40;

		//	int difference = SensorValue[leftEncoder] - SensorValue[rightEncoder];
		//	motor[rightMotor] += difference;

			}
		// test = (SensorValue[rightEncoder]-SensorValue[leftEncoder]);

			if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
			{
				limit+=1;
			}
	}
}
//30 and 50 = 10/10
//40 and 50 = bad
//20 and 50 = bad, jittery
//20 and 40 = 7/10 good but slow
//50 and 70 = bad, moving to side
//70 and 60 = bad
//70 and 40 = good, but moving to side
//70 and 20 = good, but jittery
//90 and 20 = good, but jittery
//100 and 20 = very fast and good, but jittery
//100 and 80 = very bad, too fast, moving to left side
