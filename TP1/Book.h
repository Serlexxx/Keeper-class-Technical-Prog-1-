#pragma once
#include "Bookstore.h"

class Book :public Bookstore {
private:
	std::string name;
	std::string author;
	int year;
	std::string annotation;
	std::string genre;
	int pages;
	float price;
public:
	Book();
	std::string getInfo() override;
	int setInfo(int ind, std::string str) override;
	void editInfo(int ind) override;
	~Book() override; 
};