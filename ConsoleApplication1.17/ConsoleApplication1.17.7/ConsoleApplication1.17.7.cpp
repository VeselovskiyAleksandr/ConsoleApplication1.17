// ConsoleApplication1.17.7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Задача 7. Пупырка.

#include <iostream>
#include <locale.h>
using namespace std;

void sequentialChange_function(bool arrayP[12][12]) {
	int i, j;
	cout << "\nТак выглядит плёнка:\n";
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			if (arrayP[i][j] == true) {
				cout << 'O'<<" ";
			}
			else {
				cout << 'X' << " ";
			}
		}
		cout << "\n";
	}
}

bool initialization_function(bool arrayP[12][12]) {
	int i, j;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			arrayP[i][j] = true;
		}
	}
	//sequentialChange_function(arrayP);
	return arrayP;
}

void bubblePopping_function(bool arrayP[12][12]) {
	int i, j;
	int k, l, t, d, countBubble=0;
	bool correct = true;
	while (true) {
		do {
			cout << "\n Укажите область, которую необходимо лопнуть:\n";
			cout << "\nУкажите верхнюю границу слева на право\n";
			cin >> k >> l;
			cout << "\nУкажите левую границу сверху вниз\n";
			cin >> t >> d;
			if (l<0 || l >= 12 || k>l || d<0 || d >= 12 || t>d) {
				cout << "\nУкажите правильно область\n";
				correct = false;
			}
			for (i = t; i <= d; i++) {
				for (j = k; j <= l; j++) {
					if (arrayP[i][j] == false) {
						cout << "\n В указанной области имеются лопнувшие пупырки. Измените границы области.\n";
						correct = false;
						break;
					}
					else if (arrayP[i][j] == true) {
						correct = true;
					}
					
					}
                   if (arrayP[i][j] == false) {
						break;
				}
			}
			} while (correct != true);
			for (i = 0; i < 12; i++) {
				for (j = 0; j < 12; j++) {
					if (i >= t && i <= d && j >= k && j <= l) {
						arrayP[i][j] =false;
						cout << " pop! ";
						countBubble++;
						if (countBubble == 144) {
							break;
						}
					}
					
				}
            if (countBubble == 144) {
						break;
					}
			}
			if (countBubble == 144) {
				cout << "\n\nВсе пупырки лопнуты!\n";
				break;
			}
			sequentialChange_function(arrayP);
	  }	
}


														   
int main()
{
	setlocale(LC_ALL, "Russian");
	bool bubbleWrap[12][12];
	initialization_function (bubbleWrap);
	sequentialChange_function(bubbleWrap);
	bubblePopping_function( bubbleWrap);
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
