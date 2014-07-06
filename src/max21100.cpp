#include "max21100.hpp"

max21100::max21100() : i2cbus(new i2c("/dev/i2c-1", addr)) { // initialize i2c bus
  power_cfg pcfg(i2cbus);
  pcfg.power(power_cfg::ENABLE);
}

max21100::~max21100() {
  delete i2cbus;                                             // free bus
}

float max21100::readTemp() {
  temp t(i2cbus);
  return t.readTemp();
}

Orientation max21100::getGyroXYZ() {
  gyro g(i2cbus);
  return g.getXYZ();
}

Orientation max21100::getAccelXYZ() {
  accel a(i2cbus);
  return a.getXYZ();
}

power_cfg::power_cfg(i2c *i2cbus_ptr) : i2cbus(i2cbus_ptr) { }
void power_cfg::power(State state) {
  i2cbus->writebus(addr, state);
  usleep(waitms);
}

temp::temp(i2c *i2cbus_ptr) : i2cbus(i2cbus_ptr) { }
float temp::readTemp() {
  return((int16_t)i2cbus->readbus(addr_high,addr_low)/(float)sensitivity);
}

gyro::gyro(i2c *i2cbus_ptr) : i2cbus(i2cbus_ptr) { }
Orientation gyro::getXYZ() {
  Orientation o;
  o.x = i2cbus->readbus(addr_high_x,addr_low_x);
  o.y = i2cbus->readbus(addr_high_y,addr_low_y);
  o.z = i2cbus->readbus(addr_high_z,addr_low_z);
  return o;
}

accel::accel(i2c *i2cbus_ptr) : i2cbus(i2cbus_ptr) { }
Orientation accel::getXYZ() {
  Orientation o;
  o.x = i2cbus->readbus(addr_high_x,addr_low_x);
  o.y = i2cbus->readbus(addr_high_y,addr_low_y);
  o.z = i2cbus->readbus(addr_high_z,addr_low_z);
  
  return o;
}
