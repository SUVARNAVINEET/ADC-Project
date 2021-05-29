#include <reg51.h>
#include "8lcdvin.h"
#include "delay.h"

#define databus P0;
//sbit rs =P3^3 ;
//sbit rw =P3^4 ;
//sbit en =P3^5 ;
//speecification
#define lcdmaxline 2;
#define lcdmaxchar 16;
#define lineone 0x80;
#define linetwo 0xc0;
#define blankspace '';
sbit rs =P3^3 ;
sbit rw =P3^4 ;
sbit en =P3^5 ;

void lcd_enablepluse()
 {
	 en=0;
	 en=1;
	 delay(100);
	 en=0;
	 delay(100);
 }
 void lcd_init()
 {
	 //databus0x00;
	 rs=0;
	 rw=0;
	 P0=0x30;
	 lcd_enablepluse();
	 delay_ms();
	 
	 databus 0x30;
	 lcd_enablepluse();
	 delay_us(500);
	 
	 databus=0x30;
	 lcd_enablepluse();
	 delay_us(500);

	 lcd_cmdwrite(0x38);
	 lcd_cmdwrite(0x0E);
	 lcd_cmdwrite(0x01);
	 lcd_cmdwrite(0x80);
 }
 
 void lcd_cmdwrite(char cmd)
 {
	 
	 databus=cmd;
	 rs=0;
	 rw=0;
	 lcd_enablepulse();
	 delay_Ms(1);
 }
  void lcd_datawrite(char dat)
 {
	 
	 databus=dat;
	 rs=1;
	 rw=0;
	 lcd_enablepulse();
	 delay_Ms(1);
 }
 
 void lcd_clear()
 {
	 lcd_cmdwrite(0x01);
	 lcd_cmdwrite(lineone);
 }
 void lcd_Gotolineone()
 {
	 lcd_cmdwrite(lineone);
 }
 void lcd_Gotolinetwo()
 {
	 lcd_cmdwrite(linetwo);
 }
 
 void lcd_displaystring(char *string_ptr)
 {
	 while(*string_ptr)
		 lcd_datawrite(*string_ptr++);
 }
 void lcd_displaynumber(unsigned int num)
	 {
lcd_datawrite((num/10000)+0x30);
num=num%10000;
lcd_datawrite((num/1000)+0x30);
num=num%1000;
lcd_datawrite((num/100)+0x30);
num=num%100;
lcd_datawrite((num/10)+0x30);

lcd_datawrite((num%10)+0x30);
	 }
		 
		 
	 