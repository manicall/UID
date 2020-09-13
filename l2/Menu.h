#pragma once
#include "conio.h"
#include "Sports.h"
#include "Summer.h"
#include "Winter.h"
#include "Windows.h"



class Menu
{	
	COORD firstPoint = { 0, 0 }, lastPoint = { 0, 0 };
	enum { ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };
	int levelOfMenu = 0;
	int pointOfMenu = 0;
	std::string kindofsports = " Летние виды спорта | Зимние виды спорта | Выход ";
	std::vector<std::string> menu;
	Summer summer;
	Winter winter;

public:

	Menu() {
		menu.reserve(3);
		CreateMenu();
	}
	/*Методы*/
	/*выбор пункта меню*/
	void Choise(int pointOfMenu, int levelOfMenu) {

	}
	void ChangeColor() {};
	void CreateMenu(int levelOfMenu = 0);
	void DisplayFirstLevelMenu() { std::cout << menu[0]; }
	void gotoxy(int x, int y)
	{
		COORD c = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

	void Move();

	void ChangePointOfMenu(int& pointOfMenu, int direction) {


	}
};


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
	default: break;
	}
}

void Menu::Move() {

	int code = _getch();

	switch (code) {
	case ENTER: Choise(pointOfMenu, levelOfMenu); break;
	case LEFT:	 ++pointOfMenu; break;
	case RIGHT:  ++pointOfMenu; break;
	case UP:     ++pointOfMenu; break;
	case DOWN:   ++pointOfMenu; break;

	default: break;
	}
}
