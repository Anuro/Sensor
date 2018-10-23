#include <18f4550.h>    // we include the pic "library"
#device adc=10    //we configure the ADC to work with 10 bits
#fuses PLL1, nomclr,nowdt,intrc,cpudiv1     // These are the fuses that we need in order to configure the pic an example is "intrc" is used to indicate that we want to use the internal clock
#use delay(clock=8000000)     // we indicate the crystal we are using, the internal crystal of this pic is 8MHz




lm35v = read_adc();                    // Here, the sensor reads the current temperature
temp = lm35v*0.488;                    // We multiplicate what the sensor read with the number of mV that are in each bit (0.488)
lcd_gotoxy(1,1);                       // We indicate where the cursor of the LCD will be
printf(lcd_putc,"\f T = %f",temp);      // The pic shows us what is the current temperature via LCD
if(temp>40)                                
{
   printf(lcd_putc,"WARNING!!!");      //We print  WARNING!!! when the temperature is major that 40°C.
   while(temp>40)                      //The thing that happen when the temperature is major 40°C.
{


  
  
  
  
  
