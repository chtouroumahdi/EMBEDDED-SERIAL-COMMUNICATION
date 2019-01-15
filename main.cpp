/*-------------------------------------------------------------
SERIAL COMMUNICATION
Integration using high-level API
Build an application, which displays current temperature on the LCD 
Input: temperature sensor
Output: LCD display
--------------------------------------------------------------*/

#include "mbed.h"
#include "LM75B.h"
#include "C12832_lcd.h"

//LCD peripheral
C12832_LCD lcd;

//Temperature sensor peripheral
LM75B tmp(p28,p27);

int main ()
{

    while (1) {
        lcd.cls();																					//LCD Initialization
        lcd.locate(0,3);																		//Text position
        lcd.printf("Temperature is: %.2f\n",tmp.read());		//Print temperature to the LCD
        wait(1.0);
    }

}
