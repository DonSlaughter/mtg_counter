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

	return incoming;
}
