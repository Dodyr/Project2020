#include <iostream>
#include <fstream>
#include <ctime>

#include "interface.h"
#include "Header.h"

void check(TList& list)
{
	TList p = list;
	while (p != NULL)
	{
		std::cout << p->info << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

bool find_and_kill(TList& list)
{
	bool isOdd = false;
	TList p = list;
	if (p->info % 2 != 0)
	{
		Delete(p);
		isOdd = true;
		while (p && p->info % 2 != 0)
		{
			Delete(p);
		}
		list = p;
	}
	else
	{
		while (p->next && !isOdd)
		{
			if (p->next->info % 2 != 0)
				isOdd = true;
			if (!isOdd)
				p = p->next;
		}
		while (p->next && p->next->info % 2 != 0)
		{
			Delete(p->next);
		}
	}
	return isOdd;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	TList list;
	Init(list);
	std::ifstream fin;
	if (file_open(fin))
	{
		Create_Order(list, fin);
		fin.close();
		check(list);
		bool is_killed = find_and_kill(list);
		std::ofstream fout("output.txt");
		print(list, fout, is_killed);
	}
	return 0;
}