#include <18f4550.h>    // we include the pic "library"
#device adc=10    //we configure the ADC to work with 10 bits
#fuses PLL1, nomclr,nowdt,intrc,cpudiv1     // These are the fuses that we need in order to configure the pic an example is "intrc" is used to indicate that we want to use the internal clock
#use delay(clock=8000000)     // we indicate the crystal we are using, the internal crystal of this pic is 8MHz


//Here, we set the LCD pins and include a library in order to be able to use LCD
#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
#include <lcd.c>

#define buzzer pin_a1 //we define the pin of the pic with respect to the sensor.
int lm35v,cont=0;     
float temp;
 
#int_timer3
void read_temperature()  // This is a function inside the timer3 interrupt which read the remperature and show it in the LCD
{
    cont++;                                   // We made a accountant in order to read the temperature every second
   if(cont==40)                              // 40*(25ms) = 1 second
   {

    	lm35v = read_adc();                    // Here, the sensor reads the current temperature
		temp = lm35v*0.488;                    // We multiplicate what the sensor read with the number of mV that are in each bit (0.488)
		lcd_gotoxy(1,1);                       // We indicate where the cursor of the LCD will be
		printf(lcd_putc,"\f T = %f",temp);      // The pic shows us what is the current temperature via LCD
		if(temp>40)                                
		{
   			printf(lcd_putc,"WARNING!!!");      //We print  WARNING!!! when the temperature is major that 40°C.
   			while(temp>40)                      //The thing that happen when the temperature is major 40°C.
			{

				output_toggle(buzzer);
				delay_ms(100);                 //With this the buzzer will stop every second.
				lm35v = read_adc();            //Read the adc again.
				temp = lm35v*0.4882;          //It give the temperature.
			}
    	}
   		cont=0;                              // The accountant is set to zero
  	}
	set_timer3(15535);                        // The timer3 is set to work wit 25ms
   	clear_interrupt(int_timer3);              // The timer3 is clean
}
  
