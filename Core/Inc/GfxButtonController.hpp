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
	virtual void init() {}

	virtual bool sample (uint8_t& key);
};


#endif /* INC_GFXBUTTONCONTROLLER_HPP_ */
