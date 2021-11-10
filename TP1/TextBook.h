#pragma once
#include "Keeper.h"

class TextBook :public Bookstore {
private:
	std::string name;
	std::string author;
	int year;
	std::string educat_instit;
	int year_training;
	int pages;
	float price;
public:
	void getInfo();
	void setInfo(std::string name,	std::string author,	int year,	std::string educat_instit,	int year_training,
	int pages,	float price);
	void editInfo(char ind);
};