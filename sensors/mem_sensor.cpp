#include <iostream>
#include <string>
#include "headers/mem_sensor.hpp"
#include "headers/data/sensor_readings.hpp"

MemSensor::MemSensor() {
    file.open(MEM_STAT_FILE, std::fstream::in);
    if (!file.is_open()) 
        std::cout << "Failed to open file for reading memory stats" << std::endl;
}

MemSensor::~MemSensor() {
    if (file.is_open()) file.close();
}

void MemSensor::resetFile() {
    file.clear();
    file.seekg(0);
}

void MemSensor::getReadings(sensor_readings& readings) {
    if (file.is_open()) {
        std::string property;
        std::string unit;
        int value;
        auto finished = false;
        auto gotMemTotal = false;
        auto gotMemAvailable = false;

        while (!finished && file >> property >> value >> unit) {
            property = property.substr(0, property.size() - 1);
            if (property == "MemTotal") {
                readings.memorySensor.memTotal.property = property;
                readings.memorySensor.memTotal.value = value;
                gotMemTotal = true;
            } else if (property == "MemAvailable") {
                readings.memorySensor.memAvailable.property = property;
                readings.memorySensor.memAvailable.value = value;
                gotMemAvailable = true;
            }
            finished = gotMemTotal && gotMemAvailable;
        }

        resetFile();
    }
}

