#include <iostream>
#include <cstdio>

#include "i2c.hpp"

int main(int argc, char **args) {
  try {
  	i2c i2cbus("/dev/i2c-1", 0x58);
  	std::vector<char> vect = i2cbus.readbus(0x20, 2); // Read from 0x20 whoami one byte
  	//std::cout << std::hex << (unsigned char)vect[0] << std::endl;
  	printf("Value is: %hhx\n",(vect[0]<<8)+(vect[1]));
  	
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}
