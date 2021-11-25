#include "Ñhancellery.h"

Chancellery::Chancellery() {

}

int Chancellery::setInfo(int ind, std::string str) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
	case 4: {
		try {
			this->price = round(stof(str, NULL) * 100) / 100;
		}
		catch (const std::invalid_argument& ia) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Ïîïðîáóéòå ñíîâà!\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			return ind;
		}
		break;
	}
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "Chancellery.SetInfo(" << ind << ")\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return ++ind;
}

std::string Chancellery::getInfo() {
	std::string str = "chancellery "+this->type + " " + this->color + " " + this->purpose + " " + std::to_string(this->price) + "\n";
	return str;
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "Chancellery.EditInfo(" << ind << ")\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

Chancellery::~Chancellery() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "~Chacnellery()\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

