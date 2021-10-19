#ifndef MEMORY_SENSOR_HPP
#define MEMORY_SENSOR_HPP

#include "sensor_data.hpp"

#define MEM_DATA_LEN 2

typedef struct memory_sensor {
    sensor_data memTotal {"Mem Total", 0};
    sensor_data memAvailable {"Mem Available", 0};
} memory_sensor;

#endif