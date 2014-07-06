#include <iostream>
#include "max21100.hpp"
#include <sstream>
int main(int argc, char **args) {
  try {
		max21100 m{};
		std::cout << m.readTemp() << std::endl;
		for(int i = 0 ; i<1000; i++) {
			usleep(6000);
			Orientation go = m.getGyroXYZ();
			Orientation ao = m.getAccelXYZ();
			
			std::stringstream ss;
			ss << (int)go.x << ":" << (int)go.y << ":" << (int)go.z;
			ss << ":" << (int)ao.x << ":" << (int)ao.y << ":" << (int)ao.z;
			std::cout << ss.str() << std::endl;
		}
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}

