/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

Screen3ViewBase::Screen3ViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_NATURE_LAKE_MOUNTAINS_166874_320X240_ID));
    add(image1);
}

Screen3ViewBase::~Screen3ViewBase()
{

}

void Screen3ViewBase::setupScreen()
{

}

void Screen3ViewBase::handleKeyEvent(uint8_t key)
{
    if(1 == key)
    {
        //Interaction1
        //When hardware button 1 clicked change screen to Screen4
        //Go to Screen4 with no screen transition
        application().gotoScreen4ScreenNoTransition();
    
    }

    if(2 == key)
    {
        //Interaction2
        //When hardware button 2 clicked change screen to Screen2
        //Go to Screen2 with no screen transition
        application().gotoScreen2ScreenNoTransition();
    
    }
}
