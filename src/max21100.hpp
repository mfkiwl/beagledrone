#ifndef _MAX21100_H_
#define _MAX21100_H_

#include "i2c.hpp"

class max21100 {
 private:
  i2c *i2cbus;
 public:
  max21100();
  ~max21100();
  float readTemp();
};
#endif

