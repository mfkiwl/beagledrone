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

std::vector<uint8_t> i2c::readbus(std::vector<uint8_t> reg_addr) {
	std::vector<uint8_t> read_vec(0);
	for(uint8_t &addr : reg_addr) {
		uint8_t byte = i2c_smbus_read_byte_data(i2c_dev, addr);
		read_vec.push_back(byte);
	}
	return(read_vec);
}

void i2c::writebus(uint8_t reg_addr, uint8_t value) {
		i2c_smbus_write_byte_data(i2c_dev, reg_addr, value);
}

