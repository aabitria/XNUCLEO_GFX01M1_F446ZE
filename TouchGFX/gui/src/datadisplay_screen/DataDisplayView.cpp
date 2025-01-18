#include <gui/datadisplay_screen/DataDisplayView.hpp>
#include <touchgfx/widgets/canvas/CWRUtil.hpp>
#include "string.h"
#include "stdio.h"


DataDisplayView::DataDisplayView()
{

}

void DataDisplayView::setupScreen()
{
    DataDisplayViewBase::setupScreen();
}

void DataDisplayView::tearDownScreen()
{
    DataDisplayViewBase::tearDownScreen();
}

void DataDisplayView::set_display_temp(float temp)
{
	char str[5] = {0};
	int16_t end_arc;

	snprintf(str, sizeof(str), "%.1f", temp);
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, str);
	textArea2.invalidate();

	end_arc = ((int16_t)temp * 240 / 60) - 120;

	circle1.updateArcEnd((int)end_arc);
	circle1.invalidate();
}
