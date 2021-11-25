#pragma once
#include <iostream>
#include <Windows.h>
#include "Bookstore.h"
class Keeper {
private:
	Bookstore** data;
	int size;
public:
	Keeper();
	Keeper(int length);
	~Keeper();
	void Remove();
	Bookstore& operator[](const int ind);
	int getSize();
	void realloCate(int newSize);
	void reSize(int newSize);
	void addElement(Bookstore* element, int ind);
	void removeElement(int ind);
};