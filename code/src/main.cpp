#include <Arduino.h>
#include "led.h"
#include "hc165.h"
#include "hc595.h"

//Pin declarations
//control LED's
const uint8_t led_pin_01 = PIN_PB3;
const uint8_t led_pin_02 = PIN_PB4;

//Phase and Counter Buttons
const uint8_t parallel_load_1 = PIN_PC4;
const uint8_t clock_enable_1 = PIN_PC6;
const uint8_t clock_1 = PIN_PC5;
const uint8_t button_serial_out_1 = PIN_PC7;

//Phase LED HC595 Pins
const uint8_t ser_data_led = PIN_PD4;
const uint8_t shift_reg_led = PIN_PD5;
const uint8_t latch_pin_led = PIN_PD6;


led led_01(led_pin_01);
led led_02(led_pin_02);

//Classes
hc165 bottom_row(parallel_load_1, clock_enable_1, clock_1, button_serial_out_1);
hc595 phases(latch_pin_led, shift_reg_led, ser_data_led);





void setup()
{
	Serial.begin(9600);
	phases.update_phases(0);
}

void loop()
{
	byte test;
	test = bottom_row.read_value();
	if (test == 1) {
		phases.update_phases(1);
	}
	else if (test == 2) {
		phases.update_phases(-1);
	}
	Serial.println(test);

	delay(500);
}
