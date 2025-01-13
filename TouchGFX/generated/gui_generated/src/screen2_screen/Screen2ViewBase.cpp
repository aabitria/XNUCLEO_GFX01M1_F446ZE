/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

Screen2ViewBase::Screen2ViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_CIRCLES_VORTEX_ABSTRACTION_1239570_320X240_ID));
    add(image1);
}

Screen2ViewBase::~Screen2ViewBase()
{

}

void Screen2ViewBase::setupScreen()
{

}

void Screen2ViewBase::handleKeyEvent(uint8_t key)
{
    if(1 == key)
    {
        //Interaction1
        //When hardware button 1 clicked change screen to Screen3
        //Go to Screen3 with no screen transition
        application().gotoScreen3ScreenNoTransition();
    
    }

    if(2 == key)
    {
        //Interaction2
        //When hardware button 2 clicked change screen to Screen1
        //Go to Screen1 with no screen transition
        application().gotoScreen1ScreenNoTransition();
    
    }
}