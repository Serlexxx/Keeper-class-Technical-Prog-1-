#include "TextBook.h"

TextBook::TextBook() {

}

int TextBook::setInfo(int ind, std::string str) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (ind)
	{
	case 1:
		this->name = str;
		break;
	case 2:
		this-> author = str;
		break;
	case 3: {
		try {
			this->year = stoi(str, NULL, 10);
		}
		catch (const std::invalid_argument& ia) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Попробуйте снова!\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			return ind;
		}
		break;
	}
	case 4:
		this->educat_instit = str;
		break;
	case 5: {
		try {
			this->year_training = stoi(str, NULL, 10);
		}
		catch (const std::invalid_argument& ia) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Попробуйте снова!\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			return ind;
		}
		break; 
	}
	case 6: {
		try {
			this->pages = stoi(str, NULL, 10);
		}
		catch (const std::invalid_argument& ia) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Попробуйте снова!\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			return ind;
		}
		break;
	}
	case 7: {
		try {
			this->price = round(stof(str, NULL) * 100) / 100;
		}
		catch (const std::invalid_argument& ia) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Попробуйте снова!\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			return ind;
		}
		break;
	}
	}

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "TextBook.SetInfo(" << ind << ")\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return ++ind;
}

std::string TextBook::getInfo() {
	std::string str = "textbook "+this->name + " " + this->author + " " + std::to_string(this->year) + " " + this->educat_instit + " " + std::to_string(this->year_training) + " " + std::to_string(this->pages) + " " + std::to_string(this->price) + "\n";
	return str;
}

void TextBook::editInfo(int ind) {
	std::cout << "Введите число 1..7\n";
	
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "TextBook.EditInfo(" << ind << ")\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

TextBook::~TextBook() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "~TextBook()\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}