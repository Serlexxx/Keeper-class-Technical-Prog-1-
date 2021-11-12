#pragma once
#include "Bookstore.h"

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
	void getInfo() override;
	void setInfo(int ind, std::string str) override;
	void editInfo(int ind) override;
	~TextBook() override;
};