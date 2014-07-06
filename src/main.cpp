#include <iostream>
#include <cstdio>

#include "i2c.hpp"

int main(int argc, char **args) {
  try {
  	i2c i2cbus("/dev/i2c-1", 0x58);
  	i2cbus.writebus(0x00,0x7F);                              // power on
  	usleep(6000);                                            // wait for the device to start up 
  	uint16_t temp = i2cbus.readbus({0x36,0x37});             // read both high and low addresses
		std::cout << (temp/256.0) << std::endl;
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}
