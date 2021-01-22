#include<reg52.h>
sbit P1_1=P1^1;
sbit P1_2=P1^2;
sbit P1_3=P1^3;
sbit P1_4=P1^4;
void main()
{
  P1_1=0;
  P1_2=1;
  P1_3=0;
  P1_4=0;
 }