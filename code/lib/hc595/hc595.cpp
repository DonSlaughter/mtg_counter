#include <Arduino.h>
#include "hc595.h"

hc595::hc595(uint8_t latch_pin, uint8_t clock_pin, uint8_t data_pin)
{
	_latch_pin = latch_pin;
	_clock_pin = clock_pin;
	_data_pin = data_pin;
	_shift_value = 0;
	pinMode(_latch_pin, OUTPUT);
	pinMode(_clock_pin, OUTPUT);
	pinMode(_data_pin, OUTPUT);
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
	write_out(_shift_value);
}
void hc595::update_display(uint8_t number_1, uint8_t number_2)
{
	const byte numbers[10] = {
		//DP,g,f,e,d,c,b,a
		0b00111111, // 0
		0b00000110, // 1
		0b01011011, // 2
		0b01001111, // 3
		0b01100110, // 4
		0b01101101, // 5
		0b01111101, // 6
		0b00000111, // 7
		0b01111111, // 8
		0b01101111  // 9
	};

	//write_out(numbers[ones]);
	digitalWrite(_latch_pin, LOW);
	shiftOut(_data_pin, _clock_pin, MSBFIRST, numbers[number_1]>>8);
	shiftOut(_data_pin, _clock_pin, MSBFIRST, numbers[number_2]);
	digitalWrite(_latch_pin, HIGH);

}

void hc595::write_out(uint16_t _shift_value)
{
	digitalWrite(_latch_pin, LOW);
	shiftOut(_data_pin, _clock_pin, MSBFIRST, _shift_value >>8);
	shiftOut(_data_pin, _clock_pin, MSBFIRST, _shift_value);
	digitalWrite(_latch_pin, HIGH);
}
