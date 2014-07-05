CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
 
PROJECT(beagledrone)
ADD_EXECUTABLE (beagledrone main.cpp i2c.cpp) 

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

