#include "Menu.h"
//#define DEBUG
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
	int sizeOfMenu = SizeOfMenu(sport.FindAllValues(choosen[SECOND]), false);
	/*������� ������ ����*/
	if (menu.size() == 2)
		menu.push_back(std::vector<std::string>(3)); // �������������� ����
	else
		for (int i = 0; i < menu[THIRD].size(); i++)
			menu[THIRD][i].erase();

	/*������� �������*/
	menu[THIRD][0] = HorizontBorder(sizeOfMenu - 2);
	/*������ ����*/	
	menu[THIRD][1] = "| ";
	for (auto i : sport.FindAllValues(choosen[SECOND])) {
		menu[THIRD][1] += i + " | ";
	}
	menu[THIRD][1].erase(menu[THIRD][1].length());
	/*������ �������*/
	menu[THIRD][2] = HorizontBorder(sizeOfMenu - 2);
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
		gotoxy(15, 3);
		if (choosen[FIRST] == "������ ���� ������")
			LightPointOfThirdMenu(summer);
		if (choosen[FIRST] == "������ ���� ������")
			LightPointOfThirdMenu(winter);			
		break;
	}
	gotoxy(point);
	std::cout << text;
	ChangeColor("default");
}
void Menu::LightPointOfThirdMenu(Sports& sport)
{
	int size = 0;
	ChangeColor("reverse_default");
	for (int i = 0; i < sport.GetCategories().size(); i++)
		if (choosen[SECOND] == sport.GetCategories()[i]) {	
			/*������������� ����� �� ������� ����*/		
			if (pointOfMenu >= sport.FindAllValues(sport.GetCategories()[i]).size())
				pointOfMenu = sport.FindAllValues(sport.GetCategories()[i]).size() - 1;
			/*���������� ����� ����*/
			if (!pointOfMenu)
				gotoxy(SizeOfMenu(sport.GetCategories()) + 15, 3 + i);
			else {
				for (int j = 0; j < pointOfMenu; j++)
					size += sport.FindAllValues(sport.GetCategories()[i])[j].size();
				size += 3 * pointOfMenu;
				gotoxy(SizeOfMenu(sport.GetCategories()) + size + 15, 3 + i);
			}	
			choosen[THIRD] = sport.FindAllValues(sport.GetCategories()[i])[pointOfMenu];
			std::cout << choosen[THIRD];
			break;
		}
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
		pointOfMenu = FIRST;
		DisplayMenu(levelOfMenu);
		DisplayMenu(this->levelOfMenu);

		break;
	case THIRD:	
		--this->levelOfMenu;
		if (choosen[FIRST] == "������ ���� ������")
			PrintDescription(summer);
		if (choosen[FIRST] == "������ ���� ������")
			PrintDescription(winter);

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
		CreateMenu(levelOfMenu);
		if (choosen[FIRST] == "������ ���� ������") 
			DisplayThirdMenu(summer);	
		if (choosen[FIRST] == "������ ���� ������")
			DisplayThirdMenu(winter);
		if (this->levelOfMenu == THIRD)
			LightPointOfMenu(levelOfMenu);

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
	--levelOfMenu;
	pointOfMenu = 0;
	switch (levelOfMenu + 1)
	{
	case SECOND:
		system("cls");
		break;
	case THIRD:
		system("cls");
		DisplayMenu(levelOfMenu - 1);
		DisplayMenu(levelOfMenu);
		break;
	default:
		break;
	}
}

int Menu::SizeOfMenu(const std::vector<std::string>& vect, bool isVectical)
{
	std::vector <int> lengths;
	if (isVectical) {
		for (auto i : vect)
			lengths.push_back(i.length());
		return *std::max_element(lengths.begin(), lengths.end());
	}
	else {
		for (auto i : vect)
			lengths.push_back(i.length());
		return std::accumulate(lengths.begin(), lengths.end(), 0)
			+ vect.size() * 2  // ���������� ��������
			+ vect.size() + 1; // ���������� ������������
	}
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
#ifdef DEBUG
		if (color == "default")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
		if (color == "reverse_default")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 0));
#else
		if (color == "default")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((7 << 4) | 0));
		if (color == "reverse_default")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
#endif // !DEBUG

	};
}

void Menu::ChangePointOfMenu(int& pointOfMenu, int direction)
{
	if (levelOfMenu % 2 == 0) {
		if (pointOfMenu > 0) 
			if (direction == LEFT)
				--pointOfMenu;
		if(pointOfMenu < 2)
			if (direction == RIGHT)
				++pointOfMenu;

		if (direction == DOWN) 
			Choise(pointOfMenu, levelOfMenu);
		if (direction == UP) 
			HideMenu();
	}
	if (levelOfMenu % 2 == 1) {
		if (pointOfMenu > 0)
			if (direction == UP)
				--pointOfMenu;
		if (pointOfMenu < 2)
			if (direction == DOWN)
				++pointOfMenu;

		if (direction == RIGHT)
			Choise(pointOfMenu, levelOfMenu);
		if (direction == LEFT)
			HideMenu();
	}
			
	
}

void Menu::PrintDescription(Sports& sport)
{
	gotoxy(0, 10);
	for(int i = 0; i < sport.GetNames().size(); i++)
		if (choosen[THIRD] == sport.GetNames()[i]) {
		std::cout << sport.GetDescriptions()[i];
	}
}

void Menu::DisplayThirdMenu(Sports& sport)
{
	int sizeOfMenu = SizeOfMenu(sport.GetCategories());
	int i = 0;	
	for (;i < sport.GetCategories().size(); i++)
	if (choosen[SECOND] == sport.GetCategories()[i])
	for (int j = 0; j < 3; j++) {
			gotoxy(13 + sizeOfMenu, j + i + 2);
		std::cout << menu[levelOfMenu][j] << std::endl;	
	}
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
		if (choosen[FIRST] == "������ ���� ������")
			CreateThirdLevelMenu(summer);
		if (choosen[FIRST] == "������ ���� ������")
			CreateThirdLevelMenu(winter);
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