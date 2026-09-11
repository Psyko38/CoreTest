#pragma once

#include <M5Cardputer.h>

class KeyboardDriver
{
public:
    class Key
    {
    public:
        bool backspace();
        bool del();
        bool enter();
        bool shift();
        bool ctrl();
        bool alt();
        bool fn();
        bool opt();

    private:
        friend class KeyboardDriver;
        Keyboard_Class::KeysState *_status = nullptr;
    };

    class is
    {
    public:
        bool Change();
        bool Pressed();

    private:
        friend class KeyboardDriver;
        KeyboardDriver *_keyboard = nullptr;
    };

    Key key;
    is is;

    void begin();
    void update();

    String text();

private:
    Keyboard_Class::KeysState _status;
};