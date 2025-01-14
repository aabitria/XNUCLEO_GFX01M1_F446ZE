/*
 * GfxButtonController.c
 *
 *  Created on: Jan 11, 2025
 *      Author: Lenovo310
 */
#include "GfxButtonController.hpp"
#include "main.h"
#include "gpio.h"

void GfxButtonController::init()
{
	for (uint16_t i = 0; i < 2; i++)
	{
		active_val[i] = 0;
		idle_val[i] = 1;

		if (active_val[i])
		{
			active_mask_debounce[i] = 0x00FF;
			idle_mask_debounce[i] = 0xFF00;
		}
		else
		{
			active_mask_debounce[i] = 0xFF00;
			idle_mask_debounce[i] = 0x00FF;
		}

		if (idle_val[i] != 0)
		{
			steady_state[i] = 1;
			state[i] = 1;
			prev_steady_state[i] = 1;
		}
		else
		{
			steady_state[i] = 0;
			state[i] = 0;
			prev_steady_state[i] = 0;
		}
	}
}

bool GfxButtonController::sample(uint8_t& key)
{
    if (detect_press_event(0))
    {
    	key = 1;
    	return true;
    }

    if (detect_press_event(1))
    {
    	key = 2;
    	return true;
    }

    num_run++;
    if (num_run == 13)
    {
    	num_run = 13;
    }
	return false;
}


uint16_t GfxButtonController::detect_press_event(uint16_t btn_idx)
{
	uint16_t btn_state = debounce(btn_idx);

	if ((btn_state != prev_steady_state[btn_idx]) && (btn_state == 0))
	{
		prev_steady_state[btn_idx] = btn_state;
		return 1;
	}

	prev_steady_state[btn_idx] = btn_state;
	return 0;
}


uint16_t GfxButtonController::debounce(uint16_t btn_idx)
{
	uint16_t val = 0;

	if (btn_idx == 0)
	{
		raw_val[0] = HAL_GPIO_ReadPin(KEY_UP_GPIO_Port, KEY_UP_Pin);
	}
	else
	{
		raw_val[1] = HAL_GPIO_ReadPin(KEY_DN_GPIO_Port, KEY_DN_Pin);
	}

	if (!raw_val[0] || !raw_val[1])
	{
		val++;
	}

	state[btn_idx] = (state[btn_idx] << 1) | raw_val[btn_idx];

	// continuous pressed state
	if ((state[btn_idx] & 0x0003) == active_mask_debounce[btn_idx])
	{
		steady_state[btn_idx] = active_val[btn_idx];
		return active_val[btn_idx];
	}

	// continuous not pressed state
	if ((state[btn_idx] & 0x0003) == idle_mask_debounce[btn_idx])
	{
		steady_state[btn_idx] = idle_val[btn_idx];
		return idle_val[btn_idx];
	}

	// none of the above; glitch input that got filtered
	return steady_state[btn_idx];
}
