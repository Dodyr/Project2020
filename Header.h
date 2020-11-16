#pragma once

#include <iostream>
#include <fstream>
#include "interface.h"

struct NODE
{
	int info;
	int count = 1;
	NODE* next;
};

typedef NODE* TList;

void Init(TList& list);
void Add(TList& list, int new_element);
void Create_as_Queue(TList& list, std::ifstream& file);
void Print(TList list);
bool Emply(TList list);
void Delete(TList& list);
void Clear(TList& list);
void Create_Order(TList& list, std::ifstream& fin);
TList Found_place(TList list, int x);
void print(TList list, std::ofstream& fout, bool bo);
