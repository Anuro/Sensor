  # Sensor
It is the code of our project. You can also see how we made it.

//Here start the code

#include <18f4550.h>
#fuses nomclr,nowdt,intrc_io

#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_DATA4 PIN_D4

void main()
{
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   set_adc_channel(0);
