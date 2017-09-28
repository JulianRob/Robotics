#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           rightMotor,    tmotorServoContinuousRotation, openLoop)

task main()
{
	//find the circumference of the wheel
	float diameterOfWheel = 4.25; //inches
	float circumference = diameterOfWheel*PI; //inches

	//Find how many times we must rotate the wheel
	//to go into the total distance we want to go
	int distanceToGo = 12; //inches
	float rotations = distanceToGo/circumference;
	int degreesToTurn = rotations*360;

	//start your motor encoder counts at 0
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;
	//tell the motor how many encoder counts/degrees to turn
	nMotorEncoderTarget[leftMotor] = degreesToTurn;
	nMotorEncoderTarget[rightMotor] = degreesToTurn;
	motor[leftMotor] = 100; //turns the motors on
	motor[rightMotor] = 100;

	//now we need to check when motorB is finished
	while(nMotorRunState[leftMotor] != runStateIdle &&
				nMotorRunState[rightMotor] != runStateIdle)
	{
			//do nothing else here while we wait.
	}

	motor[leftMotor] = 0; //turn the motors off
	motor[rightMotor] = 0;

}
