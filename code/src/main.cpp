#include <Arduino.h>
#include "led.h"
#include "hc165.h"
#include "hc595.h"
#include "pins_arduino.h"

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

//Display 1 HC595
const uint8_t ser_data_disp_1 = PIN_PB0;
const uint8_t shift_reg_disp_1 = PIN_PB1;
const uint8_t latch_pin_disp_1 = PIN_PB2;

//Dezimal Decoder
const uint8_t dec_encoder_a = PIN_PA0;
const uint8_t dec_encoder_b = PIN_PA1;
const uint8_t dec_encoder_c = PIN_A2;
const uint8_t dec_encoder_d = PIN_A3;

led led_01(led_pin_01);
led led_02(led_pin_02);

//Classes
hc165 bottom_row(parallel_load_1, clock_enable_1, clock_1, button_serial_out_1);
hc595 phases(latch_pin_led, shift_reg_led, ser_data_led);
hc595 display_1(latch_pin_disp_1, shift_reg_disp_1, ser_data_disp_1);

void setup()
{
	Serial.begin(9600);
	phases.update_phases(0);
	led_01.on();
	pinMode(dec_encoder_a, OUTPUT);
	pinMode(dec_encoder_b, OUTPUT);
	pinMode(dec_encoder_c, OUTPUT);
	pinMode(dec_encoder_d, OUTPUT);
}

void loop()
{
	//delayMicroseconds(5);
	digitalWrite(dec_encoder_a, HIGH);
	digitalWrite(dec_encoder_b, HIGH);
	//delayMicroseconds(5);
//	digitalWrite(dec_encoder_b, LOW);
//	digitalWrite(dec_encoder_c,HIGH);
//	digitalWrite(dec_encoder_d, HIGH);
	//led_01.toggle();
	//led_02.toggle();
//	byte test = bottom_row.read_value();
//	if (test == 1) {
//		phases.update_phases(1);
//	}
//	else if (test == 2) {
//		phases.update_phases(-1);
//	}
//	test = 0;
	display_1.update_phases(1);
	delay(100);
}
