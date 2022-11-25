#include <Arduino.h>
#include "cd4028.h"

cd4028::cd4028(uint8_t encoder_a, uint8_t encoder_b, uint8_t encoder_c, uint8_t encoder_d)
{
	_encoder_a = encoder_a;
	_encoder_b = encoder_b;
	_encoder_c = encoder_c;
	_encoder_d = encoder_d;
	pinMode(_encoder_a,OUTPUT);
	pinMode(_encoder_b,OUTPUT);
	pinMode(_encoder_c,OUTPUT);
	pinMode(_encoder_d,OUTPUT);
}

void cd4028::display(uint8_t disp_nr)
{
	if (disp_nr == 0) {
		digitalWrite(_encoder_a, HIGH);
		digitalWrite(_encoder_b, HIGH);
		digitalWrite(_encoder_c, HIGH);
		digitalWrite(_encoder_d, HIGH);
	}
	else if (disp_nr == 1) {
		digitalWrite(_encoder_a, LOW);
		digitalWrite(_encoder_b, LOW);
		digitalWrite(_encoder_c, LOW);
		digitalWrite(_encoder_d, LOW);
	}
	else if (disp_nr == 2) {
		digitalWrite(_encoder_a, HIGH);
		digitalWrite(_encoder_b, LOW);
		digitalWrite(_encoder_c, LOW);
		digitalWrite(_encoder_d, LOW);
	}
	else if (disp_nr == 3) {
		digitalWrite(_encoder_a, LOW);
		digitalWrite(_encoder_b, HIGH);
		digitalWrite(_encoder_c, LOW);
		digitalWrite(_encoder_d, LOW);
	}
	else if (disp_nr == 4) {
		digitalWrite(_encoder_a, HIGH);
		digitalWrite(_encoder_b, HIGH);
		digitalWrite(_encoder_c, LOW);
		digitalWrite(_encoder_d, LOW);
	}
	else if (disp_nr == 5) {
		digitalWrite(_encoder_a, HIGH);
		digitalWrite(_encoder_b, LOW);
		digitalWrite(_encoder_c, HIGH);
		digitalWrite(_encoder_d, LOW);
	}
	else if (disp_nr == 6) {
		digitalWrite(_encoder_a, LOW);
		digitalWrite(_encoder_b, HIGH);
		digitalWrite(_encoder_c, HIGH);
		digitalWrite(_encoder_d, LOW);
	}
	else if (disp_nr == 7) {
		digitalWrite(_encoder_a, HIGH);
		digitalWrite(_encoder_b, HIGH);
		digitalWrite(_encoder_c, HIGH);
		digitalWrite(_encoder_d, LOW);
	}
	else if (disp_nr == 8) {
		digitalWrite(_encoder_a, LOW);
		digitalWrite(_encoder_b, LOW);
		digitalWrite(_encoder_c, LOW);
		digitalWrite(_encoder_d, HIGH);
	}

}
