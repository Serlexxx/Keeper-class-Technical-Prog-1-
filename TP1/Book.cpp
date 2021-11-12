#include "Book.h"

void Book::setInfo(int ind, std::string str) {
	switch (ind)
	{
	case '1':
		this->name=str;
		break;
	case'2':
		this->author=str;
		break;
	case '3':
		this->year= stoi(str, NULL, 10);
		break;
	case '4':
		this->annotation =str;
		break;
	case '5':
		this->genre = str;
		break;
	case '6':
		this->pages= stoi(str, NULL, 10);
		break;
	case '7':
		this->price= round(stof(str, NULL) * 100) / 100;
		break;
	}
}

void Book::getInfo() {
	std::cout.setf(10);
	std::cout <<"book\n" << name << " || " << author << " || " << year << " || " << annotation << std::endl <<
		genre << " || " << pages << " || " << price<< std::endl;
}

void Book::editInfo(int ind) {
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