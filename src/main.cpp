#include <iostream>
#include "max21100.hpp"

int main(int argc, char **args) {
  try {
		max21100 m{};
		std::cout << m.readTemp() << std::endl;		
  } catch (std::exception &ex) {
  	std::cerr << ex.what() << std::endl;
  }
  return(0);
}

