#include "Menu.h"

/*�����������*/
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
	/*��������� ������*/
	int sizeOfMenu = SizeOfMenu(sport.GetCategories());
	/*������� ������ ����*/
	if (menu.size() == 1)
		menu.push_back(std::vector<std::string>(2 + sport.GetCategories().size())); // ������������ ����
	else
		for (int i = 0; i < menu[SECOND].size(); i++)
			menu[SECOND][i].erase();
	/*������� �������*/
	menu[SECOND][0] = HorizontBorder(sizeOfMenu + 2);
	/*������ ����*/
	int i = 0;
	for (; i < sport.GetCategories().size(); i++) {
		menu[SECOND][i + 1] += "| " + Padding(sport.GetCategories()[i], sizeOfMenu) + " |";
	}
	/*������ �������*/
	++i;
	menu[SECOND][i] = HorizontBorder(sizeOfMenu + 2);

}
void Menu::CreateThirdLevelMenu(Sports& sport)
{
	/*��������� ������*/
	int sizeOfMenu = SizeOfMenu(sport.GetNames());
	/*������� ������ ����*/
	if (menu.size() == 2)
		menu.push_back(std::vector<std::string>(3)); // �������������� ����
	else
		for (int i = 0; i < menu[SECOND].size(); i++)
			menu[THIRD][i].erase();
	/*������� �������*/
	menu[THIRD][0] = HorizontBorder(sizeOfMenu + 2);
	/*������ ����*/	
	menu[THIRD][1] = "| ";
	for (int i = 0; i < sport.GetCategories().size(); i++) {
		menu[THIRD][1] += sport.GetCategories()[i], sizeOfMenu + " |";
	}
	/*������ �������*/
	menu[THIRD][2] = HorizontBorder(sizeOfMenu + 2);
}
void Menu::LightPointOfMenu(int levelOfMenu) {
	ChangeColor("reverse_default");
	std::string text;
	switch (levelOfMenu) {
	case FIRST:
		if (pointOfMenu == FIRST) {
			text = "������ ���� ������";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		if (pointOfMenu == SECOND) {
			text = "������ ���� ������";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		if (pointOfMenu == THIRD) {
			text = "�����";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		break;
	case SECOND:
		gotoxy(12, pointOfMenu + 3);
		if (choosen[FIRST] == "������ ���� ������")
			std::cout << summer.GetCategories()[pointOfMenu];
		if (choosen[FIRST] == "������ ���� ������")
			std::cout << winter.GetCategories()[pointOfMenu];

		break;
	case THIRD:
		break;
	}
	gotoxy(point);
	std::cout << text;
	ChangeColor("default");
}
void Menu::Choise(int& pointOfMenu, int levelOfMenu) {
	++this->levelOfMenu;
	switch (levelOfMenu) {
	case FIRST:
		if (pointOfMenu == THIRD) {
			exit(0);
		}
		else { 
			if (pointOfMenu == FIRST)
				choosen[levelOfMenu] = "������ ���� ������";
			if (pointOfMenu == SECOND)
				choosen[levelOfMenu] = "������ ���� ������";
			pointOfMenu = FIRST;
			DisplayMenu(levelOfMenu);
			DisplayMenu(this->levelOfMenu);
		}
		break;
	case SECOND:
		if (choosen[FIRST] == "������ ���� ������")
			choosen[levelOfMenu] = summer.GetCategories()[pointOfMenu];			
		if (choosen[FIRST] == "������ ���� ������")
			choosen[levelOfMenu] = winter.GetCategories()[pointOfMenu];
		DisplayMenu(levelOfMenu);
		DisplayMenu(this->levelOfMenu);
		break;
	case THIRD:
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

int Menu::SizeOfMenu(const std::vector<std::string>& vect)
{
	std::vector <int> lengths;
	for (auto i :vect)
		lengths.push_back(i.length());
	return *std::max_element(lengths.begin(), lengths.end());
	
}

std::string Menu::HorizontBorder(int length)
{
	std::string str;
	str.push_back('+');
	for (int i = 0; i < length; i++)
		str.push_back('-');
	str.push_back('+');
	return str;
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
		if (choosen[FIRST] == "������ ���� ������")
			CreateSecondLevelMenu(summer);
		if (choosen[FIRST] == "������ ���� ������")
			CreateSecondLevelMenu(winter);
		break;
	case THIRD:
		//menu.push_back(std::vector<std::string>(3));

		

		break;
	default: break;
	}
}

void Menu::CreateFirstLevelMenu()
{
	menu.push_back(std::vector<std::string>(3)); // �������������� ����
	menu[levelOfMenu][0] = HorizontBorder(kindofsports.length());
	menu[levelOfMenu][1] = "|" + kindofsports + "|";
	menu[levelOfMenu][2] = HorizontBorder(kindofsports.length());
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