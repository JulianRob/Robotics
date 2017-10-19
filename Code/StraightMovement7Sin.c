#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)


task main()
{

	float tile = 23.5 //In inches
	int limit = 0;

	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	float diameterOfWheel = 4.25; //inches
  float circumference = diameterOfWheel*PI;

  float distanceToGo = tile*(1); //number of tile lengths to go

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

			if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn > abs(SensorValue[rightEncoder])) //This allows it to move a certain distance.
			{
				limit = 1;
			}

	}
}
