#include <Arduino.h>

//Pin declarations
//Shiftregister 74hc595n
int serial_data_output = PIN_PB0;
int shift_register_clock = PIN_PB2;
int storage_register_clock = PIN_PB1;

int parallel_load = PIN_PD1;
int clock = PIN_PD0;
int clock_enable =  PIN_PD2;
int serial_out = PIN_PD3;

//Transitor to switch digits on and off
int transistor_r = PIN_PC0;
int transistor_m = PIN_PC1;
int transistor_l = PIN_PC2;

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

unsigned long readShiftRegisters();
void printByte();

unsigned long pinValues, oldPinValues;

void setup(){
	pinMode(serial_data_output, OUTPUT);
	pinMode(shift_register_clock, OUTPUT);
	pinMode(storage_register_clock, OUTPUT);
	pinMode(parallel_load, OUTPUT);
	pinMode(clock, OUTPUT);
	pinMode(clock_enable,OUTPUT);
	pinMode(serial_out, INPUT);
	pinMode(transistor_l, OUTPUT);
	pinMode(transistor_m, OUTPUT);
	pinMode(transistor_r, OUTPUT);

	digitalWrite(clock_enable, LOW);
	digitalWrite(parallel_load, HIGH);
}

void loop(){
	digitalWrite(transistor_l, HIGH);
	digitalWrite(transistor_m, LOW);
	digitalWrite(transistor_r, LOW);
	pinValues = readShiftRegisters();
	if (pinValues != oldPinValues) {
		//printByte();
		oldPinValues = pinValues;
	}
	digitalWrite(storage_register_clock, LOW);
	shiftOut(serial_data_output, shift_register_clock, LSBFIRST, pinValues);
	digitalWrite(storage_register_clock, HIGH);
	//delay(1000);
//	for (byte i=0; i<sizeof(numbers); i++) {
//		digitalWrite(storage_register_clock, LOW);
//		shiftOut(serial_data_output, shift_register_clock, LSBFIRST, numbers[i]);
//		digitalWrite(storage_register_clock, HIGH);
//		delay(1000);
//	}
}

unsigned long readShiftRegisters()
{
	long bitVal;
	unsigned long bytesVal = 0;

	digitalWrite(clock_enable, HIGH);
	digitalWrite(parallel_load, LOW);
	delayMicroseconds(5);
	digitalWrite(parallel_load, HIGH);
	digitalWrite(clock_enable, LOW);

	for (byte i = 0; i < 7; i++) {
		bitVal = digitalRead(serial_out);
		bytesVal |= (bitVal << ((8 - 1) - i));

		digitalWrite(clock, HIGH);
		delayMicroseconds(5);
		digitalWrite(clock, LOW);
	}

	return (bytesVal);
}

//void printByte()
//{
//	for (byte i = 0; i <=7; i++){
