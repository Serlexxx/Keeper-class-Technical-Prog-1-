#include "Book.h"

void Book::setInfo(std::string name, std::string author, int year, std::string annotation,
	std::string genre, int pages, float price) {
	this->name = name;
	this->author = author;
	this->year = year;
	this->annotation = annotation;
	this->genre = genre;
	this->pages = pages;
	this->price = price;
}

void Book::getInfo() {
	std::cout.setf(10);
	std::cout << name << " || " << author << " || " << year << " || " << annotation << std::endl <<
		genre << " || " << pages << " || " << price;
}

void Book::editInfo(char ind) {
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
		std::cin >> annotation;
		break;
	case '5':
		std::cin >> genre;
		break;
	case '6':
		std::cin >> pages;
		break;
	case '7':
		std::cin >> price;
		break;
	}
}