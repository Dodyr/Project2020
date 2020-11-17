#include "Header.h"

void Init(TList& list)
{
	list = NULL;
}

void Add(TList& list, int new_element)
{
	TList p = new NODE;
	p->info = new_element;
	p->next = list;
	list = p;
}

void Create_as_Queue(TList& list, std::ifstream& file)
{
	Init(list);
	int x;
	file >> x;
	Add(list, x);
	TList tail = list;
	while (!file.eof())
	{
		file >> x;
		Add(tail->next, x);
		tail = tail->next;
	}
}

void Print(TList list)
{
	TList p = list;
	while (p != NULL)
	{
		std::cout << p->info << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

bool Emply(TList list)
{
	return list == NULL;
}

void Delete(TList& list)
{
	TList p = list;
	list = p->next;
	p->next = NULL;
	delete p;
}

void Clear(TList& list)
{
	while (!Emply(list))
		Delete(list);
}

void Create_Order(TList& list, std::ifstream& fin)
{
	Init(list);
	int x;
	fin >> x;
	Add(list, x);
	while (!fin.eof())
	{
		fin >> x;
		if (x < list->info)
			Add(list, x);
		else
		{
			TList place = Found_place(list, x);
			Add(place->next, x);
		}
	}
}

TList Found_place(TList list, int x)
{
	while (list->next && list->next->info < x)
		list = list->next;
	return list;
}

void print(TList list, std::ofstream& fout, bool bo)
{
	TList p = list;
	while (p != NULL)
	{
		fout << p->info << " ";
		p = p->next;
	}
	if (!bo)
	{
		fout << std::endl << "Ќечетных чисел в последовательности нету.";
	}
	fout << std::endl;
}