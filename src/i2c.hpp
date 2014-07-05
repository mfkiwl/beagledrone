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
/* memcpy */
#include <cstring>

#include <string>
#include <iostream>
#include <stdexcept>

#define MAX_BUFFER_SIZE					64

class i2c {
 private:
  uint8_t i2c_dev;
	uint8_t write_buff[MAX_BUFFER_SIZE];
	uint8_t read_buff[MAX_BUFFER_SIZE];
	
 public:
  i2c(std::string dev_path, uint8_t addr);
  void writebus(uint8_t reg_addr, uint8_t *buff, size_t size);
  uint8_t* readbus(uint8_t reg_addr, size_t size);
  
  ~i2c();
};
#endif

