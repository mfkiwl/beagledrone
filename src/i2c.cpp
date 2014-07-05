#include "i2c.hpp"

i2c::i2c(std::string dev_path, uint8_t addr) {
	if((i2c_dev = open(dev_path.c_str(), O_RDWR | O_NONBLOCK)) < 0){
		throw std::runtime_error("error: failed to open device " + dev_path);
	}
	if(ioctl(i2c_dev, I2C_SLAVE_FORCE, addr) < 0){
		throw std::runtime_error("error: failed to acquire i2c bus access and talk to slave");
	}
}

i2c::~i2c() {
	close(i2c_dev);
}

std::vector<uint8_t> i2c::readbus(uint8_t reg_addr, size_t size) {
	std::vector<uint8_t> read_vec(size);
	for(uint8_t &byte : read_vec) {
		byte = i2c_smbus_read_byte_data(i2c_dev, reg_addr);
	}
	return(read_vec);
}


