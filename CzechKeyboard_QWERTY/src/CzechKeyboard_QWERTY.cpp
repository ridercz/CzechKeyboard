/*
  CzechKeyboard_QWERTY.cpp

  Copyright (c) 2015, Arduino LLC
  Copyright (c) 2016, Leon Roux - https://github.com/Nurrl
  Copyright (c) 2017, Martet - https://github.com/Martet
  Copyright (c) 2017, Michal Altair Valasek - https://github.com/ridercz
  
  Original code (pre-library): Copyright (c) 2011, Peter Barrett
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "CzechKeyboard_QWERTY.h"

#if defined(_USING_HID)

//================================================================================
//================================================================================
//  Keyboard

static const uint8_t _hidReportDescriptor[] PROGMEM = {
	//  Keyboard
	0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)  // 47
	0x09, 0x06,                    // USAGE (Keyboard)
	0xa1, 0x01,                    // COLLECTION (Application)
	0x85, 0x02,                    //   REPORT_ID (2)
	0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

	0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
	0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
	0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
	0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
	0x75, 0x01,                    //   REPORT_SIZE (1)

	0x95, 0x08,                    //   REPORT_COUNT (8)
	0x81, 0x02,                    //   INPUT (Data,Var,Abs)
	0x95, 0x01,                    //   REPORT_COUNT (1)
	0x75, 0x08,                    //   REPORT_SIZE (8)
	0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)

	0x95, 0x06,                    //   REPORT_COUNT (6)
	0x75, 0x08,                    //   REPORT_SIZE (8)
	0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
	0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
	0x05, 0x07,                    //   USAGE_PAGE (Keyboard)

	0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
	0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
	0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
	0xc0,                          // END_COLLECTION
};

Keyboard_::Keyboard_(void)
{
	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&node);
}

void Keyboard_::begin(void)
{
}

void Keyboard_::end(void)
{
}

void Keyboard_::sendReport(KeyReport* keys)
{
	HID().SendReport(2, keys, sizeof(KeyReport));
}

extern
const uint8_t _asciimap[128] PROGMEM;

#define SHIFT 0x80
const uint8_t _asciimap[128] =
{
	0x00,			// NUL	0
	0x00,			// SOH	1
	0x00,			// STX	2
	0x00,			// ETX	3
	0x00,			// EOT	4
	0x00,			// ENQ	5
	0x00,			// ACK	6
	0x00,			// BEL	7
	0x2a,			// BS	8
	0x2b,			// TAB	9
	0x28,			// LF 	10
	0x00,			// VT	11
	0x00,			// FF	12
	0x00,			// CR	13
	0x00,			// SO	14
	0x00,			// SI	15
	0x00,			// DEL	16
	0x00,			// DC1	17
	0x00,			// DC2	18
	0x00,			// DC3	19
	0x00,			// DC4	20
	0x00,			// NAK	21
	0x00,			// SYN	22
	0x00,			// ETB	23
	0x00,			// CAN	24
	0x00,			// EM	25
	0x00,			// SUB	26
	0x00,			// ESC	27
	0x00,			// FS	28
	0x00,			// GS	29
	0x00,			// RS	30
	0x00,			// US	31
	0x2c,			// ' '	32
	0x34 | SHIFT,  	// !	33
	0x33 | SHIFT,  	// "	34
	0x20,			// #	35 + AltGr
	0x21,			// $	36 + AltGr
	0x2d | SHIFT,	// %	37
	0x24,			// &	38 + AltGr
	0x31 | SHIFT,	// '	39
	0x30 | SHIFT,	// (	40
	0x30,			// )	41
	0x25,			// *	42 + AltGr
	0x1e,			// +	43
	0x36,			// ,	44
	0x38,			// -	45
	0x37,			// .	46
	0x2f | SHIFT,	// /	47
	0x27 | SHIFT,	// 0	48
	0x1e | SHIFT,	// 1	49
	0x1f | SHIFT,	// 2	50
	0x20 | SHIFT,	// 3	51
	0x21 | SHIFT,	// 4	52
	0x22 | SHIFT,	// 5	53
	0x23 | SHIFT,	// 6	54
	0x24 | SHIFT,	// 7	55
	0x25 | SHIFT,	// 8	56
	0x26 | SHIFT,	// 9	57
	0x37 | SHIFT,	// :	58
	0x35,			// ;	59
	0x36,			// <	60 + AltGr
	0x2d,			// =	61
	0x37,			// >	62 + AltGr
	0x36 | SHIFT,	// ?	63
	0x1f,			// @	64 + AltGr
	0x04 | SHIFT,	// A	65
	0x05 | SHIFT,	// B	66
	0x06 | SHIFT,	// C	67
	0x07 | SHIFT,	// D	68
	0x08 | SHIFT,	// E	69
	0x09 | SHIFT,	// F	70
	0x0a | SHIFT,	// G	71
	0x0b | SHIFT,	// H	72
	0x0c | SHIFT,	// I	73
	0x0d | SHIFT,	// J	74
	0x0e | SHIFT,	// K	75
	0x0f | SHIFT,	// L	76
	0x10 | SHIFT,	// M	77
	0x11 | SHIFT,	// N	78
	0x12 | SHIFT,	// O	79
	0x13 | SHIFT,	// P	80
	0x14 | SHIFT,	// Q	81
	0x15 | SHIFT,	// R	82
	0x16 | SHIFT,	// S	83
	0x17 | SHIFT,	// T	84
	0x18 | SHIFT,	// U	85
	0x19 | SHIFT,	// V	86
	0x1a | SHIFT,	// W	87
	0x1b | SHIFT,	// X	88
	0x1c | SHIFT,	// Y	89
	0x1d | SHIFT,	// Z	90
	0x2f,			// [	91 + AltGr
	0x31,			// bsl	92 + AltGr
	0x30,			// ]	93 + AltGr
	0x23,			// ^	94 + AltGr
	0x38 | SHIFT,	// _	95
	0x35,			// `	96 + AltGr
	0x04,			// a	97
	0x05,			// b	98
	0x06,			// c	99
	0x07,			// d	100
	0x08,			// e	101
	0x09,			// f	102
	0x0a,			// g	103
	0x0b,			// h	104
	0x0c,			// i	105
	0x0d,			// j	106
	0x0e,			// k	107
	0x0f,			// l	108
	0x10,			// m	109
	0x11,			// n	110
	0x12,			// o	111
	0x13,			// p	112
	0x14,			// q	113
	0x15,			// r	114
	0x16,			// s	115
	0x17,			// t	116
	0x18,			// u	117
	0x19,			// v	118
	0x1a,			// w	119
	0x1b,			// x	120
	0x1c,			// y	121
	0x1d,			// z	122
	0x2f | SHIFT,	// {	123 + AltGr
	0x31 | SHIFT,	// |	124 + AltGr
	0x30 | SHIFT,	// }	125 + AltGr
	0x35 | SHIFT,	// ~	126 + AltGr
	0x00			// DEL	127
};
bool _altGrMap[128];
bool _altFine = false;

void initAltGr() {
	_altFine = true;

	_altGrMap[35] = true;
	_altGrMap[36] = true;
	_altGrMap[38] = true;
	_altGrMap[42] = true;
	_altGrMap[60] = true;
	_altGrMap[62] = true;
	_altGrMap[64] = true;
	_altGrMap[91] = true;
	_altGrMap[92] = true;
	_altGrMap[93] = true;
	_altGrMap[94] = true;
	_altGrMap[96] = true;
	_altGrMap[123] = true;
	_altGrMap[124] = true;
	_altGrMap[125] = true;
	_altGrMap[126] = true;
}

uint8_t USBPutChar(uint8_t c);

// press() adds the specified key (printing, non-printing, or modifier)
// to the persistent key report and sends the report.  Because of the way
// USB HID works, the host acts like the key remains pressed until we
// call release(), releaseAll(), or otherwise clear the report and resend.
size_t Keyboard_::press(uint8_t k)
{
	uint8_t i;
	if (k >= 136) {      // it's a non-printing key (not a modifier)
		k = k - 136;
	}
	else if (k >= 128) {  // it's a modifier key
		_keyReport.modifiers |= (1 << (k - 128));
		k = 0;
	}
	else {        // it's a printing key
		int oldKey = k;
		k = pgm_read_byte(_asciimap + k);
		if (!k) {
			setWriteError();
			return 0;
		}
		if (k & 0x80) {					   // it's a capital letter or other character reached with shift
			_keyReport.modifiers |= 0x02;  // the left shift modifier
			k &= 0x7F;
		}

		if (!_altFine) initAltGr();
		if (_altGrMap[oldKey]) _keyReport.modifiers |= 0x40;
	}

	// Add k to the key report only if it's not already present
	// and if there is an empty slot.
	if (_keyReport.keys[0] != k && _keyReport.keys[1] != k &&
		_keyReport.keys[2] != k && _keyReport.keys[3] != k &&
		_keyReport.keys[4] != k && _keyReport.keys[5] != k) {

		for (i = 0; i < 6; i++) {
			if (_keyReport.keys[i] == 0x00) {
				_keyReport.keys[i] = k;
				break;
			}
		}
		if (i == 6) {
			setWriteError();
			return 0;
		}
	}
	sendReport(&_keyReport);
	return 1;
}

// release() takes the specified key out of the persistent key report and
// sends the report.  This tells the OS the key is no longer pressed and that
// it shouldn't be repeated any more.
size_t Keyboard_::release(uint8_t k)
{
	uint8_t i;
	if (k >= 136) {      // it's a non-printing key (not a modifier)
		k = k - 136;
	}
	else if (k >= 128) {  // it's a modifier key
		_keyReport.modifiers &= ~(1 << (k - 128));
		k = 0;
	}
	else {        // it's a printing key
		int oldKey = k;
		k = pgm_read_byte(_asciimap + k);
		if (!k) {
			return 0;
		}
		if (k & 0x80) {              // it's a capital letter or other character reached with shift
			_keyReport.modifiers &= ~(0x02);  // the left shift modifier
			k &= 0x7F;
		}

		if (_altGrMap[oldKey])
			_keyReport.modifiers &= ~(0x40);
	}

	// Test the key report to see if k is present.  Clear it if it exists.
	// Check all positions in case the key is present more than once (which it shouldn't be)
	for (i = 0; i < 6; i++) {
		if (0 != k && _keyReport.keys[i] == k) {
			_keyReport.keys[i] = 0x00;
		}
	}

	sendReport(&_keyReport);
	return 1;
}

void Keyboard_::releaseAll(void)
{
	_keyReport.keys[0] = 0;
	_keyReport.keys[1] = 0;
	_keyReport.keys[2] = 0;
	_keyReport.keys[3] = 0;
	_keyReport.keys[4] = 0;
	_keyReport.keys[5] = 0;
	_keyReport.modifiers = 0;
	sendReport(&_keyReport);
}

size_t Keyboard_::write(uint8_t c)
{
	uint8_t p = press(c);  // Keydown
	release(c);            // Keyup
	return p;              // just return the result of press() since release() almost always returns 1
}

Keyboard_ Keyboard;

#endif

