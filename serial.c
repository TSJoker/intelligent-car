#include<reg52.h>
unsigned char x;
bit flag = 0;
sbit P1_1=P1^1;
sbit P1_2=P1^2;
sbit P1_3=P1^3;
sbit P1_4=P1^4;
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	ES = 1;
	EA = 1;
}
void xxx()interrupt 4
{
	
	if(TI == 1) 
	{
		TI = 0;
		return;
	}
	
	if(RI == 1) 
	{
		RI = 0;
		x = SBUF;
		flag = 1;
	}	

}
void main()
{
  UartInit();//配置下串口
  while(1)
  {
   if(flag==1)//有信息来了
   {
   //SBUF=x;//将收到的信息返回
    ES=0; //关闭中断
	if(x==1)
	{P1_1=1;
	P1_2=0;
	P1_3=0;
	P1_4=1;
	}
	if(x==0)
	{P1_1=0;
	P1_2=0;
	P1_3=0;
	P1_4=0;
	 }
	 if(x==2)
	 {P1_1=0;
	 P1_2=1;
	 P1_3=1;
	 P1_4=0;
	 }
	 if(x==3)
	 {P1_1=0;
	 P1_2=1;
	 P1_3=0;
	 P1_4=1;
	 }
	 if(x==4)
	 {P1_1=1;
	 P1_2=0;
	 P1_3=1;
	 P1_4=0;
	 }
	 if(x==5)
	 {P1_1=0;
	 P1_2=0;
	 P1_3=0;
	 P1_4=1;
	 }
	 if(x==6)
	 {P1_1=1;
	 P1_2=0;
	 P1_3=0;
	 P1_4=0;
	 }
	 if(x==7)
	 {P1_1=0;
	 P1_2=0;
	 P1_3=1;
	 P1_4=0;
	 }
	 if(x==8)
	 {P1_1=0;
	 P1_2=1;
	 P1_3=0;
	 P1_4=0;
	 }
	ES=1;//已完成，可以继续
	flag=0;
	}

  }
}
