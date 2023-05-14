#include "Choice.h"
#include <fstream>

void Choice(Object* object) {
	int x1;
	system("cls");
	cout << "\n1) Ввести данные с клавиатуры\n"
		 << "2) Загрузить данные из файла и рассчитать объём\n"
		 << "3) Выйти из меню\n"
		 << "Выбранный пункт: ";
	cin >> x1;

	switch (x1) {
	case 1:
		object->Volume(false);
		object->OutputFile();
		break;
	case 2:
		/* Здесь реализовать загрузку данных из файла */ 
		object->InputFile();
		object->Volume(true);
		object->OutputFile();
		break;
	case 3:
		break;
	default:
		cout << "\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 3.\n\n";
		break;
	}
}