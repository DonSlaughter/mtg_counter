#ifndef hc595_h
#define hc595_h

class hc595
{
	public:
		hc595(uint8_t latch_pin, uint8_t clock_pin, uint8_t data_pin);
		void update_phases(int8_t direction);
		void update_display(uint16_t number);
	private:
		void write_out(uint16_t shift_value);
		uint8_t _latch_pin;
		uint8_t _clock_pin;
		uint8_t _data_pin;
		uint16_t _shift_value;
};
#endif
