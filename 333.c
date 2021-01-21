 #include <reg52.h>
#include<intrins.h>
sbit P3_3=P3^3;
sbit P3_7=P3^7;
sbit P1_1=P1^1;
sbit P1_2=P1^2;
sbit P1_3=P1^3;
sbit P1_4=P1^4;
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
 while(1)
 {
  P1_1=1;
  P1_2=0;
  P1_3=0;
  P1_4=1;
 if(P3_3==0 && P3_7==1)
  {P1_1=0;
   P1_2=1;
   P1_3=0;
   P1_4=0;
   Delay100ms();
  }
  else if(P3_3==1 && P3_7==0)
  {P1_1=0;
   P1_2=0;
   P1_3=1;
   P1_4=0;
   Delay100ms();
  }
  else if(P3_3==0 && P3_7==0)
  {P1_1=0;
   P1_2=0;
   P1_3=0;
   P1_4=0;
   Delay100ms();
  }
 }
}
