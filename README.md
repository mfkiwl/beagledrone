beagledrone
===========

Software for beaglebone controlling multirotor drones.

## Build
### Java client
```bash
ant
ant BeagleUDP
```
### C++ server
```bash
cd src
cmake CMakeList.txt
make
```

## Sensors

Table shows which sensors are implemented.

| Hardware | Sensor | Implemented |
|----------|--------| ----------- |
| MAX21100 | Accel  | Yes         |
| MAX21100 | Gyro   | Yes         |
| MAX21100 | Magnet | Not yet     |
| MAX21100 | Temp   | Yes         |
| MS5611   | Baro   | Not yet     |

Other platforms can inherit from i2c_inferface abstract class to adapt drivers.
