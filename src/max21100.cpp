#include "max21100.hpp"

max21100::max21100() : i2cbus(new i2c("/dev/i2c-1", 0x58)) { // initialize i2c bus
	i2cbus->writebus(0x00,0x7F);                               // power on
  usleep(6000);                                              // wait for the device to start up
}

float max21100::readTemp() {
	 return(i2cbus->readbus(0x36,0x37)/256.0);               // read high byte and low byte
}

max21100::~max21100() {
	delete i2cbus;                                             // free bus
}
