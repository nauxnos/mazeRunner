		#include <reg51.h>
		#include <sensor.h>

		sbit left_1 = P0^4;
		sbit left_2 = P0^3;
		sbit right_1 = P0^2;
		sbit right_2 = P0^1;
		sbit enable_left = P0^5;
		sbit enable_right = P0^0;

		void speed() 
		{
				enable_right = 1;
				enable_left = 1;
		}

		void straight()
		{
				left_1 = 1;
				left_2 = 0;
				right_1 = 0;
				right_2 = 1;
		}

		void left()
		{
				left_1 = 1;
				left_2 = 0;
				right_1 = 1;
				right_2 = 0;
		}

		void right()
			{
				left_1 = 0;
				left_2 = 1;
				right_1 = 0;
				right_2 = 1;
		}

		void stop()
		{
				left_1 = 1;
				left_2 = 1;
				right_1 = 1;
				right_2 = 1;
		}

		void back() 
		{
				left_1 = 0;
				left_2 = 1;
				right_1 = 1;
				right_2 = 0;
		}

		/*void turn_around()
		{
				right();
				right();
		}*/	

		void fix_dis() 
		{
				left_1 = 1;
				left_2 = 0;
				right_1 = 0;
				right_2 = 1;
				if (dis_right() > 18) 
					{
						enable_left = 1;
						enable_right = 0;
						delay(800);
						enable_right = 1;
						delay(200);
					}
				else if (dis_right() < 12)
					{
						enable_right = 1;
						enable_left = 0;
						delay(800);
						enable_left = 1;
						delay(200);
					}
				else 
					{
						enable_right = 1;
						enable_left = 1;
					}
		}