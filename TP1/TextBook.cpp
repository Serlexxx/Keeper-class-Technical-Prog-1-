#include "TextBook.h"


void TextBook::setInfo(int ind, std::string str) {
	switch (ind)
	{
	case 1:
		this->name = str;
		break;
	case 2:
		this-> author = str;
		break;
	case 3:
		this->year = stoi(str, NULL, 10);
		break;
	case 4:
		this->educat_instit = str;
		break;
	case 5:
		this->year_training = stoi(str, NULL, 10);
		break;
	case 6:
		this->pages = stoi(str, NULL, 10);
		break;
	case 7:
		this->price = round(stof(str, NULL) * 100) / 100;
		break;
	}
}

void TextBook::getInfo() {
	std::cout.setf(10);
	std::cout <<"text\n" <<name << " || " << author << " || " << year << " || " << educat_instit << std::endl <<
		year_training << " || " << pages << " || " << price<< std::endl;
}

void TextBook::editInfo(int ind) {
	std::cout << "¬ведите число 1..7\n";
	
	switch (ind)
	{
	case 1:
		std::cin >> name;
		break;
	case 2:
		std::cin >> author;
		break;
	case 3:
		std::cin >> year;
		break;
	case 4:
		std::cin >> educat_instit;
		break;
	case 5:
		std::cin >> year_training;
		break;
	case 6:
		std::cin >> pages;
		break;
	case 7:
		std::cin >> price;
		break;
	}
}

TextBook::~TextBook() {

}