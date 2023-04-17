#include <reg51.h>
#include "sensor.h"
#include "control.h"

void main() {
	while(1) {
		if(!space_left()) {
			right();
		}
		else {
			stop();
		}
	}
}