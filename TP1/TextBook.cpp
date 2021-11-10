#include "TextBook.h"


void TextBook::setInfo(std::string name, std::string author, int year, std::string educat_instit, int year_training,
	int pages, float price) {
	this->name = name;
	this->author = author;
	this->year = year;
	this->educat_instit;
	this->year_training = year_training;
	this->pages = pages;
	this->price = price;
}

void TextBook::getInfo() {
	std::cout.setf(10);
	std::cout << name << " || " << author << " || " << year << " || " << educat_instit << std::endl <<
		year_training << " || " << pages << " || " << price;
}

void TextBook::editInfo() {
	std::cout << "¬ведите число 1..7\n";
	int ind;
	if((std:: cin >> ind) >=1 && 
	switch (ind)
	{
	case '1':
		std::cin >> name;
		break;
	case'2':
		std::cin >> author;
		break;
	case '3':
		std::cin >> year;
		break;
	case '4':
		std::cin >> educat_instit;
		break;
	case '5':
		std::cin >> year_training;
		break;
	case '6':
		std::cin >> pages;
		break;
	case '7':
		std::cin >> price;
		break;
	}
}