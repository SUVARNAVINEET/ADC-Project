#include <reg52.h>
#include "adc.h"
#include "delay.h"
#define adc_databus P2
sbit adc_start=P3^1;
sbit adc_EOC=P3^2;
sbit adc_ALE=P1^3;
sbit adc_OE=P1^4;
sbit adc_A0=P1^5;
sbit adc_A1=P3^6;
sbit adc_A2=P3^7;


void adc_init()
{

adc_start=0;                //Initialize all the control lines to zero.
adc_ALE=0;
adc_OE=0;
adc_EOC=1;                  //Configure the EOC pin as I/P
adc_databus=0xff;             //configure adc_databus as input
}

void adc_startconversion(char channel);
{
unsigned char adc_result1;

adc_A=((channel>>0) & 0x01);   //Selectthe channel
adc_B=((channel>>1) & 0x01);   //for which the conversion needs to be done
adc_C=((channel>>2) & 0x01);

adc_ALE=1;         // Latch the address by making the ALE high.
delay_us(100);
adc_start=1;       //Start the conversion after latching the channel address
delay_us(100);
//adc_ALE=0;     //Pull ALE line to zero after starting the conversion.



delay_us(50);
//adc_start=0;       //Pull Start line to zero after starting the conversion.

while(adc_EOC==0);    // Wait till the ADC conversion is completed,
                    // EOC will be pulled to HIGH by the hardware(ADC0809)
	                 // once conversion is completed.

adc_OE=1;         //Make the Output Enable high
             //to bring the ADCdata to port pins
delay_us(100);
adc_result1=adc_databus;        //Read the ADCdata from ADC bus
   
 //After reading thedata, disable th ADC output line.
return(adc_result1) ;

}