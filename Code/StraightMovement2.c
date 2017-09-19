
task main()
{
	// Find how many times we must rotate the wheel to go into the the total distance we want to go

	int distanceToGo = 12; //We need to know how far we want the robot to go.
	float rotations = distanceToGo/circumference;
	int degreesToTurn = rotations*360;

	//start your motor encoder counts at 0
	nMotorEncoder[moterB] = 0;
	// tell the motor how many encoder counts/degrees to turn
	nMotorEncoderTarget[motorB] = degrees;
	motor[motorB] = 100; //turn the motors on
	motor[motorC] = 100;

	// now we need to chekc when motorB is finished
	while (nMotorRunState[motorB] != runStateIdle)
	{
		//do nothing here while we wait
	}

}
