#include <iostream>
#include <unistd.h>
#include "sensors/headers/mem_sensor.hpp"
#include "sensors/headers/data/sensor_readings.hpp"
#include "sensors/headers/cpu_sensor.hpp"

int main() {
    
    // Get Memory Readings
    auto memSensor = new MemSensor();
    sensor_readings readings;
    memSensor->getReadings(readings);

    // Get CPU Readings
    auto cpuSensor = new CpuSensor();
    cpuSensor->getReadings(readings);

    std::cout << readings.memorySensor.memTotal.property << ": " << readings.memorySensor.memTotal.value << std::endl;
    std::cout << readings.cpuSensor.totalUsage.property << ": " << readings.cpuSensor.totalUsage.value << std::endl;

    sleep(1);

    while (1) {
        sleep(1);
        memSensor->getReadings(readings);
        cpuSensor->getReadings(readings);
        std::cout << readings.cpuSensor.totalUsage.property << ": " << readings.cpuSensor.totalUsage.value << std::endl;
        std::cout << readings.memorySensor.memAvailable.property << ": " << readings.memorySensor.memAvailable.value << std::endl;
    }

    return 0;
}