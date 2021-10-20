#include <iostream>
#include <fstream>
#include "headers/cpu_sensor.hpp"
#include "headers/data/sensor_readings.hpp"

CpuSensor::CpuSensor() {
    getCurrentReading(prevIdleReading, prevTotalReading);
}

CpuSensor::~CpuSensor() {}

void CpuSensor::getCurrentReading(size_t &idleTime, size_t &totalTime) {
    std::fstream file(CPU_STAT_FILE, std::fstream::in);
    if (!file.is_open()) {
        std::cout << "Failed to open file for reading CPU stats" << std::endl;
        return;
    }

    std::string property;
    file >> property;
    
    int cpuReadings[CPU_DATA_COLS] = {};
    // Parse the first line of the file to get total CPU data
    for (int i = 0; i < CPU_DATA_COLS; i++) {
        int val;
        file >> val;
        cpuReadings[i] = val;
    }

    auto total = 0;
    for (int i = 0; i < CPU_DATA_COLS; i++) {
        total += cpuReadings[i];
    }

    idleTime = cpuReadings[3];
    totalTime = total;

    file.close();
}

void CpuSensor::getReadings(sensor_readings& readings) {
    
    size_t idleTime, totalTime = 0;
    getCurrentReading(idleTime, totalTime);

    const float idleDelta = idleTime - prevIdleReading;
    const float totalDelta = totalTime - prevTotalReading;
    const float percentUsed = totalDelta - idleDelta;
    readings.cpuSensor.totalUsage.value = 100.0 * percentUsed / totalDelta;

    prevIdleReading = idleTime;
    prevTotalReading = totalTime;

}

