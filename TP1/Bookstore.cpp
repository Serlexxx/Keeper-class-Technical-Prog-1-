#include "Bookstore.h"


Bookstore::Bookstore()
{
	this->cnt_book = 0;
	this->cnt_chance = 0;
	this->cnt_text = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "Bookstore()\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

Bookstore::~Bookstore()
{
}

int Bookstore::getCnt(int ind) {
	int cnt = -1;
	switch (ind) {
		case 1:
			return this->cnt_text;
		case 2:
			return this->cnt_book;
		case 3:
			return this->cnt_chance;
		default:
			return cnt;
	}
}

void Bookstore::setCnt(int ind) {
	switch (ind) {
	case 1:
		this->cnt_text++;
		break;
	case 2:
		this->cnt_book++;
		break;
	case 3:
		this->cnt_chance++;
		break;
	}
}