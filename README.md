<<<<<<< HEAD
  Executable files.

The execute files work in CCS application download it on the page https://download.cnet.com/CCSC-Compiler/3000-2212_4-76172170.html of internet.
then we need to learn about basic introduction of the language for understand how it works after that we need to add three libraries (device, fuses and use) using some specifications about them.
For start the process of the code we begin including the name of the PIC because the program CCS can obtain the libraries and use them later
Then we put a device “ADC” and we define that the code works with 10 bits also add “fuses” as the result of configure the PIC.
Then add a delay with the purpose of the program knows about the crystal that we should use.
We define the legs of the PIC and incorporate a variable that we need to use in this case is “sensor”.
Later we put the function “timer3 interrupt” which reads the temperature and shows it in the LCD device.   We put on a command with the end of read the temperature every second and we collocate that read the current of the temperature (and it is reading on millivolts or mV).
We indicate a multiplication between the current of the temperature and 0.488 (it is the quantity in each bit)
 Later we indicate where is going to be respect with the LCD screen.
 Then we print the previous result that is the temperature.
 After, we indicate the “timer3” clean it every 25 seconds as a result this do the temperature more exactly.
Determine all the features that we need.
The timer3 we send it to work with the internal clock.
Next timer3 is to over float 25 milliseconds enable.
Enable an interrupt by timer3.
Enable the global interrupts.
The timer3 is clean.
The ADC is set to work with the internal clock.
The ADC is set to use one port (First port).
 Indicate which of the ports we need to use as we said the last feature.
The LCD is initialized.
=======
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
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7 
#include <lcd.c> 

#define buzzer pin_a1



float temp;

int lm35v = 0;

void main()
{
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   set_adc_channel(0);
   lcd_init();
   while(TRUE)

   {
>>>>>>> 8a2e160076e985f9f02eb1eedc3ac3118ff73122
