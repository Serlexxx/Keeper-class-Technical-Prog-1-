#include<iostream>
#include <fstream>
#include "Keeper.h"
#include "TextBook.h"
#include "Bookstore.h"
#include "Book.h"
#include "Ñhancellery.h"

int main() {
	setlocale(LC_ALL, "rus");
	Keeper keeper;
	TextBook text;
	Book book;
	Chancellery chance;
	std::ifstream fp("test.txt");
	if (!fp.is_open()) {
		std::cout << "Ôàéë íå îòêðûò\n\n";
	}
	else {
			while (!fp.eof()) {
				int count = 0;
				std::string word;
				int miniSwitch = 0;
				fp >> word;
				if (word == "textbook")
					miniSwitch = 1;
				else {
					if (word == "book")
						miniSwitch = 2;
					else {
						if (word == "chancellery")
							miniSwitch = 3;
					}
				}
				switch (miniSwitch)
				{
				case 1:
					for (int cnt = 1; cnt < 8; cnt++) {
						fp >> word;
						text.setInfo(cnt, word);
					}
					count++;
					keeper.addElement(book, count);
					text.getInfo();
					break;
				case 2:
					for (int cnt = 1; cnt < 8; cnt++) {
						fp >> word;
						book.setInfo(cnt, word);
					}
					count++;
					keeper.addElement(book, count);
					book.getInfo();
					break;
				case 3: 
					for (int cnt = 1; cnt < 5; cnt++) {
						fp >> word;
						chance.setInfo(cnt, word);
					}
					count++;
					keeper.addElement(book, count);
					chance.getInfo();
					break;
				}
			}
			fp.close();
	}
	
	
	
	std::cout <<"\nsize " << keeper.getSize() << std::endl;
	keeper[1].getInfo();
	return 0;
}