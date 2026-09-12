#include <Arduino.h>
#include <M5Cardputer.h>
#include "driver/keyboard/KeyboardDriver.h"
#include "driver/screen/ScreenDriver.h"

KeyboardDriver Keyboard;
ScreenDriver Screen;

String data = "Hello, World!";
int x = 0;
int y = 0;

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
  Keyboard.update();
  Screen.update(100, RED);
  // Screen.drawString(data, 4, M5Cardputer.Display.height() - 24, WHITE, BLACK, 2);
  Screen.drawTriangle(60, 60, 100, 100, 50, WHITE, 2, BLACK);
  y = (y + 1) % M5Cardputer.Display.height();
  x = (x + 1) % M5Cardputer.Display.width();
  Screen.drawRect(x, y, x + 50, y + 50, WHITE, 2, BLACK);
  Screen.drawString(String(x) + " / " + String(y) + " to " + String(x + 50) + " / " + String(y + 50), 2, M5Cardputer.Display.height() - 10 * 2, WHITE, BLACK, 2);
  Screen.drawString(data, 4, M5Cardputer.Display.height() - 10 * 4, WHITE, BLACK, 2);

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