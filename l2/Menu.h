#pragma once
#include "conio.h"
#include "Sports.h"
#include "Summer.h"
#include "Winter.h"
#include "Windows.h"
#include <algorithm>
#include <iostream>

/*заполнитель*/
std::string Padding(std::string str, const size_t num, const char paddingChar = ' ')
{
	if (num > str.size())
		str.insert(str.length(), num - str.size(), paddingChar);
	return str;
}

class Menu
{	
	enum { BACKSPACE = 8, ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };
	COORD point = { 0, 0 };
	int levelOfMenu = 0;
	int pointOfMenu = 0;
	std::string kindofsports = " Летние виды спорта | Зимние виды спорта | Выход ";
	std::vector<std::vector<std::string>> menu;
	Summer summer;
	Winter winter;


	/*Методы*/
	void ChangeColor(std::string color);
	void CreateMenu(int levelOfMenu = 0);
	void CreateSecondLevelMenu(Sports& sport) {
	
		/*вычисляем размер*/
		std::vector <int> lengths;
		for (auto i : sport.GetCategories())
			lengths.push_back(i.length());
		int sizeOfMenu = *std::max_element(lengths.begin(), lengths.end());
		/*создаем второе меню*/
		menu.push_back(std::vector<std::string>(2 + sport.GetCategories().size()));
		/*верхняя граница*/
		menu[levelOfMenu][0].push_back('+');
		for (int i = 0; i < sizeOfMenu + 2; i++)
			menu[levelOfMenu][0].push_back('-');
		menu[levelOfMenu][0].push_back('+');
		/*пункты меню*/
		int i = 0;
		for (; i < sport.GetCategories().size(); i++) {
			menu[levelOfMenu][i + 1] += "| " + Padding(sport.GetCategories()[i], sizeOfMenu) + " |";
		}
		/*нижняя граница*/
		++i;
		menu[levelOfMenu][i].push_back('+');
		for (int j = 0; j < sizeOfMenu + 2; j++)
			menu[levelOfMenu][i].push_back('-');
		menu[levelOfMenu][i].push_back('+');
	
	
	}
	void Choise(int& pointOfMenu, int& levelOfMenu) {

		switch (levelOfMenu) {

		case 0:
			if (pointOfMenu == 2) {
				exit(0);
			}
			else {
				DisplayMenu(levelOfMenu, false);
				DisplayMenu(++levelOfMenu);
			}
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default: return;
		}
	}
	void LightPointOfMenu(int pointOfMenu, int levelOfMenu) {
		ChangeColor("reverse_default");
		std::string text;
		switch (levelOfMenu) {
		case 0: 
			if (!pointOfMenu) {
				text = "Летние виды спорта";
				point = { (SHORT)kindofsports.find(text) + 1, 1 };
			}
			if (pointOfMenu) {
				text = "Зимние виды спорта";
				point = { (SHORT)kindofsports.find(text) + 1, 1 };
			}
			if (pointOfMenu == 2) {
				text = "Выход";
				point = { (SHORT)kindofsports.find(text) + 1, 1 };
			}
			break;
		case 1:

			break;
		case 2:
			break;
		}
		gotoxy(point);
		std::cout << text;
		ChangeColor("default");
	}
public:
	Menu() {
		CreateMenu();
	}

    /*Методы*/

	void DisplayMenu(int levelOfMenu = 0, bool cursor = true) { 
		switch (levelOfMenu) {
		case 0:
			gotoxy(0, 0);
			for(int i = 0; i < 3; i++)
				std::cout << menu[levelOfMenu][i] << std::endl;
			if (cursor) LightPointOfMenu(pointOfMenu, levelOfMenu);
			break;
		case 1: 
			CreateMenu(levelOfMenu);
			for (int i = 0; i < menu[levelOfMenu].size(); i++) {
				gotoxy(10, i + 2);
				std::cout << menu[1][i];
			}

			break;
		case 2:

			break;
		case 3:

			break;
		}
	}
	void gotoxy(int x, int y)
	{
		COORD c = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}
	void gotoxy(COORD c)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}
	void ChangePointOfMenu(int& pointOfMenu, int direction);
	void Control();
};

 void Menu::ChangeColor(std::string color) {
	{
		if (color == "default")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
		if (color == "reverse_default")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 0));
	};
 }

 void Menu::ChangePointOfMenu(int& pointOfMenu, int direction)
 {
	 if (pointOfMenu > 0)
		if (direction == LEFT || direction == UP) 
			--pointOfMenu;
	 if (pointOfMenu < 2)
		 if (direction == RIGHT || direction == DOWN)
			 ++pointOfMenu;
 }
 
void Menu::CreateMenu(int levelOfMenu) {
	switch (levelOfMenu)
	{
	case 0: 
		menu.push_back(std::vector<std::string>(3));
		menu[levelOfMenu][0].push_back('+');
		for (size_t i = 0; i < kindofsports.length(); i++)
			menu[levelOfMenu][0].push_back('-');
		menu[levelOfMenu][0].push_back('+');
		menu[levelOfMenu][1] += "|" + kindofsports + "|";
		menu[levelOfMenu][2].push_back('+');
		for (size_t i = levelOfMenu; i < kindofsports.length(); i++)
			menu[levelOfMenu][2].push_back('-');
		menu[levelOfMenu][2].push_back('+');
		break;
	case 1:
		if (!pointOfMenu) 
			CreateSecondLevelMenu(summer);		
		if (pointOfMenu) 
			CreateSecondLevelMenu(winter);		
		break;
		
	case 2:
		menu.push_back(std::vector<std::string>(3));


		break;
	default: break;
	}
}

void Menu::Control() {
	char code = _getch();
	switch (code) {
	case BACKSPACE: exit(0);
	case ENTER:  Choise(pointOfMenu, levelOfMenu); return;
	case LEFT:	 ChangePointOfMenu(pointOfMenu, code); break;
	case RIGHT:  ChangePointOfMenu(pointOfMenu, code); break;
	case UP:     ChangePointOfMenu(pointOfMenu, code); break;
	case DOWN:   ChangePointOfMenu(pointOfMenu, code); break;

	default: return;
	} 
	DisplayMenu(levelOfMenu);
}