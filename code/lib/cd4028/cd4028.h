#ifndef cd4028_h
#define cd4028_h

class cd4028
{
	public:
		cd4028(uint8_t encoder_a, uint8_t encoder_b, uint8_t encoder_c, uint8_t encoder_d);
		void display(uint8_t disp_nr);
	private:
		uint8_t _encoder_a;
		uint8_t _encoder_b;
		uint8_t _encoder_c;
		uint8_t _encoder_d;
};
#endif
