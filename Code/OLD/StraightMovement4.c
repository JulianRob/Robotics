#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           rightMotor,    tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
This is a test of the optical shaft encoder from VEX robotics.
In this test, we are demonstrating the use of two optical shaft encoders to allow
A simple robot to move forward in a straight line. The way this works is by ensuring that
each motor is moving at precisely the same RPM (rotations per minute).
*/

task main()
{
	wait1Msec(500); //Robot waits for 500 milliseconds before executing program
	int moveQuantity = 80;
	SensorValue[rightEncoder] = 0; //Set the encoder so that it starts counting at 0
	SensorValue[leftEncoder] = 0; //Set the encoder so that it starts counting at 0

	int distanceToGo = 12; //12 inches

	while(true) //Creates an infinite loop, since "true" always evaluates to true
	{
		if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			//Move Forwawrd v
		  motor[rightMotor] = moveQuantity; //Right Motor is run at power level 80
		  motor[leftMotor] = moveQuantity; //Left Motor is run at power level 80
		}
		else if(SensorValue[rightEncoder] < SensorValue[leftEncoder]) //If rightEncoder has counted more encoder counts
		{
			//Turn slightly motor
			motor[rightMotor] = moveQuantity; //Right Motor is run at power level 80
			motor[leftMotor] = moveQuantity; //Left Motor is run at power level 60
		}
		else //Only runs if leftEncoder has counted more encoder counts
		{
			//Turns slightly left
			motor[rightMotor] = moveQuantity;	//Right Motor is run at power level 60
			motor[leftMotor] = moveQuantity; //Left Motor is run at power level 80
		}
		SensorValue[rightEncoder] = 0;
 		SensorValue[leftEncoder] = 0;
	}
}