#pragma once
#include "My_uint.h"
#include <iostream>
#include <conio.h>
void My_uint::calculate()
{
	for (int i = 0; i < 32; i++)
	{
		bits[i] = ((value << i) & 0x80000000) >> 31;
	}
}
void My_uint::change_bits()
{
	int begin = 0;
	int quantity = 0;

	std::cout << "\nEnter the start point to continue: ";
	std::cin >> begin;
	while (begin < 1 || begin > 32)
	{
		std::cout << "\x1b[31mFail, try again: ";
		std::cin >> begin;
	}
	std::cout << "\x1b[0m";

	std::cout << "Enter the quantity of bits you plan to change: ";
	std::cin >> quantity;
	while (quantity < 1 || quantity > 33 - begin)
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

		if (bit - '0' == 1)
		{
			value |= (1 << 32 - begin - i);
		}
		else
		{
			value &= ~(1 << 32 - begin - i);
		}
		std::cout << bit;
	}
	std::cout << "\x1b[0m\n\n";

	std::cout << "New value will be: \x1b[32m";
	std::cout << value;
	std::cout << "\x1b[0m\n";
}
void My_uint::show_bits()
{
	std::cout << "\x1b[34m";
	for (int i = 0; i < 32; i++)
	{
		std::cout << bits[i];
	}
	std::cout << "\x1b[0m";
}
