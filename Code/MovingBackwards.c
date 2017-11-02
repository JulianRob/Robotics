#pragma config(Sensor, dgtl1,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightMotor,    tmotorVex393_MC29, openLoop, reversed)

task main()
{

	  SensorValue[leftEncoder] = 0; //The leftEncoder keeps track of the degrees turned by the wheels of the leftMotor
    SensorValue[rightEncoder] = 0;//The rightEncoder keeps track of the degrees turned by the wheels of the rightMotor
    //Sets the encoders to their default value of 0.

    int limit = 1; //Stops the while loop when the robot moves a certain distance

    //Data gathered from measured values
    float diameterOfWheel = 4.25; //Diameter of each wheel in inches
    float tile = 23.25; //Length of each tile in inches on the field

    //Applications of the measured values
    float distanceToGo = tile*2; //Distance the robot needs to go in inches.
    float circumference = diameterOfWheel*PI; //Finds the circumference of each wheel in inches
    float rotations = distanceToGo/circumference; //Number of rotations the wheels turn to go a certain distance
    float degreesToTurn = rotations*360; //Degrees the wheels must turn in order to go a certain distance

	while(limit == 1) //Loop will run continuously until the value of the limit changes like before.
    {
    	if(SensorValue[rightEncoder] == SensorValue[leftEncoder]) //If the sensor values are equal, then all the wheels must be turning equally
        {
            motor[leftMotor] = -40;  //Sets the speed of the left wheels
            motor[rightMotor] = -40; //Sets the speed of the right wheels
        }

        if(SensorValue[rightEncoder] > SensorValue[leftEncoder]) //If the the right wheels turn slower than the left wheels
        {
            motor[leftMotor] = -40; //Sets the speed of the left wheels
            motor[rightMotor] = -40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]+43)); //-43
            /*The right motor is slowed down so that the left wheels can catch up to the speed of the right wheels
             This is done by finding the absolue value of the cosine of the difference between the left and and right
             encoders. The absolute value of the cosine of any number will always be between 0 and 1. This value will
             be multiplied by the base speed of 40 in order to slow the more powerful motor.
             */
        }
        else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
        {
            motor[leftMotor] = -40*abs(cosDegrees(SensorValue[rightEncoder]-SensorValue[leftEncoder]+43)); //Similar function as above //-43
            motor[rightMotor] = -40; //Sets the speed of the right wheels
        }
         //If the number of degrees to turn is less than both the absolute value of the encoder values, the limit will increase so
         //that the while loop it's inside of will stop.

        if(degreesToTurn < abs(SensorValue[leftEncoder]) && degreesToTurn < abs(SensorValue[rightEncoder]))
         {
        	 limit = 2;
        	 motor[rightMotor] = 0;
        	 motor[leftMotor] = 0;
        	 wait1Msec(3000);
         }
 	  }
}
