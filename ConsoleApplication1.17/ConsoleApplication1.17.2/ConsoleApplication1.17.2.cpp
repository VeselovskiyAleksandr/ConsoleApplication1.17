// ConsoleApplication1.17.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Задача 1. Банкетный стол.

#include <iostream>
#include <locale.h>
using namespace std;

void inicialization(bool array[][12], int t) {
for (int i = 0; i < t; i++) {
		for (int j = 0; j < 12; j++) {
			if ((i ==t-1) && (j != 0 && j != 6)) {
				array[i][j] = false;
			}
			else {
				array[i][j] = true;
			}	
		}
	}
}

void outputArray(bool array[][12], int t) {
	for (int i = 0; i < t; i++) {
			for (int j = 0; j < 12; j++) {
				cout << (int) array[i][j];
	      }
			cout << "\n";
    }
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool silverware[4][12], dinnerWare[3][12];
	int chairWare[2][6];
	inicialization(silverware, 4);
	inicialization(dinnerWare,3);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			chairWare[i][j] = 1;
		}
	}
	chairWare[0][4] = 2;
	silverware[0][8] = false;
	silverware[0][6] = false;
	silverware[3][8] = true; 
	dinnerWare[2][6] = false;
	cout << "\n Наличие столовых приборов к концу обеда\n";
	outputArray(silverware, 4);
	cout << "\n Наличие посуды к концу обеда\n";
	outputArray(dinnerWare, 3);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
