#include <iostream>

#include "i2c.hpp"

int main(int argc, char **args) {
  try {
  	i2c i2cbus("/dev/i2c-1", 0x58);
  	std::vector<uint8_t> vect = i2cbus.readbus(0x20, 1); // Read from 0x20 whoami one byte
  	//std::cout << (int)vect[0] << std::endl;
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}
