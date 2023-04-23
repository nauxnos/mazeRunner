#include <REGX51.H>

#define PWM_PIN P1_0

int i, T, Ton, Toff;
int Ton_h_reload, Ton_l_reload, Toff_h_reload, Toff_l_reload;

void PWM_Init(int ck)
{
	PWM_PIN = 1;
	TMOD &= 0XF0;
	TMOD |= 0X01;
	
	ET0 = 1;
	EA = 1;
	
	T = ck-24;
	Ton = ck / 2;
	Toff = T - Ton;
	
	Ton_h_reload = (65536 - Ton) >> 8;
	Ton_l_reload = (65536 - Ton) & 0X00FF;
	
	Toff_h_reload = (65536 - Toff) >> 8;
	Toff_l_reload = (65536 - Toff) & 0X00FF;
	
	TH0 = Ton_h_reload;
	TL0 = Ton_l_reload;
}

void PWM_Start()
{
	TR0 = 1;
}

void PWM_Stop()
{
	TR0 = 0;
}

void PWM_Set_Duty(int duty)
{
	if(duty==0)
	{
		PWM_PIN = 0;
		ET0 = 0;
	}
	else if(duty==100)
	{
		PWM_PIN = 1;
		ET0 = 0;
	}
	else
	{
		Ton = ((unsigned long)T) * duty / 100;
		Toff = T - Ton;
		
		Ton_h_reload = (65536 - Ton) >> 8;
		Ton_l_reload = (65536 - Ton) & 0X00FF;
		
		Toff_h_reload = (65536 - Toff) >> 8;
		Toff_l_reload = (65536 - Toff) & 0X00FF;
	}
}

void Timer0overflow() interrupt 1
{
	PWM_PIN = !PWM_PIN;
	if(PWM_PIN==0)
	{
		TH0 = Toff_h_reload;
		TL0 = Toff_l_reload;
	}
	else
	{
		TH0 = Ton_h_reload;
		TL0 = Ton_l_reload;
	}
}