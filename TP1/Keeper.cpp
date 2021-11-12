#include "Keeper.h"

Keeper::Keeper() {
	this->data = nullptr;
	this->size = 0;
}

Keeper::Keeper(int length) {
	this->size = length;
	this->data = (length > 0 ? (Bookstore*)malloc(length*sizeof(Bookstore)) : nullptr);
}

Keeper::~Keeper() {
	free(data);
}

void Keeper::Remove() {
	free(data);

	this->data = nullptr;
	this->size = 0;
}

int Keeper::getSize() {
	return size;
}

Bookstore& Keeper::operator[](int ind) {
	if (ind >= 0 && ind < size)
		return data[ind];
	else std:: cout << "\n¬веден неверный индекс\n";
}

void Keeper::realloCate(int newSize) {
	Remove();
	if(newSize <= 0) return;
	
	this->data = (Bookstore*)malloc(newSize*sizeof(Bookstore));
	this->size = newSize;
}

void Keeper::reSize(int newSize) {
	if (newSize == size) return;
	if (newSize <= 0) {
		Remove();
		return;
	}
	Bookstore* new_data = (Bookstore*)malloc(newSize * sizeof(Bookstore));
	if(this->size > 0) {
		int copyid = (newSize > this->size) ? this->size : newSize;
		for (int i = 0; i < copyid; ++i) {
			new_data[i] = this->data[i];
		}
		free(data);
		this->data = new_data;
		this->size = newSize;
	}
}

void Keeper::addElement(Bookstore& element, int ind) {
	if (ind < 0 && ind >this->size) return;
	Bookstore* new_data = (Bookstore*)malloc((this->size + 1) * sizeof(Bookstore));
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
}

void Keeper::removeElement(int ind) {
	if (ind < 0 && ind >= size) return;
	if (this->size == 1) {
		Remove();
		return;
	}
	Bookstore* new_data = (Bookstore*)malloc((this->size - 1) * sizeof(Bookstore));
	for (int i = 0; i < ind; i++) {
		new_data[i] = data[i];
	}
	for (int i = ind + 1; i < this->size; i++) {
		new_data[i] = this->data[i];
	}
	free(data);
	this->data = new_data;
	--size;
}