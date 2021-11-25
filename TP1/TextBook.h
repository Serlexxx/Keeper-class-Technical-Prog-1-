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
	TextBook();
	std::string getInfo() override;
	int setInfo(int ind, std::string str) override;
	void editInfo(int ind) override;
	~TextBook() override;
};