#include <Arduino.h>
#include "led.h"

led::led(uint8_t led_pin){
	_led_pin = led_pin;
	pinMode(_led_pin, OUTPUT);
}

void led::on(){
	digitalWrite(_led_pin, HIGH);
	return;
}

void led::off(){
	digitalWrite(_led_pin, LOW);
	return;
}
