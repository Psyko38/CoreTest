#pragma once

#include <M5Cardputer.h>

class ScreenDriver
{
public:
    void begin();
    void update(uint8_t brightness, uint8_t textSize, uint16_t textColor, uint16_t backgroundColor);
    void drawRect(int16_t baseX, int16_t baseY, int16_t TargetX, int16_t TargetY, uint16_t Incolor, uint16_t BorderSize, uint16_t BorderColor);
    void drawString(const String &text, int16_t x, int16_t y, uint16_t textColor, uint16_t backgroundColor, uint8_t textSize);
};