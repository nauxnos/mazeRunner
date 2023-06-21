#include <reg51.h>
#include "sensor.h"
#include "control.h"
// #include "PWM.h"

sbit led_left = P2 ^ 7;
sbit led_front = P2 ^ 6;
sbit led_right = P2 ^ 5;

void main()
{
	while (1)
	{
		speed();
		if (space_front())
			stop();
		if (!space_right())
		{
			led_left = 0;
			led_front = 0;
			led_right = 1;
			stop();
			delay(1000);
			right();
			delay(123000);
			stop();
			delay(10000);
			while (!space_right() && !space_front())
				straight();
		}
		else if (!space_front())
		{
			led_left = 0;
			led_front = 1;
			led_right = 0;
			straight();
		}
		else if (!space_left())
		{
			led_left = 1;
			led_front = 0;
			led_right = 0;
			stop();
			delay(1000);
			left();
			delay(119000);
			stop();
			delay(10000);
			while (!space_left() && !space_front())
				straight();
			// delay(15000);
		}
		else
		{
			led_left = 0;
			led_front = 0;
			led_right = 0;
			stop();
			delay(1000);
			if (dis_left() > dis_right())
			{
				left();
				delay(119000);
			}
			else
			{
				right();
				delay(123000);
			}
			stop();
		};
		delay(10000);
	}
}
