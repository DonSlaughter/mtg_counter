#ifndef hc595_h
#define hc595_h

class hc595
{
	public:
		hc595(uint8_t latch_pin, uint8_t clock_pin, uint8_t data_pin);
		void write_phase_led(uint16_t shift_value);
		void shiftreg_out();
	private:
		uint8_t _latch_pin;
		uint8_t _clock_pin;
		uint8_t _data_pin;
};
#endif
