#ifndef DS18B20_H
#define DS18B20_H

#include <stdint.h>

void ds18b20_initialize(void);
uint8_t startMeasureTemperature(void);
uint16_t readTemperature(void);
float measureTemperature(void);


#endif
