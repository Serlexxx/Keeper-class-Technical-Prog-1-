#pragma once
#include <iostream>
#include <string>
#include <iomanip>
class Bookstore {
private:
	Bookstore* data;
	int size;
public:
	Bookstore();
	Bookstore(int length);
	~Bookstore();
	void Remove();
	Bookstore& operator [](int ind);
	int getSize();
	void realloCate(int newSize);
	void reSize(int newSize);
	void addElement(Bookstore* element, int ind);
	void removeElement(int ind);

	virtual void getInfo() = 0;
	virtual void setInfo() = 0;
	virtual void editInfp() = 0;


};