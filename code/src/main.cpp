#include <Arduino.h>
#include "led.h"
#include "hc165.h"
#include "hc595.h"
#include "cd4028.h"
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

//Display Button Rows

//Phase LED HC595 Pins
const uint8_t ser_data_led = PIN_PD4;
const uint8_t shift_reg_led = PIN_PD5;
const uint8_t latch_pin_led = PIN_PD6;

//Display 1 HC595
const uint8_t ser_data_disp = PIN_PB0;
const uint8_t shift_reg_disp = PIN_PB1;
const uint8_t latch_pin_disp = PIN_PB2;

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
hc595 displays(latch_pin_disp, shift_reg_disp, ser_data_disp);
cd4028 bcd(dec_encoder_a, dec_encoder_b, dec_encoder_c, dec_encoder_d);

uint8_t input_bottom_row;

void setup()
{
	Serial.begin(9600);
	phases.update_phases(1);
	led_01.on();

}

void loop()
{
	input_bottom_row = bottom_row.read_value();
	switch (input_bottom_row) {
		case 1:
			phases.update_phases(1);
			break;
		case 2:
			phases.update_phases(-1);
			break;
		case 4:
			phases.update_phases(127);
			break;
		default:
			break;
	}
	//Display tests:
		bcd.display(1);
		displays.update_display(8,8);
}
