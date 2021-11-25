#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <Windows.h>
class Bookstore
{
public:
	Bookstore();
	virtual ~Bookstore();
	virtual std::string getInfo() = 0;
	virtual int setInfo(int ind, std::string str) = 0;
	virtual void editInfo(int ind) = 0;
	int getCnt(int ind);
	void setCnt(int ind);
private:
	Bookstore* all;
	int cnt_book;
	int cnt_text;
	int cnt_chance;
};

