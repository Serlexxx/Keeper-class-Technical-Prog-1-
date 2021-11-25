#include "Book.h"

Book::Book() {

}

int Book::setInfo(int ind, std::string str) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (ind)
	{
	case 1:
		this->name = str;
		break;
	case 2:
		this->author = str;
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
		this->annotation = str;
		break;
	case 5:
		this->genre = str;
		break;
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
	std::cout << "Book.SetInfo(" << ind << ")\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return ++ind;
}

std::string Book::getInfo() {
	std::string str = "book "+this->name +" "+ this->author + " " + std::to_string(this->year) + " " + this->annotation + " " + this->genre + " " + std::to_string(this->pages) + " " + std::to_string(this->price) + "\n";
	return str;
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "Book.EditInfo(" << ind << ")\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

Book::~Book() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "~Book()\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}