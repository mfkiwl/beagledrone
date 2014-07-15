CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
 
PROJECT(beagledrone)
FIND_PACKAGE(Boost COMPONENTS system filesystem REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

ADD_EXECUTABLE (beagledrone main.cpp i2c.cpp max21100.cpp) 
TARGET_LINK_LIBRARIES(beagledrone ${Boost_LIBRARIES} )

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -lpthread")
endif()

