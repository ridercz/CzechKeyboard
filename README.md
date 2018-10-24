# Czech Keyboards for Arduino

These libraries are derived from the standard [Keyboard](http://www.arduino.org/learning/reference/mousekeyboard) library of Arduino and are adding support for **Czech (QWERTZ)** and **Czech (QWERTY)** keyboard layout.

The support does not lie in adding characters with Czech diacritic marks, but in allowing to type common non-letter special characters on those keyboards.

## Installation

Download the `CzechKeyboard_QWERTZ.zip` or `CzechKeyboard_QWERTY.zip` file from the [latest release](https://github.com/ridercz/CzechKeyboard/releases/latest). Then use the ZIP import function in Arduino IDE (_Sketch > Include Library > Add .ZIP Library..._).

## Usage

The only change from standard `Keyboard` library is that you have to include `#include "CzechKeyboard_QWERTZ.h"` or `#include "CzechKeyboard_QWERTZ.h"` instead of common `#include "Keyboard.h"`. Nothing else is changed.

## Contributor Code of Conduct

This project adheres to No Code of Conduct. We are all adults. We accept anyone's contributions. Nothing else matters.

For more information please visit the [No Code of Conduct](https://github.com/domgetter/NCoC) homepage.