#include <reg51.h>

sbit Echo_Front = P3^7;
sbit Trig_Front = P3^6;
sbit Echo_Right = P3^5;
sbit Trig_Right = P3^4;
sbit Echo_Left = P3^3;
sbit Trig_Left = P3^2;

int time, dis;

void delay(int t)// delay(uS)
{
	while(t--);
}

int space_front() {
	Echo_Front = 0;
	TMOD = 0x01;
	Trig_Front = 1;// trig len 1
	delay(10);// delay
	Trig_Front = 0;	
	while(Echo_Front == 0);// cho echo len 1
	TL0=TH0=0;// reset bo nho timer
	TR0=1;// bat dau timer
	while(Echo_Front == 1)// cho echo ve 0
	{
		if(TF0 == 1)
			break;
	}
	TR0=0;// dung bam gio
	TF0 = 0;
	time = (TL0 + TH0*256)*1.085;// tinh thoi gian
	dis = time/58;// tinh khoang cach (cm)
	if (dis < 17) {
		return 1;
	}
	else {
		return 0;
 	}
}

int space_right() {
	Echo_Right = 0;
	TMOD = 0x01;
	Trig_Right = 1;// trig len 1
	delay(10);// delay
	Trig_Right = 0;	
	while(Echo_Right == 0);// cho echo len 1
	TL0=TH0=0;// reset bo nho timer
	TR0=1;// bat dau timer
	while(Echo_Right == 1)// cho echo ve 0
	{
		if(TF0 == 1)
			break;
	}
	TR0=0;// dung bam gio
	TF0 = 0;
	time = (TL0 + TH0*256)*1.085;// tinh thoi gian
	dis = time/58;// tinh khoang cach (cm)
	if (dis < 12) {
		return 1;
	}
	else {
		return 0;
 	}
}

int space_left() {
	Echo_Left	 = 0;
	TMOD = 0x01;
	Trig_Left	 = 1;// trig len 1
	delay(10);// delay
	Trig_Left	 = 0;	
	while(Echo_Left	 == 0);// cho echo len 1
	TL0=TH0=0;// reset bo nho timer
	TR0=1;// bat dau timer
	while(Echo_Left	 == 1)// cho echo ve 0
	{
		if(TF0 == 1)
			break;
	}
	TR0=0;// dung bam gio
	TF0 = 0;
	time = (TL0 + TH0*256)*1.085;// tinh thoi gian
	dis = time/58;// tinh khoang cach (cm)
	if (dis < 12) {
		return 1;
	}
	else {
		return 0;
 	}
}

int dis_right() {
	Echo_Right = 0;
	TMOD = 0x01;
	Trig_Right = 1;// trig len 1
	delay(10);// delay
	Trig_Right = 0;	
	while(Echo_Right == 0);// cho echo len 1
	TL0=TH0=0;// reset bo nho timer
	TR0=1;// bat dau timer
	while(Echo_Right == 1)// cho echo ve 0
	{
		if(TF0 == 1)
			break;
	}
	TR0=0;// dung bam gio
	TF0 = 0;
	time = (TL0 + TH0*256)*1.085;// tinh thoi gian
	dis = time/58;// tinh khoang cach (cm)
	return dis;
}
int dis_left() {
	Echo_Left = 0;
	TMOD = 0x01;
	Trig_Left = 1;// trig len 1
	delay(10);// delay
	Trig_Left = 0;	
	while(Echo_Left == 0);// cho echo len 1
	TL0=TH0=0;// reset bo nho timer
	TR0=1;// bat dau timer
	while(Echo_Left == 1)// cho echo ve 0
	{
		if(TF0 == 1)
			break;
	}
	TR0=0;// dung bam gio
	TF0 = 0;
	time = (TL0 + TH0*256)*1.085;// tinh thoi gian
	dis = time/58;// tinh khoang cach (cm)
	return dis;
}
