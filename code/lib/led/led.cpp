#include <Arduino.h>
#include "led.h"

led::led(uint8_t led_pin){
	_led_pin = led_pin;
	pinMode(_led_pin, OUTPUT);
}

void led::on(){
	_led_state = HIGH;
	digitalWrite(_led_pin, _led_state);
	return;
}

void led::off(){
	_led_state = LOW;
	digitalWrite(_led_pin, _led_state);
	return;
}

void led::toggle(){
	if (_led_state == LOW) {
		_led_state = HIGH;
		digitalWrite(_led_pin, _led_state);
	}
	else if (_led_state == HIGH) {
		_led_state = LOW;
		digitalWrite(_led_pin, _led_state);
	}
}
