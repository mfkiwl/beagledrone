#include <iostream>
#include "i2c.hpp"

int main(int argc, char **args) {
  try {
  	i2c i2cbus("/dev/i2c-1", 0x58);
  	uint8_t *rbuf = i2cbus.readbus(0x20, 2); // Read from 0x20 whoami one byte
  	std::cout << std::hex << rbuf << std::endl;
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}
