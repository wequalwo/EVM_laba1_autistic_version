#include "My_double.h"
#include "My_uint.h"
int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "Работу выполнил Иванов Серафим 0392, лаб. N1, персональное задание N 4\nЗадание на работу: \nРазработать алгоритм ввода с клавиатуры числе, формата double и unsigned int и показать на экране их внутреннее представление в двоичной системе счисления.\nНаписать и отладить программу на языке С++, реализующую разработанный алгоритм.\nУстановить в заданное пользователем состояние определённое количество рядом стоящих бит, номер младшего из которых, как и всё остальное, вводится с клавиатуры типа данных и последующего вывода преобразованного кода в двоичной системе счисления и в формате исходного данного\n";
	std::cout << "Enter your double value: \x1b[32m";
	double value;
	std::cin >> value;
	std::cout << "\x1b[0m";
	My_double my(value);
	std::cout << "Your nuber at IEEE: \n";
	my.show_bits();
	my.change_bits();

	
	std::cout << "\nEnter your unsigned int value: \x1b[32m";
	unsigned int value2;
	std::cin >> value2;
	std::cout << "\x1b[0m";
	My_uint my2(value2);
	std::cout << "Your nuber at IEEE: \n";
	my2.show_bits();
	my2.change_bits();
}