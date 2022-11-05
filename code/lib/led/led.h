#ifndef led_h
#define led_h

class led
{
	public :
		led(uint8_t led_pin);
		void on();
		void off();
	private:
		uint8_t _led_pin;
};

#endif
