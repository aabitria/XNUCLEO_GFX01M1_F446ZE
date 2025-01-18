/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/datadisplay_screen/DataDisplayViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DataDisplayViewBase::DataDisplayViewBase()
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 320, 240);
    box1.setColor(touchgfx::Color::getColorFromRGB(225, 245, 239));
    add(box1);

    box2.setPosition(0, 0, 320, 35);
    box2.setColor(touchgfx::Color::getColorFromRGB(150, 212, 250));
    add(box2);

    textArea1.setXY(32, 5);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(250, 113, 7));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_TITLE));
    add(textArea1);

    circle1.setPosition(70, 47, 180, 180);
    circle1.setCenter(90, 90);
    circle1.setRadius(90);
    circle1.setLineWidth(0);
    circle1.setArc(-120, 120);
    circle1Painter.setColor(touchgfx::Color::getColorFromRGB(44, 199, 67));
    circle1.setPainter(circle1Painter);
    add(circle1);

    circle2.setPosition(90, 67, 140, 140);
    circle2.setCenter(70, 70);
    circle2.setRadius(65);
    circle2.setLineWidth(0);
    circle2.setArc(0, 360);
    circle2Painter.setColor(touchgfx::Color::getColorFromRGB(225, 245, 239));
    circle2.setPainter(circle2Painter);
    add(circle2);

    textArea2.setXY(115, 111);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_DBTK).getText());
    textArea2.setWildcard(textArea2Buffer);
    textArea2.resizeToCurrentText();
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W5ED));
    add(textArea2);
}

DataDisplayViewBase::~DataDisplayViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void DataDisplayViewBase::setupScreen()
{

}

void DataDisplayViewBase::handleKeyEvent(uint8_t key)
{
    if(1 == key)
    {
        //Interaction1
        //When hardware button 1 clicked change screen to Screen1
        //Go to Screen1 with no screen transition
        application().gotoScreen1ScreenNoTransition();
    
    }

    if(2 == key)
    {
        //Interaction2
        //When hardware button 2 clicked change screen to Screen5
        //Go to Screen5 with no screen transition
        application().gotoScreen5ScreenNoTransition();
    
    }
}
