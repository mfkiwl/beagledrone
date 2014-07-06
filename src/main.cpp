#include <iostream>
#include "max21100.hpp"
#include <sstream>
int main(int argc, char **args) {
  try {
		max21100 m{};
		std::cout << m.readTemp() << std::endl;
		for(int i = 0 ; i<1000; i++) {
			usleep(8000);
			Orientation go = m.getGyroXYZ();
			Orientation ao = m.getAccelXYZ();
			
			std::stringstream ss;
			//ss << (int)go.x << ":" << (int)go.y << ":" << (int)go.z;
			double scale = 65536;
			double x = (((int16_t)ao.x*(4/scale)));
			double y = (((int16_t)ao.y*(4/scale)));
			double z = (((int16_t)ao.z*(4/scale)));
	//double x = (int16_t)ao.x;
	//double y = (int16_t)ao.y;
	//double z = (int16_t)ao.z;
			ss << x << ":" << y << ":" << z;
			std::cout << ss.str() << std::endl;
		}
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}

