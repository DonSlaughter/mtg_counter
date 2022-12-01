#include <Arduino.h>
#include "hc165.h"

hc165::hc165(uint8_t parallel_load_pin, uint8_t clock_enable_pin, uint8_t clock_pin, uint8_t serial_out_pin){
	_parallel_load_pin = parallel_load_pin;
	_clock_enable_pin = clock_enable_pin;
	_clock_pin = clock_pin;
	_serial_out_pin = serial_out_pin;
	pinMode(_parallel_load_pin, OUTPUT);
	pinMode(_clock_enable_pin, OUTPUT);
	pinMode(_clock_pin, OUTPUT);
	pinMode(_serial_out_pin, INPUT);
}

void hc165::_clock()
{
	digitalWrite(_clock_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(_clock_pin, LOW);
	delayMicroseconds(5);
}

void hc165::_load()
{
	digitalWrite(_parallel_load_pin, LOW);
	delayMicroseconds(5);
	digitalWrite(_parallel_load_pin, HIGH);
	delayMicroseconds(5);

}

byte hc165::read_value()
{
	_load();

	digitalWrite(_clock_enable_pin, LOW);

	for (uint8_t i = 0; i < 8; i++) {
		_incomming |= digitalRead(_serial_out_pin) << (7-i);
		_clock();
	}
	digitalWrite(_clock_enable_pin, HIGH);
	if (_incomming == _old_incomming) {
		_incomming = 0;
	}
	else {
		_old_incomming = _incomming;
	}
	return _incomming;
}
