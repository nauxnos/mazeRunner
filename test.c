int space_right() {
	Echo_Right = 0;
	TMOD = 0x01;
	Trig_Right = 1;// bat Trigger phai
	delay(10);// delay 10
	Trig_Right = 0;	
	while(Echo_Right == 0);// cho Echo len 1
	TL0=TH0=0;// xoa bo nho thoi gian
	TR0=1;// bam gio
	while(Echo_Right == 1)// cho Echo xuong 1
	{
		if(TF0 == 1)
			break;
	}
	TR0=0;// tat bam gio
	TF0 = 0;
	time = (TL0 + TH0*256)*1.085;// tinh thoi gian (uS)
	distance = time/58;// tinh khoang cach (cm)
	if (distance < 10) {
		return 1;
	}
	else {
		return 0;
 	}
}