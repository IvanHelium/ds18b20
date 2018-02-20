#include "ds18b20.h"
#include "onewire.h"
#include "stm32f4xx.h"

//---------------------------------------------------------------
//
//---------------------------------------------------------------
void ds18b20_initialize(void)
{
	OW_Init();
}
//---------------------------------------------------------------
//
//---------------------------------------------------------------
uint8_t startMeasureTemperature(void)
{	
	uint8_t OW_status=0;
	OW_status =	OW_Send(OW_SEND_RESET, "\xCC\x44", 2, 0, 0, OW_NO_READ);
	return OW_status;
}
//---------------------------------------------------------------
//
//---------------------------------------------------------------
uint16_t readTemperature(void)
{
	uint8_t buf[2];
	uint16_t result=0;
	OW_Send(OW_SEND_RESET, "\xCC\xBE\xFF\xFF", 4, buf, 2, 2);
	result = (((uint16_t)buf[1])<<8 | (uint16_t)buf[0]);
	return result;
}

//---------------------------------------------------------------
//
//---------------------------------------------------------------
float measureTemperature(void)
{		
		uint8_t OW_status;
		uint32_t i;
		uint16_t temperature;
		float temperature_f;
		OW_status = startMeasureTemperature();																			//start temperature measure
		for (i=0; i<1000000; i++); 																			//wait
		temperature = readTemperature();																			//read temperature measure
		temperature_f = (float)temperature / 16.0f; 							      //convert to Celsius
	
		return temperature_f;
}
//---------------------------------------------------------------
//
//---------------------------------------------------------------



