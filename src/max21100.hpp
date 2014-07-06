#ifndef _MAX21100_H_
#define _MAX21100_H_

#include "i2c.hpp"

struct Orientation { uint16_t x; uint16_t y; uint16_t z; };

class max21100 {
private:
  i2c *i2cbus;
public:
  static const uint8_t addr = 0x58;
  max21100();
  ~max21100();
  float readTemp();
  Orientation getGyroXYZ();
  Orientation getAccelXYZ();
};

class power_cfg {
private:
  i2c *i2cbus;
  static const uint16_t waitms = 6000;
  static const uint8_t  addr   = 0x00;
public:
  enum State { ENABLE = 0x7f, DISABLE = 0x00}; // Only two states implemented
  power_cfg(i2c *i2cbus);
  void power(State state);
};

class temp {
private:
  i2c *i2cbus;
  static const uint8_t  addr_high   = 0x36;
  static const uint8_t  addr_low    = 0x37;
  static const uint16_t sensitivity = 0x100;
public:
  temp(i2c *i2cbus_ptr);
  float readTemp();
};

class gyro {
private:
  i2c *i2cbus;
  static const uint8_t  addr_high_x   = 0x24;
  static const uint8_t  addr_low_x    = 0x25;
  static const uint8_t  addr_high_y   = 0x26;
  static const uint8_t  addr_low_y    = 0x27;
  static const uint8_t  addr_high_z   = 0x28;
  static const uint8_t  addr_low_z    = 0x29;
public:
  gyro(i2c *i2cbus_ptr);
  Orientation getXYZ();
};

class accel {
private:
  i2c *i2cbus;
  static const uint8_t  addr_high_x   = 0x2A;
  static const uint8_t  addr_low_x    = 0x2B;
  static const uint8_t  addr_high_y   = 0x2C;
  static const uint8_t  addr_low_y    = 0x2D;
  static const uint8_t  addr_high_z   = 0x2E;
  static const uint8_t  addr_low_z    = 0x2F;
public:
  accel(i2c *i2cbus_ptr);
  Orientation getXYZ();
};
#endif
