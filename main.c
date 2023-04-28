#include <reg51.h>
#include "sensor.h"
#include "control.h"
//#include "PWM.h"

sbit led_left = P2^7;
sbit led_front = P2^6;
sbit led_right = P2^5;

void main() {
	while(1){
		if (space_front()) stop();
		if (!space_right()) {
			led_right = 1;
			led_left = 0;
			led_front = 0;
			stop();
			delay(1000);
			right();
			delay(100000);
			delay(100000);
			stop();
			delay(10000);
			straight();
			while(!space_right() && !space_front());
		}
		else if (!space_front()) {
			led_right = 0;
			led_left = 0;
			led_front = 1;
			straight();
			fix_dis();
		}
		else if (!space_left()) {
			led_right = 0;
			led_left = 1;
			led_front = 0;
			stop();
			delay(1000);
			left();
			delay(100000);
			delay(100000);
			stop();
			delay(10000);
			straight();
			while(!space_left() && !space_front());
		}
		else {
			stop();
		}
	}
}

/*if (space_front) stop();
		if (!space_right()) {
			stop();
			delay(1000);
			right();
			delay(100000);
			delay(100000);
			delay(50000);
			stop();
			delay(100000);
			straight();
			while(!space_right() && !space_front());
		}
		else if (!space_front()) {
			straight();
			fix_dis();
		}
		else if (!space_left()) {
			stop();
			delay(1000);
			left();
			delay(100000);
			delay(100000);
			delay(50000);
			stop();
			delay(100000);
			straight();
			while(!space_left() && !space_front());
		}
		else {
			stop();
		}*/

