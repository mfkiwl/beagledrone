#ifndef _MAX21100_H_
#define _MAX21100_H_

#include "i2c.hpp"
#include <memory>

class max21100 {
	private:
		i2c *i2cbus;
	public:
		static const uint8_t addr = 0x58;
		max21100();
		~max21100();
		float readTemp();
};

class power_cfg {
	private:
		i2c *i2cbus;
		static const uint16_t waitms = 6000;
		static const uint8_t  addr   = 0x00;
	public:
		enum State { ENABLE = 0x7f, DISABLE = 0x00};
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
#endif

