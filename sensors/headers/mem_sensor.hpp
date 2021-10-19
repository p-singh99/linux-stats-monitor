#ifndef MEM_SENSOR_HPP
#define MEM_SENSOR_HPP

#include "sensor.hpp"
#include <fstream>

#define MEM_STAT_FILE "/proc/meminfo"

class MemSensor: public Sensor {
private:
    std::fstream file;
    void resetFile();
public:
    MemSensor(/* args */);
    ~MemSensor();
    void getReadings(sensor_readings& readings);
};

#endif