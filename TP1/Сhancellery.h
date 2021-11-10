#pragma once
#include "Keeper.h"

class Chancellery :public Bookstore {
private:
	std::string type;
	std::string color;
	std::string purpose;
	float price;
public:
	void getInfo();
	void setInfo(std::string type, std::string color, std::string purpose, float price);
	void editInfo(char ind);
};