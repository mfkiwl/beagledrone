#ifndef _I2C_H_
#define _I2C_H_

/* open */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/* ioctl */
#include <sys/ioctl.h>
/* read/write */
#include <unistd.h>
/* i2c_slave */
#include <linux/i2c-dev.h>
/* uint_8 and uint16_t */
#include <cstdint>

#include <string>
#include <stdexcept>

class i2c_interface {
public:
  virtual ~i2c_interface() {};
  virtual uint16_t readbus(uint8_t high_addr, uint8_t low_addr) = 0;
  virtual void writebus(uint8_t reg_addr, uint8_t value) = 0;
};

class i2c : public i2c_interface {
private:
  uint8_t i2c_dev;  
public:
  i2c(std::string dev_path, uint8_t addr);
  uint16_t readbus(uint8_t high_addr, uint8_t low_addr);
  uint8_t readbus(uint8_t high_addr);
  void writebus(uint8_t reg_addr, uint8_t value);
  ~i2c();
};
#endif
