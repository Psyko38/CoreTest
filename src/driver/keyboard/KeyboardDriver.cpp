#include "KeyboardDriver.h"

void KeyboardDriver::begin()
{
  update();
}

void KeyboardDriver::update()
{
  M5Cardputer.update();
  _status = M5Cardputer.Keyboard.keysState();

  // Donne au sous-module key accès à l'état actuel
  key._status = &_status;
}

bool KeyboardDriver::Key::backspace()
{
  return _status->backspace;
}

bool KeyboardDriver::Key::del()
{
  return _status->del;
}

bool KeyboardDriver::Key::enter()
{
  return _status->enter;
}

bool KeyboardDriver::Key::shift()
{
  return _status->shift;
}

bool KeyboardDriver::Key::ctrl()
{
  return _status->ctrl;
}

bool KeyboardDriver::Key::alt()
{
  return _status->alt;
}

bool KeyboardDriver::Key::fn()
{
  return _status->fn;
}

bool KeyboardDriver::is::Change()
{
  return M5Cardputer.Keyboard.isChange();
}

bool KeyboardDriver::is::Pressed()
{
  return M5Cardputer.Keyboard.isPressed();
}

bool KeyboardDriver::Key::opt()
{
  return _status->opt;
}

String KeyboardDriver::text()
{
  String result;

  for (auto c : _status.word)
  {
    result += c;
  }

  return result;
}