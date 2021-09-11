#include "My_double.h"
#include <conio.h>
void My_double::calculate()
{
	uint32_t* c = (uint32_t*)(&value);

	first = *c;
	second = *(c + 1);

	for (int i = 0; i < 32; i++)
	{
		bits[31 - i] = (second >> i) & 1;//((second << i) & 0x80000000) >> 31;
	}
	for (int i = 0; i < 32; i++)
	{
		
		
		bits[31 - i + 32] = (first >> i) & 1;//((first << i) & 0x80000000) >> 31;
	}
}

void My_double::show_bits()
{
	std::cout << "\x1b[31m";
	std::cout << bits[0];
	std::cout << "\x1b[32m";
	for (int i = 1; i < 12; i++)
	{
		std::cout << bits[i];
	}
	std::cout << "\x1b[36m";
	for (int i = 12; i < 64; i++)
	{
		std::cout << bits[i];
	}
	std::cout << "\x1b[0m";

}

void My_double::change_bits()
{
	//std::cout << "\n" << first << " " << second << "\n";
	int begin = 0;
	int quantity = 0;

	std::cout << "\nEnter the start point to continue: ";
	std::cin >> begin;
	while (begin < 1 || begin > 64)
	{
		std::cout << "\x1b[31mFail, try again: ";
		std::cin >> begin;
	}
	std::cout << "\x1b[0m";

	std::cout << "Enter the quantity of bits you plan to change: ";
	std::cin >> quantity;
	while (quantity < 1 || quantity > 65 - begin)
	{
		std::cout << "\x1b[31mFail, try again: ";
		std::cin >> quantity;
	}
	std::cout << "\x1b[0m";
	std::cout << "Enter new values:\n\n";
	show_bits();
	std::cout << "\n\x1b[2A";
	for (int i = 0; i < begin - 1; i++)
	{
		std::cout << ' ';
	}
	char bit = 0;
	std::cout << "\x1b[33m";
	for (int i = 0; i < quantity; i++)
	{
		bit = _getch();
		bits[begin - 1 + i] = bit - '0';
		if ((begin - 1 + i) < 31)
		{
			if(bit - '0' == 1)
				second |= (1 << 32 - begin - i);
			else
				second &= ~(1 << 32 - begin - i);
		}
		else
		{
			if (bit - '0' == 1)
				first |= (1 << 64 - begin - i);
			else
				first &= ~(1 << 64 - begin - i);
		}
		std::cout << bit;
	}
	std::cout << "\x1b[0m\n\n";
	//std::cout << "\n" << first << " " << second << "\n";


	uint32_t shoot_in_the_leg[2];
	shoot_in_the_leg[0] = first;
	shoot_in_the_leg[1] = second;

	double* p_new_value = (double*)shoot_in_the_leg;
	value = *p_new_value;

	std::cout << "New value will be: \x1b[32m";
	std::cout << value;
	std::cout << "\x1b[0m\n";
}
