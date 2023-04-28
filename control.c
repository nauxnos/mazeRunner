#include <reg51.h>
#include <sensor.h>

sbit left_1 = P1^0;
sbit left_2 = P1^1;
sbit right_1 = P1^2;
sbit right_2 = P1^3;
sbit enable_left = P1^6;
sbit enable_right = P1^7;


void straight()
{
		enable_right = 1;
		enable_left = 1;
    left_1 = 0;
    left_2 = 1;
    right_1 = 1;
    right_2 = 0;
}

void left()
{
		enable_right = 1;
		enable_left = 1;
    left_1 = 1;
    left_2 = 0;
    right_1 = 1;
    right_2 = 0;
    // delay(10000);
}

void right()
	{
		enable_right = 1;
		enable_left = 1;
    left_1 = 0;
    left_2 = 1;
    right_1 = 0;
    right_2 = 1;
    //delay(10000);
}

void stop()
{
    left_1 = 1;
    left_2 = 1;
    right_1 = 1;
    right_2 = 1;
}

/*void turn_around()
{
    right();
    right();
}*/	

void fix_dis() 
{
		if (dis_right() < 10) 
			{
				enable_right = 1;
				enable_left = 1;
				delay(8000);
				enable_left = 0;
				delay(5000);
			}
		else if (dis_right() > 10)
			{
				enable_left = 1;
				enable_right = 1;
				delay(8000);
				enable_right = 0;
				delay(5000);
			}
		else 
			{
				enable_right = 1;
				enable_left = 1;
			}
}