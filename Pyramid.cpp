#include "Pyramid.h"

ostream& operator << (ostream& os, const Pyramid& pyramid) {

	os << "������� ���������: " << pyramid.base_area << "\t������: " << pyramid.height << "\t�����: " << pyramid.volume;

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

	cout << "��������" << endl;
	if (file == false) {
		cout << "\n������� �������� ������� ���������\nS = ";
		cin >> base_area;
		cout << "\n������� �������� ������, ���������� � ����� ���������\nH = ";
		cin >> height;
	}
	else {
		cout << "\n������� ���������\nS = " << base_area;
		cout << "\n������, ���������� � ����� ���������\nH = " << height;
	}

	volume = (double)((base_area * height) / 3.0);
	cout << "\n����� ��������\nV = " << volume << "\n\n";
}

void Pyramid::OutputFile() {
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
			f_stream.open("pyramid.txt", fstream::in | fstream::out);

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

void Pyramid::InputFile() {
	fstream fs;
	fs.open("INpyr.txt", fstream::in);

	if (!fs.is_open()) {
		cout << "\n������ �������� ����� !!!\n\n";
	}
	else {
		cout << "\n������ ������� ��������� !!!\n\n";
		fs >> *this;
	}

	fs.close();
}