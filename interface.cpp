#include "interface.h"

bool file_open(std::ifstream& fin)
{
	bool file_exist = true;
	fin.open("input.txt");
	if (!fin.is_open())
	{
		std::cout << std::endl << "���� � ������ input.txt �� ������. �������������, ��� �� ������������� ������ � ��������� � ������ �����, � ����� ���������� ������������� ���������.";
		file_exist = false;
	}
	else
		std::cout << std::endl << "���� ������.";
	return file_exist;
}

std::string write_name()
{
	std::string name;
	std::cout << std::endl << "������� ��� ����� ��� ������: ";
	std::cin >> name;
	std::cout << std::endl << "���� ������.";
	return name;
}

int enter_menu(int a, int b)
{
	int c, tries = 1;
	std::cin >> c;
	while ((!std::cin.good() || c < a || c > b) && tries < 3)
	{
		tries++;
		std::cout << std::endl << "������. ������� ������������� �������� � ��������� �� " << a << " �� " << b << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> c;
	}
	if (tries > 3)
	{
		std::cout << std::endl << "�� ��������� ����������� ���������� ���������� ������. ��������� ����� ���������.";
		c = b;
	}
	return c;
}

short print_menu()
{
	std::cout << std::endl << std::endl << "�������� ������ ������ ������:"
		<< std::endl << "1. ����� �� �����."
		<< std::endl << "2. ������ � ����." << std::endl << "  -> ";
	short ch = enter_menu(1, 2);
	return ch;
}