#ifndef led_h
#define led_h

class led
{
	public :
		led(uint8_t led_pin);
		void on();
		void off();
		void toggle();
	private:
		uint8_t _led_pin;
		uint8_t _led_state;
};

#endif
