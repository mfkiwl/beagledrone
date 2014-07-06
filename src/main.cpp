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
			double x = ((ao.x*(4/scale))/1.875)-2.1;
			double y = ((ao.y*(4/scale))/1.875)-2.1;
			double z = ((ao.z*(4/scale))/1.875)-1.4;
	
			ss << x << ":" << y << ":" << z;
			std::cout << ss.str() << std::endl;
		}
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}

