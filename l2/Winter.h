#pragma once
#include "Sports.h"

class Winter : public Sports {

public:
	Winter() {
		names = { 
			"�������", 
			"��������",
			"������������ �����", 
			"�������� �������",
			"���� - ����",
			"����������� �����",
			"������ ���������",
			"������ �����" 
		};
		categories = { 
			"�������", 
			"��������� ���� ������", 
			"������ ���� ������" 
		};
		descriptions = { 
			"������ ����������� ��� ������, �������������� ����� ���������� ����� \
�� ���������� �������������� ������� ������� �� �����",
			"������ ����������� ��� ������, �������������� ����� ����� �� �������� \
����� �� �������������� ����� �� ����������� ����, ���������� �������� \
������������ �� ����� ���� �������.",
			"��� ������, � ������� ���������� ��� ����� ������� ������������ ����������� \
��������� �� ������� �������� �� ���������� �����.",
			"������ ��� ������, � ������� ���������� ������������ �� ������� �� ���� � ����������� \
�������������� ���������, ���� ����� ��� ������. ",
			"��� ����������� ���� �� �������, ������������� � ����������� ������� \
����������� ���������������� ��������� ������ ��������� ��������.",
			"����� � ��� �� ����������� �����. ��� ������, � ����� ���������� ��� ���������\
������ ��������� ����� �� ����� ����.",
			"������ ��������� �������� � ���� 2 ����������: ������ � ��������� � ������ ����� �� 15 ��.",
			"������ ����� � ����� �� ����� �� ����������� ��������� �� ���������� \
�������������� ������ ����� ��� ����������� ���������"	
		};
		int i = 0;
		for (; i < 2; i++)
			category_names.emplace(categories[0], names[i]);
		for (; i < 5; i++)
			category_names.emplace(categories[1], names[i]);
		for (; i < names.size(); i++)
			category_names.emplace(categories[2], names[i]);
	}
};