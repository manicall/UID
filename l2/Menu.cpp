#include "Menu.h"
/*
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
}*/