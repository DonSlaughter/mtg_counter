#ifndef hc165_h
#define hc165_h

class hc165
{
	public :
		hc165(uint8_t parallel_load, uint8_t clock_enable, uint8_t clock, uint8_t serial_out);
		byte read_value();
	private:
		uint8_t _parallel_load;
		uint8_t _clock_enable;
		uint8_t _clock;
		uint8_t _serial_out;
};
#endif
