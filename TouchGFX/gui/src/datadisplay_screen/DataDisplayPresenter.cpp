#include <gui/datadisplay_screen/DataDisplayView.hpp>
#include <gui/datadisplay_screen/DataDisplayPresenter.hpp>

DataDisplayPresenter::DataDisplayPresenter(DataDisplayView& v)
    : view(v)
{

}

void DataDisplayPresenter::activate()
{

}

void DataDisplayPresenter::deactivate()
{

}

void DataDisplayPresenter::set_temp(float number)
{
    view.set_display_temp(number);
}
