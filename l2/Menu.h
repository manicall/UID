#pragma once
#include "conio.h"
#include "Sports.h"
#include "Summer.h"
#include "Winter.h"
#include "Windows.h"
#include <algorithm>
#include <iostream> 
#include <numeric>

class Menu
{	

	enum { 
		FIRST, SECOND, THIRD, FOURTH, 
		BACKSPACE = 8, ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 
	};
	COORD point = { 0, 0 };
	int levelOfMenu = 0;
	int pointOfMenu = 0;
	std::vector<std::string> choosen = { "", "", "" };
	std::string kindofsports = " Летние виды спорта | Зимние виды спорта | Выход ";
	std::vector<std::vector<std::string>> menu;
	Summer summer;
	Winter winter;

	/*Методы*/
	void HideMenu();
	int SizeOfMenu(const std::vector<std::string>& vect, bool isVertical = true);
	std::string HorizontBorder(int length);
	void ChangeColor(std::string color);
	void CreateMenu(int levelOfMenu = 0);
	void CreateFirstLevelMenu();
	void CreateSecondLevelMenu(Sports& sport);
	void CreateThirdLevelMenu(Sports& sport);
	void Choise(int& pointOfMenu, int levelOfMenu);
	void LightPointOfMenu(int levelOfMenu);
	void gotoxy(int x, int y);
	void gotoxy(COORD c);
	void ChangePointOfMenu(int& pointOfMenu, int direction);
	void PrintDescription();
	
public:
	Menu();

	void DisplayMenu(int levelOfMenu = 0);
	void Control();

};
