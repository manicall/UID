#pragma once
#include "Sports.h"

class Summer : public Sports {

public:
	Summer() {
		names = { 
			"�����-������� ������", 
			"������� ������", 
			"��������", 
			"���������� ��������", 
			"������ � ����",
			"�������",
			"������", 
			"������ ���������"
		};
		categories = { 
			"������", 
			"������ ���� ������",   
			"������ �����"
		};
		descriptions = { 
			L"����������� ��� ������, � ������� ��������� ����������� ������������ �������� \
����������� �������� �������� ������� ��������� �� ���������� \
� ������� ��������� � �����. � �����-������� ������, � ������� �� �������, \
��������� ����������� �������� ������ � ������� ��� ������",
		    L"���������� ������������ � ����������� ��� ������, ������������� � \
�������� ���� ����������� �� ����������� ��������, � ����������� ��������� \
������, � ������� ������ �� ���������� �������� �������� ������� �� ������� � \
��������. � ������� ������, � ������� �� �����-������� � ������ �� ������, ��������� ������� \
��� ����������, �������� � �������� ������������� ��� ��� ���������� ������-���� ������.",
			L"��� ������ ��� ���������� ����������, ������������� � ����������� \
������ �� ���������� ����� ��������� ���������",
			L"������ ��� ������, ��������� � ����������� � ���� ��������� ����� ��� ������.",
			L"���� �� ������ ����� ������, ������ � ����, ����������� � ��������� \
��������: �����, ���� ���������. �� ����� ������ ���������� ��������� \
��� �������������� ��������",
			L"�������, �� ������������� ������������ �  �������� �  ������ \
����� �������� ���� � ����������� ��� ������.",
			L"������������ �� ����������� ����������� � ����������� ������� � ����������� \
��������� � ������, ���������� �� ��������� ����.",
			L"��� ������� ������, ������� ������� �� �������� ����, ������� ��������� ��� \
������ (������ ����), ����������� ����������� ��� ������� (������ ����)"	
		};
		int i = 0;
		for (; i < 2; i++)
			category_names.emplace(categories[0], names[i]);
		for (; i < 5; i++)
				category_names.emplace(categories[1], names[i]);
		for(; i < names.size(); i++)
			category_names.emplace(categories[2], names[i]);

	}
};
