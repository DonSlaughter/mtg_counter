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
//byte hc165::read_value()
//{
//
//	digitalWrite(_clock, HIGH);
//	digitalWrite(_clock_enable, LOW);
//	byte incoming = shiftIn(_serial_out, _clock, LSBFIRST);
//	digitalWrite(_clock_enable, HIGH);
//	Serial.println(incoming);
//	byte value;
//	switch (incoming)  {
//		case B10000000:
//			value = 1;
//		case B01000000:
//			value = 2;
//		case B00100000:
//			value = 3;
//		case B00010000:
//			value = 4;
//		case B00001000:
//			value = 5;
//		case B00000100:
//			value = 6;
//		case B00000010:
//			value = 7;
//		case B00000001:
//			value = 8;
//		default:
//			value = 0;
//	}
//	return value;
//}

byte hc165::read_value()
{
	byte incoming = 0;
	_load();

	digitalWrite(_clock_enable_pin, LOW);

	for (uint8_t i = 0; i < 8; i++) {
		incoming |= digitalRead(_serial_out_pin) << (7-i);
		_clock();
	}
	digitalWrite(_clock_enable_pin, HIGH);
	Serial.println(incoming);
	return incoming;
}
