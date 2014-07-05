#include <iostream>
#include <cstdio>

#include "i2c.hpp"

int main(int argc, char **args) {
  try {
  	i2c i2cbus("/dev/i2c-1", 0x58);
  	i2cbus.writebus(0x00,0x7F);                              // power on
  	usleep(6000);                                            // wait for the device to start up 
  	std::vector<uint8_t> temp = i2cbus.readbus({0x36,0x37}); // read both high and low addresses
  	std::cout << (float)((temp[0] << 8) | temp[1])/256.0 << std::endl; // print temperature in celcius
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}
