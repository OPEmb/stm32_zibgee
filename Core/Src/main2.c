/*
 * main2.c
 *
 *  Created on: Jun 4, 2024
 *      Author: dark
 */

#include "mrf24j40ma_dev.h"
#include <string.h>

/*

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	int_triggered++;
	uint8_t last_interrupt = read_short(MRF_INTSTAT);
	uint8_t tmp = read_short(MRF_TXSTAT);
	if(!last_interrupt && !tmp){
		return;
	}
	interrupt = 1;

	__NOP();
}
*/

static mrf24j40ma_dev_t dev;

void main2(gpio_if_t* reset_pin,spi_if_t* spi,mrf24j40ma_delay_us_fn delay_us
		,mrf24j40ma_isr_fn enable_int,mrf24j40ma_isr_fn disable_int){
	mrf24_create_dev(&dev,reset_pin,spi,delay_us,enable_int,disable_int);

}
