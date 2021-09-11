#pragma once
class My_uint
{
private:
	unsigned int value;
	unsigned int bits[32];
	void calculate();
	
public:
	My_uint(unsigned int _value) : value(_value), bits{}
	{
		calculate();
	}
	void change_bits();
	void show_bits();
	
};

