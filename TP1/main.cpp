#include <iostream>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include "Keeper.h"
#include "TextBook.h"
#include "Bookstore.h"
#include "Book.h"
#include "Сhancellery.h"
#include "Painter.h"
#include "Point.h"


uint32_t frameWidth, frameHeight;
RGBQUAD* frameBuffer;

int main() {
	setlocale(LC_ALL, "rus");
	Keeper keeper(0);
	char BigSwitch = 0;
	bool BigExit = 1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (BigExit) {
		std::cout << "\nЧто пожелаете сделать?\n";
		std::cout << "1. Открыть файл\n2. Сохранить в файл\n3. Добавить книгу, учебник или канцелярию" << std::endl <<
			"4. Удалить что-то\n5. Вывести что-то\n6. Вывести ещё что-то\n0. Выход\n";
		std::cin >> BigSwitch;
		switch (BigSwitch)
		{
		case '1': {
			OPENFILENAME ofn = { sizeof ofn };
			wchar_t file[1024];
			file[0] = '\0';
			ofn.lpstrFile = file;
			ofn.lpstrFilter = L"Text .txt\0 * .TXT\0";
			ofn.nMaxFile = 1024;
			ofn.Flags = OFN_ALLOWMULTISELECT | OFN_EXPLORER;
			if (GetOpenFileNameW(&ofn)) {
				std::ifstream fp(file);
				int count = 0;
				while (!fp.eof()) {

					std::string word_switch;
					std::string word;
					int miniSwitch = 0;
					fp >> word_switch;
					std::transform(word_switch.begin(), word_switch.end(), word_switch.begin(), tolower);
					if (word_switch == "textbook")
						miniSwitch = 1;
					else {
						if (word_switch == "book")
							miniSwitch = 2;
						else {
							if (word_switch == "chancellery")
								miniSwitch = 3;
						}
					}
					int cnt_in = 1;
					switch (miniSwitch)
					{
					case 1: {
						keeper.addElement(new TextBook, count);
						while (cnt_in < 8) {
							fp >> word;
							cnt_in = keeper[count].setInfo(cnt_in, word);
						}
						keeper[count].getInfo();
						count++;
						break;
					}
					case 2: {
						keeper.addElement(new Book, count);
						while (cnt_in < 8) {
							fp >> word;
							cnt_in = keeper[count].setInfo(cnt_in, word);
						}
						keeper[count].getInfo();
						count++;
						break;
					}
					case 3: {
						keeper.addElement(new Chancellery, count);
						while (cnt_in < 5) {
							fp >> word;
							cnt_in = keeper[count].setInfo(cnt_in, word);
						}
						keeper[count].getInfo();
						count++;
						break;
					}
					}
				}
				fp.close();
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Выполнено!\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Вы отменили выбор файла!\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			break;
		}
		case '2': {
			if (keeper.getSize() == 0) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Сохранять нечего!\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else {
				OPENFILENAME ofn = { sizeof ofn };
				wchar_t file[1024];
				file[0] = '\0';
				ofn.lpstrFile = file;
				ofn.lpstrFilter = L"Text .txt\0 * .TXT\0";
				ofn.nMaxFile = 1024;
				ofn.Flags = OFN_ALLOWMULTISELECT | OFN_EXPLORER;
				if (GetOpenFileNameW(&ofn)) {
					std::ofstream fp(file);
					int count = 0;
					do {
						fp << keeper[count].getInfo();
						count++;
					} while (count != keeper.getSize());
					fp.close();
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Выполнено!\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				else {
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Вы отменили выбор файла!\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
			}
			break;
		}
		case '3': {
			
			bool miniExit = 1;
			while (miniExit) {
				system("cls");
				char miniSwitch;
				std::cout << "Что пожелаете добавить?\n";
				std::cout << "1. Книгу\n2. Учебник\n3. Канцелярию\n0. Назад\n";
				std::cin >> miniSwitch;
				switch (miniSwitch)
				{
				case '1': {
					std::cout << "Куда добавить: в начало(0) или в конце(" << keeper.getSize() << ").?";
					int cnt = 0;
					std::cin >> cnt;
					keeper.addElement(new Book, cnt);
					int i = 1;
					while (i < 8) {
						std::string str;
						std::cin >> str;
						i = keeper[cnt].setInfo(i, str);
					}
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Выполнено!\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					Sleep(5000);
					break;
				}
				case '2': {
					std::cout << "Куда добавить: в начало(0) или в конце(" << keeper.getSize() << ").?";
					int cnt = 0;
					std::cin >> cnt;
					keeper.addElement(new TextBook, cnt);
					int i = 1;
					while (i < 8) {
						std::string str;
						std::cin >> str;
						i = keeper[cnt].setInfo(i, str);
					}
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Выполнено!\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					Sleep(5000);
					break;
				}
				case '3': {
					std::cout << "Куда добавить: в начало(0) или в конце(" << keeper.getSize() << ").?";
					int cnt = 0;
					std::cin >> cnt;
					keeper.addElement(new Chancellery, cnt);
					int i = 1;
					while (i < 5) {
						std::string str;
						std::cin >> str;
						i = keeper[cnt].setInfo(i, str);

					}
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Выполнено!\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					Sleep(5000);
					break;
				}
				case '0': {
					miniExit = 0;
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Cпасибо!\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
				default:
					system("cls");
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Попробуйте снова!\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					break;
				}
			}
			break;
		}
		case '4': {
			system("cls");
			if (keeper.getSize() == 0) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Удалять нечего!\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else {
				bool miniExit = 1;
				while (miniExit) {
					for (int i = 0; i < keeper.getSize(); i++) {
						std::cout << i << ". " << keeper[i].getInfo();
					}
					std::cout << "Что желаете удалить?\nВведите значение 0.." << keeper.getSize() - 1 << std::endl;
					int ind, indic = 0;
					std::cin >> ind;
					indic = (ind >= 0 && ind < keeper.getSize() ? ind : -1);
					if (indic != -1) {
						keeper.removeElement(indic);
						miniExit = 0;
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
						std::cout << "Выполнено!\n";
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					}
					else {
						system("cls");
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
						std::cout << "Попробуйте снова!\n";
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					}
				}
			}
			break;
		}
		case '5': {
			system("cls");
			if (keeper.getSize() == 0) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Выводить нечего!\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else {
				for (int i = 0; i < keeper.getSize(); i++) {
					std::cout << keeper[i].getInfo();
				}
			}
			break;
		}
		case '6': {
			system("cls");
			if (keeper.getSize() == 0) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Пусто, ничего не покажу!\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else {
				
				char c;
				while ((c = getchar() != EOF)) {
					HWND hWnd = GetConsoleWindow();
					HDC hDC = GetDC(hWnd);
					RECT clientRect;
					GetClientRect(hWnd, &clientRect);
					frameWidth = clientRect.right;
					frameHeight = clientRect.bottom;

					frameBuffer = CreateFrameBuffer(frameWidth, frameHeight);
					Point point[4];

					int cnt_cnt[3];
					for (int i = 0; i < 3; i++) cnt_cnt[i] = 0;
					for (int i = 0; i < keeper.getSize(); i++) {
						if (typeid(keeper[i]) == typeid(TextBook)) {
							cnt_cnt[0]++;
						}
						else {
							if (typeid(keeper[i]) == typeid(Book)) {
								cnt_cnt[1]++;
							}
							else {
								if (typeid(keeper[i]) == typeid(Chancellery)) {
									cnt_cnt[2]++;
								}
							}
						}
					}
					int max_height = clientRect.bottom - 20;
					int min_heinght = 20;
					int delta_x = 20;
					float pircent;
					int size = keeper.getSize();
					int big_delta_x = 30;
					for (int i = 0; i < 3; i++) {
						pircent = ((float)cnt_cnt[i] / size);
						point[0].y = min_heinght;
						point[1].y = point[0].y;
						point[2].y = pircent * (max_height - min_heinght);
						point[3].y = point[2].y;
						if (i == 0) point[0].x = 10;
						else {
							if (i == 1) point[0].x = 40;
							else {
								if (i == 2) {
									point[0].x = 70;
								}
							}
						}
						point[1].x = point[0].x + delta_x;
						point[2].x = point[1].x;
						point[3].x = point[0].x;
						RGBQUAD color = { (i + 1) * 55,(i + 1) * 55,(i + 1) * 55,0 };
						SetLine(point, frameBuffer, frameWidth, color);
						Sketch(frameBuffer, (point[0].x+point[1].x)/2, (point[0].y+point[2].y)/2, frameWidth, { 0,0,0,0 }, color);
					}
					PresentFrame(frameWidth, frameHeight, frameBuffer, hWnd);
					ReleaseDC(hWnd, hDC);
				}
				
			}
			system("cls");
			break;
		}
		case '0': {
			BigExit = 0;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
			std::cout << "Досвидания!\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		default: {
			system("cls");
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Попробуйте снова!\n";
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		}
		}
	}

	return 0;
}

