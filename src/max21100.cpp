#include "max21100.hpp"

max21100::max21100() : i2cbus(new i2c("/dev/i2c-1", 0x58)) { // initialize i2c bus
	power_cfg pcfg(i2cbus);
	pcfg.enable();
}

float max21100::readTemp() {
	 return(i2cbus->readbus(0x36,0x37)/256.0);               // read high byte and low byte
}

max21100::~max21100() {
	delete i2cbus;                                             // free bus
}

power_cfg::power_cfg(i2c *i2cbus_ptr) : i2cbus(i2cbus_ptr) {
}

power_cfg::~power_cfg() {
}

void power_cfg::enable() {
	i2cbus->writebus(0x00,0x7F);                               // power on
  usleep(6000);                                              // wait for the device to start up
}
