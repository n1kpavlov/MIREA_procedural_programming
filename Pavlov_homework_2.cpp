#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int i;
	double r, R, h, l, x, a, y, b, n;
	cout << "Введите № задания: ";
	cin >> i;
	if (i == 1) {
		bool f = true;
		cout << "Введите R: ";
		cin >> R;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		cout << "Введите r: ";
		cin >> r;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		cout << "Введите h: ";
		cin >> h;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		if (f == true) {
			if ((r == 0) or (R == 0) or (h == 0) or (r >= R)) {
				cout << "Ошибка ввода данных" << endl;
			}
			else {
				l = sqrt(pow(R - r, 2) + pow(h, 2));
				cout << "Объем усеченного конуса: " << (M_PI * h * (pow(R, 2) + R * r + pow(r, 2)) / 3) << endl;
				cout << "Площадь полной поверхности усеченного конуса: " << (M_PI * (pow(R, 2) + (R + r) * l + pow(r, 2))) << endl;
			}
		}
		else {
			cout << "Введены не числа" << endl;
		}
	}
	if (i == 2) {
		bool f = true;
		cout << "Введите x: ";
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		cout << "Введите a: ";
		cin >> a;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		if (f == true) {
			if (x == 0) {
				cout << "Ошибка" << endl;
			}
			else if (abs(x) < 1) {
				cout << "Ответ: " << (a * log(abs(x))) << endl;
			}
			else if (a >= pow(x, 2)) {
				cout << "Ответ: " << (sqrt(a - pow(x, 2))) << endl;
			}
			else {
				cout << "Ошибка" << endl;
			}
		}
		else {
			cout << "Введены не числа" << endl;
		}
		
	}
	if (i == 3) {
		bool f = true;
		cout << "Введите x: ";
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		cout << "Введите y: ";
		cin >> y;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		cout << "Введите b: ";
		cin >> b;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		if (f == true) {
			if (((b - y) <= 0) or ((b - x) < 0)) {
				cout << "Ошибка" << endl;
			}
			else {
				cout << "Ответ: " << (log(b - y) * sqrt(b - x)) << endl;
			}
		}
		else {
			cout << "Введены не числа" << endl;
		}
	}
	if (i == 4) {
		bool f = true;
		cout << "Введите n: ";
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			f = false;
		}
		if ((n > 0) and (f == true)) {
			cout << "Ответ:" << endl;
				for (int j = n; j < (n + 10); j++) {
					cout << j << endl;
				}
		}
		else {
			cout << "Ошибка ввода данных" << endl;
		}
	}
	if (i == 5) {
		cout << "Ответ:" << endl;
		for (x = -4; x <= 4; x += 0.5) {
			if (x == 1) {
				cout << "Невозможно найти" << endl;
			}
			else {
				cout << ((pow(x, 2) - 2 * x + 2) / (x - 1)) << endl;
			}
		}
	}
}