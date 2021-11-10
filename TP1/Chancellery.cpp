#include "Ñhancellery.h"

void Chancellery::setInfo(std::string type, std::string color, std::string purpose, float price) {
	this->type = type;
	this->color = color;
	this->purpose = purpose;
	this->price = price;
}

void Chancellery::getInfo() {
	std::cout.setf(10);
	std::cout << type << " || " << color << " || " << purpose << " || " << price;
}

void Chancellery::editInfo(char ind) {
	switch (ind)
	{
	case '1':
		std::cin >> type;
		break;
	case '2':
		std::cin >> color;
		break;
	case '3':
		std::cin >> purpose;
		break;
	case '4':
		std::cin >> price;
		break;
	}
}
