#include <reg51.h>
#include "sensor.h"
#include "control.h"

void main()
{
	while (1)
	{
		if (!space_right())
		{
			right();
			straight();
		}
		else
		{
			if (!space_front)
			{
				straight();
			}
			else
			{
				if (!space_left)
				{
					left();
					straight();
				}
				else
				{
					turn_around();
				}
			}
		}
	}
} // 992