#include "Pyramid.h"

ostream& operator << (ostream& os, const Pyramid& pyramid) {

	os << "Площадь основания: " << pyramid.base_area << "\tВысота: " << pyramid.height << "\tОбъём: " << pyramid.volume;

	return os;
}

istream& operator >> (istream& is, Pyramid& pyramid) {

	is >> pyramid.base_area >> pyramid.height;

	return is;
}

Pyramid::Pyramid() {
	base_area = 0;
	height = 0;
	volume = 0;
}

Pyramid::Pyramid(double base_area, double height) {
	this->base_area = base_area;
	this->height = height;
	this->volume = 0;
}

Pyramid::Pyramid(const Pyramid& other) {
	this->base_area = other.base_area;
	this->height = other.height;
	this->volume = other.volume;
}

Pyramid::~Pyramid() {
	base_area = 0;
	height = 0;
}

void Pyramid::Volume(bool file) {
	system("cls");

	cout << "Пирамида" << endl;
	if (file == false) {
		cout << "\nВведите значение площади основания\nS = ";
		cin >> base_area;
		cout << "\nВведите значение высоты, проведённой к этому основанию\nH = ";
		cin >> height;
	}
	else {
		cout << "\nПлощадь основания\nS = " << base_area;
		cout << "\nВысота, проведённая к этому основанию\nH = " << height;
	}

	volume = (double)((base_area * height) / 3.0);
	cout << "\nОбъём пирамиды\nV = " << volume << "\n\n";
}

void Pyramid::OutputFile() {
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
			f_stream.open("pyramid.txt", fstream::in | fstream::out);

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

void Pyramid::InputFile() {
	fstream fs;
	fs.open("INpyr.txt", fstream::in);

	if (!fs.is_open()) {
		cout << "\nОшибка открытия файла !!!\n\n";
	}
	else {
		cout << "\nДанные успешно загружены !!!\n\n";
		fs >> *this;
	}

	fs.close();
}