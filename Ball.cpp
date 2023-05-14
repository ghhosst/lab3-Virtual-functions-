#define _USE_MATH_DEFINES
#include "Ball.h"
#include <math.h>

ostream& operator << (ostream& os, const Ball& ball) {

	os << "Длина радиуса: " << ball.radius << "\tОбъём: " << ball.volume;

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

	cout << "Шар" << endl;
	if (file == false) {
		cout << "\nВведите значение радиуса шара\nR = ";
		cin >> radius;
	}
	else {
		cout << "\nРадиус шара\nR = " << radius;
	}

	volume = (double)(4.0 / 3.0) * pow(radius, 3) * M_PI;
	cout << "\nОбъём шара\nV = " << volume << "\n\n";
}

void Ball::OutputFile() {
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
			f_stream.open("ball.txt", fstream::in | fstream::out);

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

void Ball::InputFile() {
	fstream fs;
	fs.open("INball.txt", fstream::in);

	if (!fs.is_open()) {
		cout << "\nОшибка открытия файла !!!\n\n";
	}
	else {
		cout << "\nДанные успешно загружены !!!\n\n";
		fs >> *this;
	}

	fs.close();
}