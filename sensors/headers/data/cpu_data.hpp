#ifndef CPU_DATA_HPP
#define CPU_DATA_HPP

#include "sensor_data.hpp"

#define MEM_DATA_LEN 2

typedef struct cpu_data {
    sensor_data totalUsage = {"CPU Usage", 0};
} cpu_data;

#endif