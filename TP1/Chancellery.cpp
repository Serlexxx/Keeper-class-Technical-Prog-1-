#include "Ñhancellery.h"

void Chancellery::setInfo(int ind, std::string str) {
	switch (ind)
	{
	case 1:
		this->type = str;
		break;
	case 2:
		this->color = str;
		break;
	case 3:
		this->purpose = str;
		break;
	case 4:
		this->price = round(stof(str, NULL) * 100) / 100;
		break;
	}
}

void Chancellery::getInfo() {
	std::cout.setf(10);
	std::cout <<"chacne\n"<< type << " || " << color << " || " << purpose << " || " << price<< std::endl;
}

void Chancellery::editInfo(int ind) {
	switch (ind)
	{
	case 1:
		std::cin >> type;
		break;
	case 2:
		std::cin >> color;
		break;
	case 3:
		std::cin >> purpose;
		break;
	case 4:
		std::cin >> price;
		break;
	}
}
