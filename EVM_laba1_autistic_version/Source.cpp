#include "My_double.h"
#include "My_uint.h"
int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "������ �������� ������ ������� 0392, ���. N1, ������������ ������� N 4\n������� �� ������: \n����������� �������� ����� � ���������� �����, ������� double � unsigned int � �������� �� ������ �� ���������� ������������� � �������� ������� ���������.\n�������� � �������� ��������� �� ����� �++, ����������� ������������� ��������.\n���������� � �������� ������������� ��������� ����������� ���������� ����� ������� ���, ����� �������� �� �������, ��� � �� ���������, �������� � ���������� ���� ������ � ������������ ������ ���������������� ���� � �������� ������� ��������� � � ������� ��������� �������\n";
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