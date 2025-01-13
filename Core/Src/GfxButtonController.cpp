/*
 * GfxButtonController.c
 *
 *  Created on: Jan 11, 2025
 *      Author: Lenovo310
 */
#include "GfxButtonController.hpp"
#include "main.h"
#include "gpio.h"


bool GfxButtonController::sample(uint8_t& key)
{
	if (HAL_GPIO_ReadPin(KEY_UP_GPIO_Port, KEY_UP_Pin) == GPIO_PIN_RESET)
	{
		key = 1;
		return true;
	}

	if (HAL_GPIO_ReadPin(KEY_DN_GPIO_Port, KEY_DN_Pin) == GPIO_PIN_RESET)
	{
		key = 2;
		return true;
	}

	return false;
}
