#ifndef hc165_h
#define hc165_h

class hc165
{
	public:
		hc165(uint8_t parallel_load_pin, uint8_t clock_enable_pin, uint8_t clock_pin, uint8_t serial_out_pin);
		byte read_value();
	private:
		void _clock();
		void _load();
		uint8_t _parallel_load_pin;
		uint8_t _clock_enable_pin;
		uint8_t _clock_pin;
		uint8_t _serial_out_pin;
};
#endif
