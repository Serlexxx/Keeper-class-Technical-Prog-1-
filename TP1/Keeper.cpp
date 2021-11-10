#include "Keeper.h"

Bookstore::Bookstore() {
	this->data = nullptr;
	this->size = 0;
}

Bookstore::Bookstore(int length) {
	this->size = length;
	this->data = (length > 0 ? (Bookstore*)malloc(length*sizeof(Bookstore)) : nullptr);
}

Bookstore::~Bookstore() {
	free(data);
}

void Bookstore::Remove() {
	free(data);

	this->data = nullptr;
	this->size = 0;
}

int Bookstore::getSize() {
	return size;
}

Bookstore& Bookstore::operator[](int ind) {
	if (ind >= 0 && ind < size)
		return data[ind];
	else return;
}

void Bookstore::realloCate(int newSize) {
	Remove();
	if(newSize <= 0) return;
	
	this->data = (Bookstore*)malloc(newSize*sizeof(Bookstore));
	this->size = newSize;
}

void Bookstore::reSize(int newSize) {
	if (newSize == size) return;
	if (newSize <= 0) {
		Remove();
		return;
	}
	this->data = (Bookstore*)realloc(data, newSize*sizeof(Bookstore));
	this->size = newSize;
}

void Bookstore::addElement(Bookstore* element, int ind) {
	if (ind < 0 && ind >size) return;
	this->size++;
	this->data = (Bookstore*)realloc(data, size * sizeof(Bookstore));
	data[ind] = element;
}

void Bookstore::removeElement(int ind) {
	if (ind < 0 && ind >= size) return;
	if (this->size == 1) {
		Remove();
		return;
	}
	Bookstore* data_new = (Bookstore*)malloc((this->size - 1) * sizeof(Bookstore));
	for (int i = 0; i < ind; i++) {
		data_new[i] = data[i];
	}
	for (int i = ind + 1; i < this->size; i++) {
		data_new[i] = data[i];
	}
	free(data);
	this->data = data_new;
	--size;
}