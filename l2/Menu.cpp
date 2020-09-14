#include "Menu.h"

/*заполнитель*/
std::string Padding(std::string str, const size_t num, const char paddingChar = ' ')
{
	if (num > str.size())
		str.insert(str.length(), num - str.size(), paddingChar);
	return str;
}

Menu::Menu() {
	CreateMenu();
}
void Menu::CreateSecondLevelMenu(Sports& sport) {
	/*вычисляем размер*/
	std::vector <int> lengths;
	for (auto i : sport.GetCategories())
		lengths.push_back(i.length());
	int sizeOfMenu = *std::max_element(lengths.begin(), lengths.end());
	/*создаем второе меню*/
	if (menu.size() == 1)
		menu.push_back(std::vector<std::string>(2 + sport.GetCategories().size()));
	else
		for (int i = 0; i < menu[levelOfMenu].size(); i++)
			menu[levelOfMenu][i].erase();

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
void Menu::LightPointOfMenu(int levelOfMenu) {
	ChangeColor("reverse_default");
	std::string text;
	switch (levelOfMenu) {
	case FIRST:
		if (pointOfMenu == FIRST) {
			text = "Летние виды спорта";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		if (pointOfMenu == SECOND) {
			text = "Зимние виды спорта";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		if (pointOfMenu == THIRD) {
			text = "Выход";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		break;
	case SECOND:
		gotoxy(12, pointOfMenu + 3);
		if (choosen == "Летние виды спорта")
			std::cout << summer.GetCategories()[pointOfMenu];
		if (choosen == "Зимние виды спорта")
			std::cout << winter.GetCategories()[pointOfMenu];

		break;
	case THIRD:
		break;
	}
	gotoxy(point);
	std::cout << text;
	ChangeColor("default");
}

void Menu::Choise(int& pointOfMenu, int& levelOfMenu) {

	switch (levelOfMenu) {
	case FIRST:
		++levelOfMenu;
		if (pointOfMenu == THIRD) {
			exit(0);
		}
		else {
			if (pointOfMenu == FIRST)
				choosen = "Летние виды спорта";
			if (pointOfMenu == SECOND)
				choosen = "Зимние виды спорта";
			pointOfMenu = FIRST;
			DisplayMenu(0);
			DisplayMenu(levelOfMenu);
		}
		break;
	case SECOND:

		break;
	case THIRD:
		break;
	case 3:
		break;
	default: 
		break;
	}

}

void Menu::DisplayMenu(int levelOfMenu)
{
	switch (levelOfMenu) {
	case FIRST:
		gotoxy(0, 0);
		for (int i = 0; i < 3; i++)
			std::cout << menu[levelOfMenu][i] << std::endl;
		if (this->levelOfMenu == FIRST)
			LightPointOfMenu(levelOfMenu);
		break;
	case SECOND:
		CreateMenu(levelOfMenu);
		for (int i = 0; i < menu[levelOfMenu].size(); i++) {
			gotoxy(10, i + 2);
			std::cout << menu[1][i];
		}
		if (this->levelOfMenu == SECOND)
			LightPointOfMenu(levelOfMenu);
		break;
	case THIRD:

		break;
	default: 
		break;
	}
}
void Menu::gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Menu::gotoxy(COORD c)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Menu::HideMenu()
{

	switch (levelOfMenu)
	{
	case SECOND:
		system("cls");
		break;
	case THIRD:

		break;
	default:
		break;
	}
	--levelOfMenu;
	pointOfMenu = 0;
}

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
	case FIRST:
		CreateFirstLevelMenu();
		break;
	case SECOND:
		if (choosen == "Летние виды спорта")
			CreateSecondLevelMenu(summer);
		if (choosen == "Зимние виды спорта")
			CreateSecondLevelMenu(winter);
		break;
	case THIRD:
		menu.push_back(std::vector<std::string>(3));


		break;
	default: break;
	}
}

void Menu::CreateFirstLevelMenu()
{
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
}

void Menu::Control() {
	char code = _getch();
	switch (code) {
	case BACKSPACE: HideMenu(); break;
	case ENTER:  Choise(pointOfMenu, levelOfMenu); return;
	case LEFT:	 ChangePointOfMenu(pointOfMenu, code); break;
	case RIGHT:  ChangePointOfMenu(pointOfMenu, code); break;
	case UP:     ChangePointOfMenu(pointOfMenu, code); break;
	case DOWN:   ChangePointOfMenu(pointOfMenu, code); break;

	default: return;
	} 
	DisplayMenu(levelOfMenu);
}