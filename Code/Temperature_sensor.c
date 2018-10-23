#include <18f4550.h>    // we include the pic "library"
#device adc=10    //we configure the ADC to work with 10 bits
#fuses PLL1, nomclr,nowdt,intrc,cpudiv1     // These are the fuses that we need in order to configure the pic an example is "intrc" is used to indicate that we want to use the internal clock
#use delay(clock=8000000)     // we indicate the crystal we are using, the internal crystal of this pic is 8MHz

