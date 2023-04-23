#include <reg51.h>
#include "sensor.h"
#include "control.h"

void main()
{
	while (1)
	{
		if(space_front()) stop();
		else {
			if(!space_right()) {
				right();
				delay(100000);
				delay(100000);
				delay(15000);
				stop();
				delay(100000);
				delay(100000);
				delay(8000);
				straight();
				while(!space_right());
			}
			else {
				straight();
			}
		}
	}
} // 1019