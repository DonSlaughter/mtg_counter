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
	_shift_value = 0;
}

void hc595::update_phases(int8_t direction)
{
	//turn Phase Leds off
	if (direction == 127){
		_shift_value = 0;
	}
	//move Led to next Phase
	else if (direction == 1){
		if (_shift_value == 0){
			_shift_value =1;
		}
		else {
			_shift_value = _shift_value << 1;
			if (_shift_value == 4096) _shift_value = 1;
		}
	}
	//move Led to previous Phase
	else if (direction == -1){
		if (_shift_value == 1) {
			_shift_value = 2048;
		}
		else {
			_shift_value = _shift_value >> 1;
		}
	}
	write_phase_led(_shift_value);
}

void hc595::write_phase_led(uint16_t _shift_value)
{
	digitalWrite(_latch_pin, LOW);
	shiftOut(_data_pin, _clock_pin, MSBFIRST, _shift_value >>8);
	shiftOut(_data_pin, _clock_pin, MSBFIRST, _shift_value);
	digitalWrite(_latch_pin, HIGH);
}
