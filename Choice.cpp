#include "Choice.h"
#include <fstream>

void Choice(Object* object) {
	int x1;
	system("cls");
	cout << "\n1) ������ ������ � ����������\n"
		 << "2) ��������� ������ �� ����� � ���������� �����\n"
		 << "3) ����� �� ����\n"
		 << "��������� �����: ";
	cin >> x1;

	switch (x1) {
	case 1:
		object->Volume(false);
		object->OutputFile();
		break;
	case 2:
		/* ����� ����������� �������� ������ �� ����� */ 
		object->InputFile();
		object->Volume(true);
		object->OutputFile();
		break;
	case 3:
		break;
	default:
		cout << "\n������������ ����� !!!\n����������, �������� ����� �� 1 �� 3.\n\n";
		break;
	}
}