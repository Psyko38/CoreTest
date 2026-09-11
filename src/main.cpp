#include <Arduino.h>
#include <M5Cardputer.h>
#include "driver/keyboard/KeyboardDriver.h"
#include "driver/screen/ScreenDriver.h"

KeyboardDriver Keyboard;
ScreenDriver Screen;

String data = "Hello, World!";

void setup()
{
  // Init du clavier
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);

  Keyboard.begin();
  Screen.begin();
}

void loop()
{
  M5Cardputer.update();
  Keyboard.update();
  Screen.update(100, 2, WHITE, RED);
  Screen.drawString(data, 4, M5Cardputer.Display.height() - 24, WHITE, BLACK, 2);
  Screen.drawRect(10, 10, 50, 50, WHITE, 2, BLACK);

  if (Keyboard.is.Change() && Keyboard.is.Pressed())
  {

    if (Keyboard.text())
    {
      data += Keyboard.text();
    }

    if (Keyboard.key.backspace() && data.length() > 0)
    {
      data.remove(data.length() - 1);
    }

    if (Keyboard.key.enter())
    {
      data = "";
    }
  }
  delay(100);
}