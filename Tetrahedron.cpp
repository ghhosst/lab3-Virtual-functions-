#include "Tetrahedron.h"
#include <math.h>

ostream& operator << (ostream& os, const Tetrahedron& tetrahedron) {

	os << "����� �����: " << tetrahedron.edge_length << "\t�����: " << tetrahedron.volume;

	return os;
}

istream& operator >> (istream& is, Tetrahedron& tetrahedron) {

	is >> tetrahedron.edge_length;

	return is;
}

Tetrahedron::Tetrahedron() {
	edge_length = 0;
	volume = 0;
}

Tetrahedron::Tetrahedron(double edge_length) {
	this->edge_length = edge_length;
	this->volume = 0;
}

Tetrahedron::Tetrahedron(const Tetrahedron& other) {
	this->edge_length = other.edge_length;
	this->volume = other.volume;
}

Tetrahedron::~Tetrahedron() {
	edge_length = 0;
	volume = 0;
}

void Tetrahedron::Volume(bool file){
	system("cls");

	cout << "��������" << endl;
	if (file == false) {
		cout << "\n������� �������� ����� ����� ���������\nl = ";
		cin >> edge_length;
	}
	else {
		cout << "\n����� ����� ���������\nl = " << edge_length;
	}

	volume = pow(edge_length, 3) * (sqrt(2.0) / 12.0);
	cout << "\n����� ���������\nV = " << volume << "\n\n";
}

void Tetrahedron::OutputFile() {
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
			f_stream.open("tetrahedron.txt", fstream::in | fstream::out);

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

void Tetrahedron::InputFile() {
	fstream fs;
	fs.open("INtet.txt", fstream::in);

	if (!fs.is_open()) {
		cout << "\n������ �������� ����� !!!\n\n";
	}
	else {
		cout << "\n������ ������� ��������� !!!\n\n";
		fs >> *this;
	}

	fs.close();
}