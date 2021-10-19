#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <fstream>
#include <iostream>
#include "data/sensor_readings.hpp"

class Sensor {
    private:
        std::fstream file;
    public:
         virtual void getReadings(sensor_readings& readings) = 0;
};

#endif