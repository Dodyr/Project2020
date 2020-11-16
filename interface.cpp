#include "interface.h"

bool file_open(std::ifstream& fin)
{
	bool file_exist = true;
	fin.open("input.txt");
	if (!fin.is_open())
	{
		std::cout << std::endl << "Файл с именем input.txt не найден. Удостовертесь, что он действительно создан и находится в нужной папке, а затем попробуйте перезапустить программу.";
		file_exist = false;
	}
	else
		std::cout << std::endl << "Файл открыт.";
	return file_exist;
}

std::string write_name()
{
	std::string name;
	std::cout << std::endl << "Введите имя файла для записи: ";
	std::cin >> name;
	std::cout << std::endl << "Файл создан.";
	return name;
}

int enter_menu(int a, int b)
{
	int c, tries = 1;
	std::cin >> c;
	while ((!std::cin.good() || c < a || c > b) && tries < 3)
	{
		tries++;
		std::cout << std::endl << "Ошибка. Введите целочисленное значение в диапазоне от " << a << " до " << b << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> c;
	}
	if (tries > 3)
	{
		std::cout << std::endl << "Вы превысили максимально допустимое количество ошибок. Программа будет завершена.";
		c = b;
	}
	return c;
}

short print_menu()
{
	std::cout << std::endl << std::endl << "Выберите способ вывода ответа:"
		<< std::endl << "1. Вывод на экран."
		<< std::endl << "2. Запись в файл." << std::endl << "  -> ";
	short ch = enter_menu(1, 2);
	return ch;
}