/*
 * ds18b20.c
 *
 *  Created on: Jan 17, 2025
 *      Author: Lenovo310
 */
#include "ds18b20.h"

uint8_t rx_done = 0;
uint8_t rx_data[8];

int DS18B20_start (void)
{
	uint8_t data = 0xF0;

	usart_hd_reinit(&huart6, 9600);

	// Transmit
	HAL_UART_Transmit(&huart6, &data, 1, HAL_MAX_DELAY);

	// Receive
	if (HAL_UART_Receive(&huart6, &data, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		return -1;
	}

	usart_hd_reinit(&huart6, 115200);

	if (data == 0xF0)	// Same data as sent, wrong behavior
	{
		return -2;
	}

	return 1;
}


void DS18B20_write (uint8_t data)
{
	uint8_t buffer[8];

	for (int i = 0; i < 8; i++)
	{
		if ((data & (1 << i)) != 0)  // if the bit is HIGH
		{
			buffer[i] = 0xFF;  // send a 1
		}
		else
		{
			buffer[i] = 0x00;  // send a 0
		}
	}

	HAL_UART_Transmit(&huart6, buffer, 8, HAL_MAX_DELAY);
}


uint8_t DS18B20_read (void)
{
	uint8_t buffer[8];
	uint8_t value = 0;

	for (int i = 0; i < 8; i++)
	{
		buffer[i] = 0xFF;
	}

	HAL_UART_Transmit_DMA(&huart6, buffer, 8);
	HAL_UART_Receive_DMA(&huart6, rx_data, 8);

	while (rx_done == 0);		// wait flag for DMA completion

	for (int i = 0; i < 8; i++)
	{
		if (rx_data[i] == 0xFF)  // bit is 1
		{
			value |= 1 << i;  // write a 1 to that position
		}
	}

	rx_done = 0;

	return value;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART6)
	{
		rx_done = 1;
	}
}


int ds18b20_read_raw_temp (uint16_t *temp_ptr)
{
	int presence;
	uint8_t temp_lsb, temp_msb;
	uint16_t temp;

	presence = DS18B20_start();
	DS18B20_write(0xCC);
	DS18B20_write(0x44);

	presence = DS18B20_start();
	DS18B20_write(0xCC);
	DS18B20_write(0xBE);

	temp_lsb = DS18B20_read();
	temp_msb = DS18B20_read();

	temp = ((uint16_t)temp_msb << 8) | temp_lsb;
	*temp_ptr = temp;

	return presence;
}
