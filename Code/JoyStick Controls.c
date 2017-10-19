;
		motor[RClaw] = 90;
	}

	else if(vexRT[Btn6D] == 1) //WHEN BUTTON 5D IS PUSHED, THEN THE LEFT CLAW MOTOR WILL BE SET TO -20
	{
		motor[RClaw] = -90;
		motor[LClaw] = 85;
	}
	else
		{
		motor[RClaw] = 0;
		motor[LClaw] = 0;

	}

	}
}
