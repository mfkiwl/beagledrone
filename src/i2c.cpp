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

std::vector<uint8_t> i2c::readbus(uint8_t reg_addr, size_t size) {
	uint8_t write_buff[1]={0};
	uint8_t read_buff[size]={0};
	write_buff[0] = reg_addr;
	
	if(write(i2c_dev, write_buff, 1) != 1){
		throw std::runtime_error("error: wrote more than one byte");
	}
	std::cout << (unsigned int)read_buff[0] << std::endl; // DEBUG
	if(read(i2c_dev, read_buff, size) != (ssize_t)size){
		throw std::runtime_error("error: got less bytes than expected");
	}
	std::cout << (unsigned int)read_buff[0] << std::endl; // DEBUG
	
	std::vector<uint8_t> vect(size);
	for(size_t i=0;i<size;i++) {
		vect[i] = read_buff[i];
	}
	return(vect);
}

