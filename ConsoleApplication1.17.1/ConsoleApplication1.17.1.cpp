// ConsoleApplication1.17.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Задача 2.

#include <iostream>
#include <locale.h>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char tic_tac_toe[3][3] = { {' ',' ',' '},
							 {' ',' ',' '},
							 {' ',' ',' '} };

	bool correct = true;
	int i, j, countX = 0, countO = 0, countWinXI = 0, countWinOI=0, countWinXIJ = 0, countWinOIJ = 0;
	int countWinXJ = 0, countWinOJ = 0, countWinXJI = 0, countWinOJI = 0;
	int counterMove = 0;
		
	do {
cout << "\n Игровое поле: \n";
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				cout << tic_tac_toe[i][j]<<" ";
			}
			cout << "\n";
		}
		if ((countWinXI == 3)||(countWinXJ == 3)||(countWinXIJ == 3)||(countWinXJI == 3)) {
			cout << "\n Победили крестики!";
			break;
		}
		else if ((countWinOI == 3)||(countWinOJ == 3)||(countWinOIJ == 3)||(countWinOJI == 3)) {
			cout << "\n Победили нолики!";
			break;
		}
		else if (counterMove == 9) {
			cout << "\n Ничья.";
			break;
		}
		do {
			cout << "\n Укажите номер строки и столбца, выбранной клетки \n";
			cin >> i >> j;
			if ((tic_tac_toe[i][j] == 'X') || (tic_tac_toe[i][j] == 'O')) {
				cout << "\n Данная клетка занята. Укажите правильно клетку.";
				correct = false;
			}
			else {
				correct = true;
			}
		} while (correct!=true);
		 if ((i < 0) || (i > 2) || (j < 0) || (j > 2)) {
			cout << "\n Сделайте правильный ход ";		
		}
		else {
			cout << "\n Сделайте Ваш ход: ";
			cin >> tic_tac_toe[i][j];
			if ((tic_tac_toe[i][j] != 'X') && (tic_tac_toe[i][j] != 'O')) {
				cout << "\n Сделайте правильный ход ";
				tic_tac_toe[i][j] = ' ';	
			}
			else {
				counterMove++;
				if (tic_tac_toe[i][j] == 'X') {
					countX++; countO = 0;
					if (countX > 1) {
						cout << "\n Сделайте правильный ход ";
						tic_tac_toe[i][j] = ' ';
					}
				}
				else if (tic_tac_toe[i][j] == 'O') {
					countO++; countX = 0;
					if (countO > 1) {
						cout << "\n Сделайте правильный ход ";
						tic_tac_toe[i][j] = ' ';
					}
				}
			 }
		  }	
		if (correct) {
			countWinXIJ = 0; countWinOIJ = 0; countWinXJI = 0; countWinOJI = 0;
			for (i = 0; i < 3; i++) {
				countWinXJ = 0; countWinOJ = 0;
				for (j = 0; j < 3; j++) {
					if (tic_tac_toe[i][j] == 'X') {
						countWinXJ++;	
						if (countWinXJ == 3) {
							break;
						}
					}
					else if (tic_tac_toe[i][j] == 'O') {
						countWinOJ++;
						if (countWinOJ == 3) {
							break;
						}
					}
				if ((i == j) && (tic_tac_toe[i][j] == 'X')) {
					countWinXIJ++; 
                 }
				else if ((i == j) && (tic_tac_toe[i][j] == 'O')) {
					countWinOIJ++;
				}
				 if ((i == 2 - j) && (tic_tac_toe[i][j] == 'X')) {
					
					countWinXJI++;
				}
				else if ((j ==2-i) && (tic_tac_toe[i][j] == 'O')) {
					countWinOJI++;
				}
	
				else if(tic_tac_toe[i][j] == 'O') {
					 countWinOI++;
			    	}
		    	} 		
				if (countWinXJ == 3) {
					break;
				}
				if (countWinOJ == 3) {
					break;
				}
			}		
			for (j = 0; j < 3; j++) {
				countWinXI = 0; countWinOI = 0;
				for (i = 0; i < 3; i++) {
					if (tic_tac_toe[i][j] == 'X') {
							countWinXI++;
						if (countWinXI == 3) {
							break;
						}	
					}
					else if (tic_tac_toe[i][j] == 'O') {
						countWinOI++;
						if (countWinOI == 3) {
							break;
						}
					}
				}
				if (countWinXI == 3) {
					break;
				}
				if (countWinOI == 3) {
					break;
				}
			 }
		  }
		} while (true);
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