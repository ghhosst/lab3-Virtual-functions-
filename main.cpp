#include "Object.h"
#include "Parallelepiped.h"
#include "Pyramid.h"
#include "Tetrahedron.h"
#include "Ball.h"
#include "Choice.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	Parallelepiped parallelepiped;
	Pyramid pyramid;
	Tetrahedron tetrahedron;
	Ball ball;

	int n;

	Object* arr[4] = { nullptr };
	arr[0] = new Parallelepiped; 
	arr[1] = new Pyramid;
	arr[2] = new Tetrahedron;
	arr[3] = new Ball;
	
	arr[0] = &parallelepiped;
	arr[1] = &pyramid;
	arr[2] = &tetrahedron;
	arr[3] = &ball;

	

	do{
		system("cls");
		cout << "\nВычислить\n"
			 << "1) Объём параллелепипеда\n"
			 << "2) Объём пирамиды\n"
			 << "3) Объём тетраэдра\n"
			 << "4) Объём шара\n"
			 << "5) Выйти из программы\n"
			 << "Выбранный пункт меню: ";
		cin >> n;

		switch (n){
		case 1:
			Choice(arr[0]);
			system("pause");
			break;
		case 2:
			Choice(arr[1]);
			system("pause");
			break;
		case 3:
			Choice(arr[2]);
			system("pause");
			break;
		case 4:
			Choice(arr[3]);
			system("pause");
			break;
		case 5:
			break;
		default:
			cout << "\nНекорректный выбор !!!\nПожалуйста, выберете пункт меню от 1 до 5.\n\n";
			system("pause");
			break;
		}
	} while (n != 5);

	return 0;
}