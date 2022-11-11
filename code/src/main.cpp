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

led led_01(led_pin_01);
led led_02(led_pin_02);

//Classes
hc165 led_row(parallel_load_1, clock_enable_1, clock_1, button_serial_out_1);

byte test;



void setup()
{
	Serial.begin(9600);
}

void loop()
{
	test = led_row.read_value();
	Serial.print(test, BIN);
	delay(500);
}


void error(){

}
