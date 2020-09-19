#include "Menu.h"
//#define DEBUG
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
	/*вычисл€ем размер*/
	int sizeOfMenu = SizeOfMenu(sport.GetCategories());
	/*создаем второе меню*/
	if (menu.size() == 1)
		menu.push_back(std::vector<std::string>(2 + sport.GetCategories().size())); // вертикальное меню
	else
		for (int i = 0; i < menu[SECOND].size(); i++)
			menu[SECOND][i].erase();
	/*верхн€€ граница*/
	menu[SECOND][0] = HorizontBorder(sizeOfMenu + 2);
	/*пункты меню*/
	int i = 0;
	for (; i < sport.GetCategories().size(); i++) {
		menu[SECOND][i + 1] += "| " + Padding(sport.GetCategories()[i], sizeOfMenu) + " |";
	}
	/*нижн€€ граница*/
	++i;
	menu[SECOND][i] = HorizontBorder(sizeOfMenu + 2);

}
void Menu::CreateThirdLevelMenu(Sports& sport)
{
	/*вычисл€ем размер*/
	int sizeOfMenu = SizeOfMenu(sport.FindAllValues(choosen[SECOND]), false);
	/*создаем третье меню*/
	if (menu.size() == 2)
		menu.push_back(std::vector<std::string>(3)); // горизонтальное меню
	else
		for (int i = 0; i < menu[THIRD].size(); i++)
			menu[THIRD][i].erase();

	/*верхн€€ граница*/
	menu[THIRD][0] = HorizontBorder(sizeOfMenu - 2);
	/*пункты меню*/	
	menu[THIRD][1] = "| ";
	for (auto i : sport.FindAllValues(choosen[SECOND])) {
		menu[THIRD][1] += i + " | ";
	}
	menu[THIRD][1].erase(menu[THIRD][1].length());
	/*нижн€€ граница*/
	menu[THIRD][2] = HorizontBorder(sizeOfMenu - 2);
}
void Menu::LightPointOfMenu(int levelOfMenu) {
	ChangeColor("reverse_default");
	std::string text;
	switch (levelOfMenu) {
	case FIRST:
		if (pointOfMenu == FIRST) {
			text = "Ћетние виды спорта";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		if (pointOfMenu == SECOND) {
			text = "«имние виды спорта";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		if (pointOfMenu == THIRD) {
			text = "¬ыход";
			point = { (SHORT)kindofsports.find(text) + 1, 1 };
		}
		break;
	case SECOND:
		gotoxy(12, pointOfMenu + 3);
		if (choosen[FIRST] == "Ћетние виды спорта")
			std::cout << summer.GetCategories()[pointOfMenu];
		if (choosen[FIRST] == "«имние виды спорта")
			std::cout << winter.GetCategories()[pointOfMenu];
		break;
	case THIRD:
		gotoxy(15, 3);
		if (choosen[FIRST] == "Ћетние виды спорта")
			LightPointOfThirdMenu(summer);
		if (choosen[FIRST] == "«имние виды спорта")
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
			/*предотвратить выход за пределы меню*/		
			if (pointOfMenu >= sport.FindAllValues(sport.GetCategories()[i]).size())
				pointOfMenu = sport.FindAllValues(sport.GetCategories()[i]).size() - 1;
			/*подсветить пункт меню*/
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
				choosen[levelOfMenu] = "Ћетние виды спорта";
			if (pointOfMenu == SECOND)
				choosen[levelOfMenu] = "«имние виды спорта";
			pointOfMenu = FIRST;
			DisplayMenu(levelOfMenu);
			DisplayMenu(this->levelOfMenu);
		}
		break;
	case SECOND:
		if (choosen[FIRST] == "Ћетние виды спорта")
			choosen[levelOfMenu] = summer.GetCategories()[pointOfMenu];			
		if (choosen[FIRST] == "«имние виды спорта")
			choosen[levelOfMenu] = winter.GetCategories()[pointOfMenu];
		pointOfMenu = FIRST;
		DisplayMenu(levelOfMenu);
		DisplayMenu(this->levelOfMenu);

		break;
	case THIRD:	
		--this->levelOfMenu;
		if (choosen[FIRST] == "Ћетние виды спорта")
			PrintDescription(summer);
		if (choosen[FIRST] == "«имние виды спорта")
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
		if (choosen[FIRST] == "Ћетние виды спорта") 
			DisplayThirdMenu(summer);	
		if (choosen[FIRST] == "«имние виды спорта")
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
			+ vect.size() * 2  // количество пробелов
			+ vect.size() + 1; // количество разделителей
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
		if (choosen[FIRST] == "Ћетние виды спорта")
			CreateSecondLevelMenu(summer);
		if (choosen[FIRST] == "«имние виды спорта")
			CreateSecondLevelMenu(winter);
		break;
	case THIRD:
		if (choosen[FIRST] == "Ћетние виды спорта")
			CreateThirdLevelMenu(summer);
		if (choosen[FIRST] == "«имние виды спорта")
			CreateThirdLevelMenu(winter);
		break;
	default: break;
	}
}

void Menu::CreateFirstLevelMenu()
{
	menu.push_back(std::vector<std::string>(3)); // горизонтальное меню
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