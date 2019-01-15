
#include "mbed.h"

SPI spi(p5, p6, p7); // mosi, miso, sclk
DigitalOut a0(p8);
DigitalOut cs(p11);
DigitalOut nreset(p6);

int main()
{
    int j=0;

		//SPI Initilization
    spi.format(8,3);						// 8 bit spi mode 3
    spi.frequency(20000000);		// 19,2 Mhz SPI clock
		
		//LCD Initilization
		cs=0;
		a0=0;
		nreset=0;										// display reset
		wait_us(50);
		nreset=1;										// end reset
		wait_ms(5);

		spi.write(0xAE);			// display off
		spi.write(0xA2);			// bias voltage
		spi.write(0xA0);			
		spi.write(0xC8);			// colum normal
		spi.write(0x22);			// voltage resistor ratio
		spi.write(0x2F);			// power on
		spi.write(0x40);			// start line = 0
		spi.write(0xAF);			// display ON
		spi.write(0x81);			// set contrast
		spi.write(0x17);			// set contrast
		spi.write(0xA6);			// display normal
	
	
		//Write four checks to the four corners
		
		//Write top-left		
		//Set LCD address
    spi.write(0x00);      // set column low nibble 0
    spi.write(0x10);      // set column hi  nibble 0
    spi.write(0xB0);      // set page address  0

		//Write 8-bit data to the address
		a0=1;
		for(j=0;j<8;j++)
			spi.write(0xFF);			//write data

		//Write top-right		
		//Set LCD address
		a0=0;
    spi.write(0x07);      // set column low nibble 7
    spi.write(0x17);      // set column hi  nibble 7
    spi.write(0xB0);      // set page address  0

		//Write 8-bit data to the address		
		a0=1;		
		for(j=0;j<8;j++)
			spi.write(0xFF);			//write data
			
		//Write bottom-left		
		//Set LCD address	
		a0=0;	
    spi.write(0x00);      // set column low nibble 0
    spi.write(0x10);      // set column hi  nibble 0
    spi.write(0xB3);      // set page address  3

		//Write 8-bit data to the address
		a0=1;	
		for(j=0;j<8;j++)
			spi.write(0xFF);			//write data	

		//Write bottom-right		
		//Set LCD address
		a0=0;
    spi.write(0x07);      // set column low nibble 7
    spi.write(0x17);      // set column hi  nibble 7
    spi.write(0xB3);      // set page address  3

		//Write 8-bit data to the address
		a0=1;	
		for(j=0;j<8;j++)
			spi.write(0xFF);			//write data

		
}
