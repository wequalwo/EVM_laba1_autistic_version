#pragma once
#include <iostream>
class My_double
{
private:
	double value;
	uint32_t first;
	uint32_t second;
	uint32_t bits[64];
	void calculate();
public:
	My_double(double _value) : value(_value)
	{
		calculate();
	}
	void show_bits();
	void change_bits();
};

