#include <reg51.h>

sbit left_1 = P1^0;
sbit left_2 = P1^1;
sbit right_1 = P1^2;
sbit right_2 = P1^3;

void straight()
{
    left_1 = 0;
    left_2 = 1;
    right_1 = 1;
    right_2 = 0;
}

void left()
{
    left_1 = 1;
    left_2 = 1;
    right_1 = 1;
    right_2 = 0;
}

void right()
{
    left_1 = 0;
    left_2 = 1;
    right_1 = 1;
    right_2 = 1;
}

void stop()
{
    left_1 = 1;
    left_2 = 1;
    right_1 = 1;
    right_2 = 1;
}
