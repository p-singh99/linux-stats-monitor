#ifndef SENSOR_READINGS_HPP
#define SENSOR_READINGS_HPP

#include "memory_sensor.hpp"
#include "cpu_data.hpp"

typedef struct sensor_readings {
    memory_sensor memorySensor;
    cpu_data cpuSensor;
} sensor_readings;

#endif