#pragma once
#include "Bookstore.h"

class Chancellery :public Bookstore {
private:
	std::string type;
	std::string color;
	std::string purpose;
	float price;
public:
	void getInfo() override;
	void setInfo(int ind, std::string str) override;
	void editInfo(int ind) override;
};