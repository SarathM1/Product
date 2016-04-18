
// PIC12F675 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High speed crystal/resonator on GP4/OSC2/CLKOUT and GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#define INPUT1 GPIO0
#define INPUT2 GPIO3            // GPIO3 is input only pin
#define OUTPUT GPIO2

int main()
{
    GPIO = 0x00;        // All GPIO pins '0'
    TRISIO0 = 1;        // GPIO0 input
    TRISIO3 = 1;        // GPIO3 input
    TRISIO2 = 0;        // GPIO2 ouput
    CMCON = 0x07;       // Disable Comparator; to use GPIO pins as digital pins
    ANSEL = 0x00;       // Disable Analog ip; all GPIO pins are digital pins    
    
    /*
        voltage range: -0.3V to (VDD+0.3V) with respect to Vss; 
        current range: +/-20mA;
        (Section 12.0 Data sheet; Electrical Specifications) 
    */
    while(1)
    {
        if(INPUT1 == 1 && INPUT2 == 0)      
        {
            OUTPUT = 0;
        }
        
        else if(INPUT1 == 0 && INPUT2 == 1)
        {
            OUTPUT = 1;
        }
        /*
        else if(INPUT1 == 0 && INPUT2 == 0)
        {
            OUTPUT = ?;
        }
        
        else if(INPUT1 == 1 && INPUT2 == 1)
        {
            OUTPUT = ?;
        }*/
    }
}