
#include "mbed.h"
 
// Serial tx, rx connected to the PC via an USB cable
Serial device(USBTX, USBRX); 
 
int main() {
	
		//Set baudrate to 9600 bps
    device.baud(9600);
    device.printf("Hello World from mbed! \n");
		
}
