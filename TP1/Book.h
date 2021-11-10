#pragma once
#include "Keeper.h"

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
	void getInfo();
	void setInfo(std::string name, std::string author, int year, std::string annotation, 
				std::string genre, int pages, float price);
	void editInfo(char ind);
};