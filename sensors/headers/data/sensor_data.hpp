#ifndef SENSOR_DATA_HPP
#define SENSOR_DATA_HPP

#include <string>

typedef struct sensor_data {
    std::string property;
    float value;
} sensor_data;

#endif