#include <Arduino.h>
#include <M5Cardputer.h>
#include "driver/keyboard/KeyboardDriver.h"

KeyboardDriver Keyboard;

String data = "";

void setup()
{
  // Init du clavier
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);

  Keyboard.begin();
}

void loop()
{
  M5Cardputer.update();
  Keyboard.update();

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

    int Height = M5Cardputer.Display.height();
    int Width = M5Cardputer.Display.width();

    // Efface l'ancien texte
    M5Cardputer.Display.fillRect(0, Height - 28, Width, 25, BLACK);

    // désine le nouvaux texte
    M5Cardputer.Display.drawString(data, 4, Height - 24);
  }
  delay(100);
}