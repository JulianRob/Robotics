#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)

int limit = 0;

task main()
{
    SensorValue[leftEncoder] = 0; //The leftEncoder keeps track of the degrees turned by the wheels of the leftMotor
    SensorValue[rightEncoder] = 0;//The rightEncoder keeps track of the degrees turned by the wheels of the rightMotor
    int Turning = 500;

	while(limit == 0)
	{
		 if(Turning < abs(SensorValue[leftEncoder]) && Turning < abs(SensorValue[rightEncoder]))
            {
            	  limit = 1;
            	  motor[leftMotor] = 0;
            	  motor[rightMotor] = 0;
            	  wait1Msec(5000);
            }

			 if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = 40;
            }

            if(abs(SensorValue[rightEncoder]) < abs(SensorValue[leftEncoder]))
            {
                motor[leftMotor] = 40;
                motor[rightMotor] = -40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
            }
            else if(abs(SensorValue[leftEncoder]) < abs(SensorValue[rightEncoder]))
            {
                motor[leftMotor] = 40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]));
                motor[rightMotor] = -40;
            }
	}
}
