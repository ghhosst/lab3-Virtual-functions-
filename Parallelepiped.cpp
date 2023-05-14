#include "Parallelepiped.h"

ostream& operator << (ostream& os, const Parallelepiped& parallelepiped) {

	os << "������� ���������: " << parallelepiped.base_area << "\t������: " << parallelepiped.height << "\t�����: " << parallelepiped.volume;
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

		cout << "��������������" << endl;
	if (file == false) {
		cout << "\n������� �������� ������� ���������\nS = ";
		cin >> base_area;
		cout << "\n������� �������� ������, ���������� � ����� ���������\nH = ";
		cin >> height;
	}
	else {
		cout << "\n������� ���������\nS = " << base_area;
		cout << "\n\n������, ����������� � ����� ���������\nH = " << height;
	}
	
	volume = base_area * height;
	cout << "\n\n����� ���������������\nV = " << volume << "\n\n";
}

void Parallelepiped::OutputFile() {
	int x;
	fstream f_stream;	

	do {
		cout << "\n\n��������� ��������� � ���� ?\n"
			<< "1) ��\n"
			<< "2) ���\n"
			<< "��������� �����: ";
		cin >> x;
		switch (x) {
		case 1:
			f_stream.open("parallelepiped.txt", fstream::out);

			if (!f_stream.is_open()) {
				cout << "\n������ �������� ����� !!!" << "\n\n";
			}
			else {
				cout << "\n������ ������� ��������� !!!" << "\n\n";
				f_stream << *this;
			}

			f_stream.close();
			x = 2;
			break;
		case 2:
			break;
		default:
			cout << "\n������������ ����� !!!\n����������, �������� ����� �� 1 �� 2." << "\n\n";
			break;
		}
	} while (x != 2);
}

void Parallelepiped::InputFile() {
	fstream fs;
	fs.open("INpar.txt", fstream::in);

	if (!fs.is_open()) {
		cout << "\n������ �������� ����� !!!\n\n";
	}
	else {
		cout << "\n������ ������� ��������� !!!\n\n";
		fs >> *this;
	}

	fs.close();
}