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
//#include <linux/i2c.h>
#include <linux/i2c-dev.h>
/* memcpy */
#include <cstring>
/* uint_8 */
#include <cstdint>

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

class i2c {
 private:
  uint8_t i2c_dev;  
 public:
  i2c(std::string dev_path, uint8_t addr);
  std::vector<uint8_t> readbus(uint8_t reg_addr, size_t size);
  ~i2c();
};
#endif

