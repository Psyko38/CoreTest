#include "ScreenDriver.h"

M5Canvas canvas(&M5Cardputer.Display);

void ScreenDriver::begin()
{
    ::canvas.createSprite(
        M5Cardputer.Display.width(),
        M5Cardputer.Display.height());
}

void ScreenDriver::update(uint8_t brightness, uint16_t backgroundColor)
{
    ::canvas.pushSprite(0, 0);
    M5Cardputer.Display.setBrightness(brightness);
    ::canvas.fillRect(0, 0, ::canvas.width(), ::canvas.height(), backgroundColor);
}

void ScreenDriver::drawRect(int16_t baseX, int16_t baseY, int16_t TargetX, int16_t TargetY, uint16_t Incolor, uint16_t BorderSize, uint16_t BorderColor)
{
    int16_t width = TargetX - baseX;
    int16_t height = TargetY - baseY;
    ::canvas.fillRect(baseX - BorderSize, baseY - BorderSize, width + (2 * BorderSize), height + (2 * BorderSize), BorderColor);
    ::canvas.fillRect(baseX, baseY, width, height, Incolor);
}

void ScreenDriver::drawString(const String &text, int16_t x, int16_t y, uint16_t textColor, uint16_t backgroundColor, uint8_t textSize)
{
    ::canvas.setTextColor(textColor, backgroundColor);
    ::canvas.setTextSize(textSize);
    ::canvas.drawString(text, x, y);
}

void ScreenDriver::drawTriangle(int16_t BaseX, int16_t BaseY, int16_t TargetX, int16_t TargetY, int16_t AngleRatio, uint16_t backgroundColor, uint16_t BorderSize, uint16_t BorderColor)
{
    int16_t AngleX = BaseX + ((TargetX - BaseX) * AngleRatio) / 100;
    ::canvas.fillTriangle(BaseX - BorderSize, TargetY + BorderSize, TargetX + BorderSize, TargetY + BorderSize, AngleX, BaseY - BorderSize, BorderColor);
    ::canvas.fillTriangle(BaseX, TargetY, TargetX, TargetY, AngleX, BaseY, backgroundColor);
}
