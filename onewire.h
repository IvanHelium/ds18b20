/*
 * onewire.h
 *
 *  Version 1.0.1
 */

#ifndef ONEWIRE_H_
#define ONEWIRE_H_

// for different prosessor require check function  OW_Init
// for the location of the legs USART
//#include "stm32f10x.h"
#include <stdint.h>

// choose which USART is 1-wire
#define OW_USART1
//#define OW_USART2
//#define OW_USART3
//#define OW_USART4


// if you need to give ticks FreeRTOS, then uncomment
//#define OW_GIVE_TICK_RTOS

// the first parameter of the function OW_Send
#define OW_SEND_RESET		1
#define OW_NO_RESET		2

// function return status
#define OW_OK			1
#define OW_ERROR		2
#define OW_NO_DEVICE	3

#define OW_NO_READ		0xff

#define OW_READ_SLOT	0xff

uint8_t OW_Init(void);
uint8_t OW_Reset(void);
uint8_t OW_Send(uint8_t sendReset, char *cmd, uint8_t cLen, uint8_t *data, uint8_t dLen, uint8_t readStart);


#endif /* ONEWIRE_H_ */
