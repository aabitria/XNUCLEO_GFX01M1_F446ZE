#ifndef DATADISPLAYVIEW_HPP
#define DATADISPLAYVIEW_HPP

#include <gui_generated/datadisplay_screen/DataDisplayViewBase.hpp>
#include <gui/datadisplay_screen/DataDisplayPresenter.hpp>

class DataDisplayView : public DataDisplayViewBase
{
public:
    DataDisplayView();
    virtual ~DataDisplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void set_display_number(int number);
protected:
};

#endif // DATADISPLAYVIEW_HPP
