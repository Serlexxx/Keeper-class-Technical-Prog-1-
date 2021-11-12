#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
class Bookstore
{
public:
	Bookstore();
	virtual ~Bookstore();
	virtual void getInfo() = 0;
	virtual void setInfo(int ind, std::string str) = 0;
	virtual void editInfo(int ind) = 0;
};

