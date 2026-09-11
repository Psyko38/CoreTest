#include "ScreenDriver.h"

void ScreenDriver::begin()
{
}

void ScreenDriver::update(uint8_t brightness, uint8_t textSize, uint16_t textColor, uint16_t backgroundColor)
{
    M5Cardputer.Display.setBrightness(brightness);
    M5Cardputer.Display.setTextSize(textSize);
    M5Cardputer.Display.setTextColor(textColor);
    M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), backgroundColor);
}

void ScreenDriver::drawRect(int16_t baseX, int16_t baseY, int16_t TargetX, int16_t TargetY, uint16_t Incolor, uint16_t BorderSize, uint16_t BorderColor)
{
    M5Cardputer.Display.fillRect(baseX, baseY, TargetX, TargetY, Incolor);
    M5Cardputer.Display.drawRect(baseX - BorderSize, baseY - BorderSize, TargetX + (2 * BorderSize), TargetY + (2 * BorderSize), BorderColor);
}

void ScreenDriver::drawString(const String& text, int16_t x, int16_t y, uint16_t textColor, uint16_t backgroundColor, uint8_t textSize)
{
    M5Cardputer.Display.setTextColor(textColor, backgroundColor);
    M5Cardputer.Display.setTextSize(textSize);
    M5Cardputer.Display.drawString(text, x, y);
}