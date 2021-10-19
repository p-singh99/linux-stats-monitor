#ifndef CPU_SENSOR_HPP
#define CPU_SENSOR_HPP

#include <iostream>
#include <fstream>
#include "sensor.hpp"

#define CPU_STAT_FILE "/proc/stat"
#define CPU_DATA_COLS 10

class CpuSensor: public Sensor {
private:
    size_t prevIdleReading = 0;
    size_t prevTotalReading = 0;
    void resetFile();
    void getCurrentReading(size_t &idleTime, size_t &totalTime);
public:
    CpuSensor();
    ~CpuSensor();
    void getReadings(sensor_readings& readings);
};

#endif