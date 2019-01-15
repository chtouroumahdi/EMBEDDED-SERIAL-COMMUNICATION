

#include "mbed.h"
 
//I2C interface  
I2C i2c_if(p28, p27);

//I2C address of temperature sensor LM75BD
const int tmp_addr = 0x90;

int main() {
    char cmd[2];
    while (1) 
	{
				
				//Write to the configuration register of the temperature sensor
	    cmd[0] = 0x00;		//configuration data (normal mode)
        cmd[1] = 0x00;		//address of configuration register
        i2c_if.write(tmp_addr, cmd, 2);
				
        wait(0.5);
				
				//read the 16-bit temperature from the sensor
        i2c_if.read(tmp_addr, cmd, 2);
 
				//convert the temperature data into real temperature
        float tmp = (float((cmd[0]<<8)|cmd[1]) / 256.0);
				
				//print the temperature via the serial cable
        printf("Temp = %.2f\n", tmp);
				
    }
}