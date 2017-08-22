# Czech Keyboards for Arduino

These libraries are derived from the standard [Keyboard](http://www.arduino.org/learning/reference/mousekeyboard) library of Arduino and are adding support for **Czech (QWERTZ)** and **Czech (QWERTY)** keyboard layout.

The support does not lie in adding characters with Czech diacritic marks, but in allowing to type common non-letter special characters on those keyboards.

## Usage

The only change from standard `Keyboard` library is that you have to include `#include "CzechKeyboard_QWERTZ.h"` or `#include "CzechKeyboard_QWERTZ.h"` instead of common `#include "Keyboard.h"`. Nothing else is changed.