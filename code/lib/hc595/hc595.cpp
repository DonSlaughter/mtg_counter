#include <Arduino.h>
#include "hc595.h"

hc595::hc595(uint8_t latch_pin, uint8_t clock_pin, uint8_t data_pin)
{
	_latch_pin = latch_pin;
	_clock_pin = clock_pin;
	_data_pin = data_pin;
	pinMode(_latch_pin, OUTPUT);
	pinMode(_clock_pin, OUTPUT);
	pinMode(_data_pin, OUTPUT);
}

void hc595::write_phase_led(uint16_t shift_value)
{
	uint16_t _mask = 1;
	uint16_t _write_value[16];
	for (uint16_t i = 0; i <= 15; i++){
		if ((shift_value & _mask) != 0) {
			_write_value[i] = 1;
		}
		else {
			_write_value[i] = 0;
		}
		_mask = _mask << 1;
	}
	digitalWrite(_latch_pin, LOW);
	shiftOut(_data_pin, _clock_pin, MSBFIRST, _write_value);
	digitalWrite(_latch_pin, HIGH);
}
