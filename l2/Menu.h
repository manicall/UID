#pragma once
#include "conio.h"
#include "Sports.h"
#include "Summer.h"
#include "Winter.h"
#include "Windows.h"
#include <algorithm>
#include <iostream> 

class Menu
{	

	enum { 
		FIRST, SECOND, THIRD, FOURTH, 
		BACKSPACE = 8, ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 
	};
	COORD point = { 0, 0 };
	int levelOfMenu = 0;
	int pointOfMenu = 0;
	std::string choosen;
	std::string kindofsports = " Летние виды спорта | Зимние виды спорта | Выход ";
	std::vector<std::vector<std::string>> menu;
	Summer summer;
	Winter winter;

	/*Методы*/
	void HideMenu();
	void ChangeColor(std::string color);
	void CreateMenu(int levelOfMenu = 0);
	void CreateFirstLevelMenu();
	void CreateSecondLevelMenu(Sports& sport);
	void Choise(int& pointOfMenu, int& levelOfMenu);
	void LightPointOfMenu(int levelOfMenu);
	void gotoxy(int x, int y);
	void gotoxy(COORD c);
	void ChangePointOfMenu(int& pointOfMenu, int direction);

public:
	Menu();

	void DisplayMenu(int levelOfMenu = 0);
	void Control();

};
