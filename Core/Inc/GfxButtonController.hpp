/*
 * GfxButtonController.hpp
 *
 *  Created on: Jan 11, 2025
 *      Author: Lenovo310
 */

#ifndef INC_GFXBUTTONCONTROLLER_HPP_
#define INC_GFXBUTTONCONTROLLER_HPP_

#include <platform/driver/button/ButtonController.hpp>


class GfxButtonController : public touchgfx::ButtonController
{
	virtual void init();

	virtual bool sample (uint8_t& key);

protected:
	uint16_t  active_val[2] = {0, 0};
	uint16_t  idle_val[2] = {1, 1};
	uint16_t  active_mask_debounce[2] = {0x0000, 0x0000};
	uint16_t  idle_mask_debounce[2] = {0x0003, 0x0003};
	uint16_t  steady_state[2] = {1, 1};
	uint16_t  prev_steady_state[2] = {1, 1};
	uint16_t  state[2] = {1, 1};
	uint16_t  raw_val[2];

	uint16_t  num_buttons = 2;
	uint16_t num_run = 0;

	uint16_t  debounce(uint16_t btn_idx);
	uint16_t  detect_press_event(uint16_t btn_idx);
};


#endif /* INC_GFXBUTTONCONTROLLER_HPP_ */
