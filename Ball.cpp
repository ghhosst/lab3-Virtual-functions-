#define _USE_MATH_DEFINES
#include "Ball.h"
#include <math.h>

ostream& operator << (ostream& os, const Ball& ball) {

	os << "����� �������: " << ball.radius << "\t�����: " << ball.volume;

	return os;
}

istream& operator >> (istream& is, Ball& ball) {

	is >> ball.radius;

	return is;
}

Ball::Ball() {
	radius = 0;
	volume = 0;
}

Ball::Ball(double radius) {
	this->radius = radius;
	this->volume = 0;
}

Ball::Ball(const Ball& other) {
	this->radius = other.radius;
	this->volume = other.volume;
}

Ball::~Ball() {
	radius = 0;
	volume = 0;
}

void Ball::Volume(bool file) {
	system("cls");

	cout << "���" << endl;
	if (file == false) {
		cout << "\n������� �������� ������� ����\nR = ";
		cin >> radius;
	}
	else {
		cout << "\n������ ����\nR = " << radius;
	}

	volume = (double)(4.0 / 3.0) * pow(radius, 3) * M_PI;
	cout << "\n����� ����\nV = " << volume << "\n\n";
}

void Ball::OutputFile() {
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
			f_stream.open("ball.txt", fstream::in | fstream::out);

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

void Ball::InputFile() {
	fstream fs;
	fs.open("INball.txt", fstream::in);

	if (!fs.is_open()) {
		cout << "\n������ �������� ����� !!!\n\n";
	}
	else {
		cout << "\n������ ������� ��������� !!!\n\n";
		fs >> *this;
	}

	fs.close();
}