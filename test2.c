#include<reg52.h>
#include<intrins.h>
sbit P1_1=P1^1;
sbit P3_3=P3^3;
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}


void main()
{  P1=0;
   Delay100ms();
   P2=0;

	while(1)
	{
	 Delay100ms();
	 if(P3_3==0)
	 {
	 P1_1=0;Delay100ms();
	 P1_1=1;Delay100ms();
	 P1_1=0;Delay100ms();
	 P1_1=1;Delay100ms();
	 P1_1=0;Delay100ms();
	 P1_1=1;Delay100ms();
	 P1_1=0;Delay100ms();
	 P1_1=1;Delay100ms();
	 P1_1=0;Delay100ms();
	 }
	 P1=0xff;
	}
}