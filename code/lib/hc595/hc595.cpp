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
