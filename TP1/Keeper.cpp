#include "Keeper.h"

Keeper::Keeper() {
	this->data = nullptr;
	this->size = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "Keeper()\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

Keeper::Keeper(int length) {
	this->size = length;
	this->data = (length > 0 ? (Bookstore**)malloc(length*sizeof(Bookstore*)) : nullptr);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "Keeper(int)\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

Keeper::~Keeper() {
	free(data);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "~Keeper\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Keeper::Remove() {
	free(data);

	this->data = nullptr;
	this->size = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "Remove\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int Keeper::getSize() {
	return size;
}

Bookstore& Keeper::operator[](const int ind) {
	if (ind >= 0 || ind < this->size) {
		for (int i = 0; i < this->size; i++) {
		}
		return *data[ind];
	}
	else std:: cout << "\nВведен неверный индекс\n";
}

void Keeper::realloCate(int newSize) {
	Remove();
	if(newSize <= 0) return;
	
	this->data = (Bookstore**)malloc(newSize*sizeof(Bookstore*));
	this->size = newSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "realloCate\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Keeper::reSize(int newSize) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (newSize == size) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "Нечего переделывать!\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else {
		if (newSize <= 0) {
			Remove();
		}
		else {
			Bookstore** new_data = (Bookstore**)malloc(newSize * sizeof(Bookstore*));
			if (this->size > 0) {
				int copyid = (newSize > this->size) ? this->size : newSize;
				for (int i = 0; i < copyid; ++i) {
					new_data[i] = this->data[i];
				}
				free(data);
				this->data = new_data;
				this->size = newSize;
			}

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << "reSize\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
}

void Keeper::addElement(Bookstore* element, int ind) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if ((ind < 0) || (ind >this->size)) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "Выход за пределы полки!\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
	}
	else {
		Bookstore** new_data = (Bookstore**)malloc((this->size + 1) * sizeof(Bookstore*));
		for (int i = 0; i < ind; ++i) {
			new_data[i] = this->data[i];

		}
		new_data[ind] = element;
		for (int i = ind; i < this->size; ++i) {
			new_data[i + 1] = this->data[i];
		}
		free(data);

		this->data = new_data;
		this->size++;

		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
		std::cout << "addElement\n";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

void Keeper::removeElement(int ind) {
	if (ind < 0 || ind >= size) return;
	if (this->size == 1) {
		Remove();
		return;
	}
	Bookstore** new_data = (Bookstore**)malloc((this->size - 1) * sizeof(Bookstore*));
	for (int i = 0; i < ind; i++) {
		new_data[i] = data[i];
	}
	for (int i = ind; i < this->size; i++) {
		new_data[i] = this->data[i+1];
	}
	free(data);
	this->data = new_data;
	--size;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "removeElement\n";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}