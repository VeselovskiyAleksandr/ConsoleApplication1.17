// ConsoleApplication1.17.9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 14. Итоговое задание. Морской бой.

#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

void inicialization_function(char arrayS[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arrayS[i][j] = '~';	
		}
	}	
}

bool correctCoordinate_function(string s, int len) {
	bool correct = true, number=true;
	for (int i = 0; i < 4; i++) {
		if (s[i] - '0' < 0 || s[i] - '0' > 9) {
			number = false;
			break;
		}
	}
		if (s[0]!= s[2] && s[1] != s[3]) {
			cout << "\n Укажите правильно координаты корабля.";
			correct = false;
		}
		else if ((s[0] == s[2] && s[3] - s[1] != len-1) || (s[1] == s[3]&& s[2] - s[0] != len-1)) {
			cout << "\n Укажите правильно координаты корабля.";
			correct = false;
		}
		else if( number== false) {
			cout << "\n Укажите правильно координаты корабля.";
			correct = false;
		}
		else {
			correct = true;
		}
	return correct;
}

bool inputCorrect_function(string s, char arrayS[][10]) {
	int  m, p, n, q;//переменные принимают индексы элементов массива arrayS.
	bool correct = true;
	 m = (int)s[0]-'0';  p = (int)s[2]-'0';  n = (int)s[1]-'0'; q = (int)s[3]-'0';
	for (int i = m; i < p + 1; i++) {
		for (int j = n; j < q + 1; j++) {
			if ((arrayS[i][j] != '~')||((q<9)&&((arrayS[i + 1][j + 1] == '#') || (arrayS[i - 1][j + 1] == '#')
				||( arrayS[i][q + 1] == '#')))||(arrayS[m+1][n]=='#') || (arrayS[m - 1][n] == '#')||
				((n>0)&&((arrayS[m - 1][n-1] == '#')|| (arrayS[m + 1][n-1] == '#') || (arrayS[m][n - 1] == '#'))))
			{
				correct = false;
                  break;
			}
			
			else {
				
				correct = true;
					
			}		
		}
	}
      return correct;
}

char inputShipPlacement_function(int len, char arrayS[][10]) {
	int  countShip = 0;
	int  m, p, n, q;//переменные принимают индексы элементов массива arrayS.
	string str;	
	while (countShip < 5 - len) {
		do
		{
			cin >> str;
			if (str.length() != 4) {
				cout << "\nУкажите правильно координаты.";
			}
		} while((str.length()!= 4)||(inputCorrect_function(str, arrayS) != true) ||
			(correctCoordinate_function(str, len) != true));
		 m = (int)str[0]-'0';  p = (int)str[2]-'0';  n = (int)str[1]-'0'; q = (int)str[3]-'0';
		for (int i = m; i < p + 1; i++) {
			for (int j = n; j < q + 1; j++) {
				arrayS[i][j] = '#';			
			}
		}
             countShip++;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << arrayS[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return  arrayS[9][9];
}

char shipPlacement_function(char arrayS[][10]){
	int  len;
	string str;
    cout << "\n Укажите координаты катеров и тральщиков \n";
     len = 1;
	 inputShipPlacement_function(len, arrayS);
	cout << "\n Укажите координаты эсминцев ";
		len = 2;
		inputShipPlacement_function(len, arrayS);
		cout << "\n Укажите координаты крейсеров ";
		len = 3;
		inputShipPlacement_function(len, arrayS);
		cout << "\n Укажите координаты линкора ";
		len = 4;
		inputShipPlacement_function(len, arrayS);
		return arrayS[9][9];
}


void shipLayOut_function(char arrayPl[][10], char arrayIg[][10]) {
	for (int i = 0; i < 10; i++) {
		cout << "     ";
		for (int j = 0; j < 10; j++) {
			cout << arrayPl[i][j] << " ";
		}
		cout << "               ";
		for (int j = 0; j < 10; j++) {
			cout << arrayIg[i][j] << " ";
		}
		cout << "\n";
	}
}

bool correctShot_function(string s1, string s2) {
	int t, d;//переменные принимают индексы элементов массивов S1 и S2.
	t = s1[0] - '0'; d = s2[0] - '0';
	if (s1.length() > 1 || s2.length() > 1 || t < 0 || t>9 || d < 0 || d>9) {
		cout << "\nУкажите правильно координаты.";
		return false;
	}
	else {
		return true;
	}
}


void battleMap_function(char seaBattleMapOne[][10], char seaBattleMapTwo[][10],
	char intendedGoalsMapOne[][10], char intendedGoalsMapTwo[][10]) {
	int  t, d;//переменные принимают индексы элементов массивов stri и strj.
	int counterHitOne = 0, counterHitTwo = 0;
	bool correct = true;
	string stri, strj;
	cout << "\n              К  А  Р  Т  А           С  Р  А  Ж  Е  Н  И  Я\n";
	while (counterHitOne < 20 && counterHitTwo < 20) {	
		cout << "\n Расположение кораблей игрока №1   Координаты выстрелов игрока №1\n";
		shipLayOut_function(seaBattleMapOne, intendedGoalsMapOne);
		cout << "\n Расположение кораблей игрока №2   Координаты выстрелов игрока №2\n\n";
		shipLayOut_function(seaBattleMapTwo, intendedGoalsMapTwo);
		cout << "\nИгрок №1 произведите выстрел\n"; 		
		do {
			cin >> stri >> strj;
			correctShot_function(stri, strj);
				t = stri[0] - '0'; d = strj[0] - '0';
		} while (correctShot_function(stri, strj) != true);
			cout << "          Ба-бах!";            
			if (seaBattleMapTwo[t][d] == '~') {           
				intendedGoalsMapOne[t][d] = 'V';          
				cout << "\n          Мимо\n";
			}
			else if (seaBattleMapTwo[t][d] == '#') {
		          seaBattleMapTwo[t][d] = 'X';
				intendedGoalsMapOne[t][d] = 'X';
				cout << "\n            Попал\n";
				counterHitOne++;
				if (counterHitOne ==20 ) {
					cout << "\n Победил игрок №1 !!!";
					break;
				}
			}
		cout << "\nИгрок №2 произведите выстрел\n";
		do {
			cin >> stri >> strj;
			t = stri[0] - '0'; d = strj[0] - '0';
			correctShot_function(stri, strj);
		} while (correctShot_function(stri, strj) != true);
		cout << "          Ба-бах!";
		if (seaBattleMapOne[t][d] == '~') {
			intendedGoalsMapTwo[t][d] = 'V';
			cout << "\n          Мимо\n";
		}
		else if (seaBattleMapOne[t][d] == '#') {
			seaBattleMapOne[t][d] = 'X';
			intendedGoalsMapTwo[t][d] = 'X';
			cout << "\n            Попал\n";
			counterHitTwo++;
			if (counterHitTwo == 20) {
				cout << "\n Победил игрок №2 !!!";
				break;
			   }
		    }
		}
	}



int main()
{
	setlocale(LC_ALL, "Russian");
	char seaBattleMapOne[10][10], seaBattleMapTwo[10][10],
		intendedGoalsMapOne[10][10], intendedGoalsMapTwo[10][10];
	cout<<"\n\n    М    О   Р   С   К   О   Е       С   Р   А   Ж   Е   Н   И   Е\n\n";
	cout << "(При вводе координат указывайте начальную и конечную координаты корабля.)\n";
	cout<<"(Для одноклеточных кораблей координаты начала и конца совпадают.)\n";
	inicialization_function(seaBattleMapOne);
	inicialization_function(seaBattleMapTwo);
	inicialization_function(intendedGoalsMapOne);
	inicialization_function(intendedGoalsMapTwo);
cout << "\nКарта размещения кораблей игрока №1";
	shipPlacement_function(seaBattleMapOne);
cout << "\nКарта размещения кораблей игрока №2";
	shipPlacement_function(seaBattleMapTwo);
	battleMap_function(seaBattleMapOne, seaBattleMapTwo,
		intendedGoalsMapOne, intendedGoalsMapTwo);	
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
