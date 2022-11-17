#include <Arduino.h>
#include "hc165.h"

hc165::hc165(uint8_t parallel_load, uint8_t clock_enable, uint8_t clock, uint8_t serial_out){
	_parallel_load = parallel_load;
	_clock_enable = clock_enable;
	_clock = clock;
	_serial_out = serial_out;
	pinMode(_parallel_load, OUTPUT);
	pinMode(_clock_enable, OUTPUT);
	pinMode(_clock, OUTPUT);
	pinMode(_serial_out, OUTPUT);
}

byte hc165::read_value()
{
	digitalWrite(_parallel_load, LOW);
	delayMicroseconds(5);
	digitalWrite(_parallel_load, HIGH);
	delayMicroseconds(5);

	digitalWrite(_clock, HIGH);
	digitalWrite(_clock_enable, LOW);
	byte incoming = shiftIn(_serial_out, _clock, LSBFIRST);
	digitalWrite(_clock_enable, HIGH);
	byte value;
	switch (incoming)  {
		case B10000000:
			value = 1;
		case B01000000:
			value = 2;
		case B00100000:
			value = 3;
		case B00010000:
			value = 4;
		case B00001000:
			value = 5;
		case B00000100:
			value = 6;
		case B00000010:
			value = 7;
		case B00000001:
			value = 8;
		default:
			value = 0;
	}
	return value;
}
