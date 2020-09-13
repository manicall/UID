#pragma once
#include "conio.h"
#include "Sports.h"
#include "Summer.h"
#include "Winter.h"
#include "Windows.h"



class Menu
{	
	COORD point = { 0, 0 };
	enum { BACKSPACE = 8,  ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };
	int levelOfMenu = 0;
	int pointOfMenu = 0;
	std::string kindofsports = " Летние виды спорта | Зимние виды спорта | Выход ";
	std::vector<std::string> menu;
	Summer summer;
	Winter winter;

	/*Методы*/
	void ChangeColor(std::string color);
	void CreateMenu(int levelOfMenu = 0);
	void Choise(int& pointOfMenu, int& levelOfMenu) {
		switch (levelOfMenu) {
		case 0:
			if (!pointOfMenu) {
				DisplayMenu(1);
			}
			if (pointOfMenu) {

			}
			if (pointOfMenu == 2) {
				exit(0);
			}
			break;
		default: return;
		}
		++levelOfMenu;
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
		menu.reserve(3);
		CreateMenu();
	}

    /*Методы*/

	void DisplayMenu(int levelOfMenu = 0) { 
		switch (levelOfMenu) {
		case 0:
			gotoxy(0, 0);
			std::cout << menu[levelOfMenu];
			LightPointOfMenu(pointOfMenu, levelOfMenu);
			break;
		case 1: 
			gotoxy(10, 2);
			std::cout << menu[0];

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
		menu.push_back("+");
		for (size_t i = 0; i < kindofsports.length(); i++)
			menu[0].push_back('-');
		menu[0] += "+\n";
		menu[0] += "|" + kindofsports + "|\n";
		menu[0].push_back('+');
		for (size_t i = 0; i < kindofsports.length(); i++)
			menu[0].push_back('-');
		menu[0].push_back('+');
		break;
	case 1:

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
