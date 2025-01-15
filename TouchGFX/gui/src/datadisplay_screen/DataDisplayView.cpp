#include <gui/datadisplay_screen/DataDisplayView.hpp>

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

void DataDisplayView::set_display_number(int number)
{
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%d", number);
	textArea2.invalidate();
}
