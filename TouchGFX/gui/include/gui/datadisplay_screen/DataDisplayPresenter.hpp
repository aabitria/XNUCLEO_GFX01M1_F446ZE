#ifndef DATADISPLAYPRESENTER_HPP
#define DATADISPLAYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DataDisplayView;

class DataDisplayPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DataDisplayPresenter(DataDisplayView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~DataDisplayPresenter() {}

    virtual void set_int(int number);

private:
    DataDisplayPresenter();

    DataDisplayView& view;
};

#endif // DATADISPLAYPRESENTER_HPP
