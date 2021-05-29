#include <reg52.h>
#include "8lcdvin.h"
//#include "delay.h"
#include "adc.h"
void main()
{
	unsigned char adc_result1;
	unsigned char adc_result2;
	lcd_init();
	adc_init();
	lcd_displaystring("voltage=");
	lcd_Gotolinetwo();
	lcd_displaystring("current=");
	while(1)
	{
		adc_result1 = adc_startconversion(1);
		
		//here u have to use formula to get the change value 
		
		
		lcd_displaynumber(adc_result1);
		
		first=adc_result*0.02;
		
		adc_result2=((first-2.5)/0.185);
		
		
		
		
		lcd_Gotolinetwo();
		lcd_displaynumber(adc_result2);
}