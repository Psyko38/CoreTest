#include "ScreenDriver.h"

M5Canvas canvas(&M5Cardputer.Display);

void ScreenDriver::begin()
{
    canvas.createSprite(
        M5Cardputer.Display.width(),
        M5Cardputer.Display.height());
}

void ScreenDriver::update(uint8_t brightness, uint8_t textSize, uint16_t textColor, uint16_t backgroundColor)
{
    canvas.pushSprite(0, 0);
    M5Cardputer.Display.setBrightness(brightness);
    canvas.setTextSize(textSize);
    canvas.setTextColor(textColor);
    canvas.fillRect(0, 0, canvas.width(), canvas.height(), backgroundColor);
}

void ScreenDriver::drawRect(int16_t baseX, int16_t baseY, int16_t TargetX, int16_t TargetY, uint16_t Incolor, uint16_t BorderSize, uint16_t BorderColor)
{
    canvas.fillRect(baseX, baseY, TargetX, TargetY, Incolor);
    canvas.drawRect(baseX - BorderSize, baseY - BorderSize, TargetX + (2 * BorderSize), TargetY + (2 * BorderSize), BorderColor);
}

void ScreenDriver::drawString(const String &text, int16_t x, int16_t y, uint16_t textColor, uint16_t backgroundColor, uint8_t textSize)
{
    canvas.setTextColor(textColor, backgroundColor);
    canvas.setTextSize(textSize);
    canvas.drawString(text, x, y);
}