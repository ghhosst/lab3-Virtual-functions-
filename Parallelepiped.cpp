#include "Parallelepiped.h"

ostream& operator << (ostream& os, const Parallelepiped& parallelepiped) {

	os << "Площадь основания: " << parallelepiped.base_area << "\tВысота: " << parallelepiped.height << "\tОбъём: " << parallelepiped.volume;
	return os;
}

istream& operator >> (istream& is, Parallelepiped& parallelepiped) {

	is >> parallelepiped.base_area >> parallelepiped.height;

	return is;
}

Parallelepiped::Parallelepiped() {
	base_area = 0;
	height = 0;
	volume = 0;
}

Parallelepiped::Parallelepiped(double base_area, double height) {
	this->base_area = base_area;
	this->height = height;
	this->volume = 0;
}

Parallelepiped::Parallelepiped(const Parallelepiped& other) {
	this->base_area = other.base_area;
	this->height = other.height;
	this->volume = other.volume;
}

Parallelepiped::~Parallelepiped() {
	base_area = 0;
	height = 0;
	volume = 0;
}

void Parallelepiped::Volume(bool file) {
	system("cls");

		cout << "Параллелепипед" << endl;
	if (file == false) {
		cout << "\nВведите значение площади основания\nS = ";
		cin >> base_area;
		cout << "\nВведите значение высоты, проведённой к этому основанию\nH = ";
		cin >> height;
	}
	else {
		cout << "\nПлощадь основания\nS = " << base_area;
		cout << "\n\nВысота, проведенная к этому основанию\nH = " << height;
	}
	
	volume = base_area * height;
	cout << "\n\nОбъём параллелепипеда\nV = " << volume << "\n\n";
}

void Parallelepiped::OutputFile() {
	int x;
	fstream f_stream;	

	do {
		cout << "\n\nСохранить результат в файл ?\n"
			<< "1) Да\n"
			<< "2) Нет\n"
			<< "Выбранный пункт: ";
		cin >> x;
		switch (x) {
		case 1:
			f_stream.open("parallelepiped.txt", fstream::out);

			if (!f_stream.is_open()) {
				cout << "\nОшибка открытия файла !!!" << "\n\n";
			}
			else {
				cout << "\nДанные успешно сохранены !!!" << "\n\n";
				f_stream << *this;
			}

			f_stream.close();
			x = 2;
			break;
		case 2:
			break;
		default:
			cout << "\nНекорректный выбор !!!\nПожалуйста, выберете пункт от 1 до 2." << "\n\n";
			break;
		}
	} while (x != 2);
}

void Parallelepiped::InputFile() {
	fstream fs;
	fs.open("INpar.txt", fstream::in);

	if (!fs.is_open()) {
		cout << "\nОшибка открытия файла !!!\n\n";
	}
	else {
		cout << "\nДанные успешно загружены !!!\n\n";
		fs >> *this;
	}

	fs.close();
}