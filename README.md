  # Sensor
It is the code of our project. You can also see how we made it.

//Here start the code

#include <18f4550.h>
#fuses nomclr,nowdt,intrc_io
#use delay(clock=8000000)
#device adc=10 


#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_DATA4 PIN_D4
>>>>>>> 2b13dd123dc69f394568ef09647a937f778d09b0

void main()
{
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   set_adc_channel(0);

