#include "i2c.hpp"

i2c::i2c(std::string dev_path, uint8_t addr) {
	if((i2c_dev = open(dev_path.c_str(), O_RDWR | O_NONBLOCK)) < 0){
		throw std::runtime_error("error: failed to open device " + dev_path);
	}
	if(ioctl(i2c_dev,I2C_SLAVE,addr) < 0){
		throw std::runtime_error("error: failed to acquire i2c bus access and talk to slave");
	}
}

i2c::~i2c() {
	close(i2c_dev);
}

void i2c::writebus(uint8_t reg_addr, uint8_t *buff, size_t size) {
	write_buff[0] = reg_addr;
	memcpy(&write_buff[1], &buff, size);
	ssize_t s;

	if((s = write(i2c_dev, write_buff, size+1)) != (ssize_t)size+1){
		throw std::runtime_error("error: wrote than one byte");
	}
}

uint8_t* i2c::readbus(uint8_t reg_addr, size_t size) {
	write_buff[0] = reg_addr;
	ssize_t s, r;

	if((s = write(i2c_dev, write_buff, 1)) != 1){
		throw std::runtime_error("error: wrote than one byte");
	}
	if((r = read(i2c_dev, read_buff, size)) != (ssize_t)size){
			throw std::runtime_error("error: read less bytes than expected");
	}
	return(read_buff);
}
