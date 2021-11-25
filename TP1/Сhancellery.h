#pragma once
#include "Bookstore.h"

class Chancellery :public Bookstore {
private:
	std::string type;
	std::string color;
	std::string purpose;
	float price;
public:
	Chancellery();
	std::string getInfo() override;
	int setInfo(int ind, std::string str) override;
	void editInfo(int ind) override;
	~Chancellery() override;
	
};