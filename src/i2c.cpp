#include "i2c.hpp"

i2c::i2c(std::string dev_path, uint8_t addr) {
	if((i2c_dev = open(dev_path.c_str(), O_RDWR | O_NONBLOCK)) < 0){
		throw std::runtime_error("error: failed to open device " + dev_path);
	}
	if(ioctl(i2c_dev, I2C_SLAVE, addr) < 0){
		throw std::runtime_error("error: failed to acquire i2c bus access and talk to slave");
	}
}

i2c::~i2c() {
	close(i2c_dev);
}

std::vector<char> i2c::readbus(uint8_t reg_addr, size_t size) {
	std::vector<char> read_vec(size);
	std::vector<char> write_vec{reg_addr};
	
	if(write(i2c_dev, write_vec.data(), write_vec.size()) != 1){
		throw std::runtime_error("error: wrote more than one byte");
	}
	
	if(read(i2c_dev, read_vec.data(), read_vec.size()) != (ssize_t)size) {
		throw std::runtime_error("error: got less bytes than expected");
	}

	return(read_vec);
}

