#ifndef _MAX21100_H_
#define _MAX21100_H_

#include "i2c.hpp"
#include <memory>

class max21100 {
 private:
  i2c *i2cbus;
 public:
 
  max21100();
  ~max21100();
  float readTemp();
};

class power_cfg {
	private:
		i2c *i2cbus;
	public:
	power_cfg(i2c *i2cbus);
	~power_cfg();
	void enable();
};
#endif

