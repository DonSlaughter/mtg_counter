#ifndef hc595_h
#define hc595_h

class hc595
{
	public:
		hc595(uint8_t latch_pin, uint8_t clock_pin, uint8_t data_pin);
		void read_value(uint8_t shift_value);
		void read_value(uint16_t shift_value);
		void shiftreg_out();
	private:
		uint8_t _latch_pin;
		uint8_t _clock_pin;
		uint8_t _data_pin;
};
#endif
