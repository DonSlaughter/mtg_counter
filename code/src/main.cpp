#include <Arduino.h>

//Pin declarations
//Shiftregister 74hc595n
int serial_data_output = PB0;
int shift_register_clock = PB2;
int storage_register_clock = PB1;

//Transitor to switch digits on and off
int transistor_r = PC0;
int transistor_m = PC1;
int transistor_l = PC2;

const byte numbers[10] = {
	0b11111100, // 0
	0b01100000, // 1
	0b11011010, // 2
	0b11110010, // 3
	0b01100110, // 4
	0b10110110, // 5
	0b10111110, // 6
	0b11100000, // 7
	0b11111110, // 8
	0b11110110  // 9
};

void setup(){
	pinMode(serial_data_output, OUTPUT);
	pinMode(shift_register_clock, OUTPUT);
	pinMode(storage_register_clock, OUTPUT);
	pinMode(transistor_l, OUTPUT);
	pinMode(transistor_m, OUTPUT);
	pinMode(transistor_r, OUTPUT);
}

void loop(){
//	digitalWrite(storage_register_clock,LOW);
//	shiftOut(serial_data_output, shift_register_clock, LSBFIRST, numbers[0]);
//	digitalWrite(storage_register_clock,HIGH);
//	delay(1000);
	digitalWrite(transistor_l, HIGH);
	digitalWrite(transistor_m, HIGH);
	digitalWrite(transistor_r, HIGH);
	for (byte i=0; i<sizeof(numbers); i++) {
		digitalWrite(storage_register_clock, LOW);
		shiftOut(serial_data_output, shift_register_clock, LSBFIRST, numbers[i]);
		digitalWrite(storage_register_clock, HIGH);
		delay(1000);
	}
}
