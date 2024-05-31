#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int i;
    double a, b, c;
    cout << "Введите № задания: ";
    cin >> i;
    if (i == 1) {
        cout << "Никита" << endl;
    }
    else if (i == 2) {
        bool f = true;
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        if (f == true) {
            cout << "Сумма: " << (b + c) << endl;
            cout << "Разность: " << (b - c) << endl;
            cout << "Произведение:" << (b * c) << endl;
            if (c != 0) {
                cout << "Частное: " << (b / c) << endl;
            }
            else {
                cout << "Невозможно поделить" << endl;
            }
        }
        else {
            cout << "Введены не числа" << endl;
        }
    }
    else if (i == 3) {
        bool f = true;
        cout << "Введите b: ";
        cin >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        if (f == true) {
            if ((b == 0) and (c == 0)) {
                cout << "Уравнение bx+c=0 имеет бесконечное колличество решений" << endl;
            }
            else if (b == 0) {
                cout << "Уравнение bx+c=0  не имеет решений" << endl;
            }
            else if (c == 0) {
                cout << "Решение уравнения bx+c=0: 0" << endl;
            }
            else {
                cout << "Решение уравнения bx+c=0: " << ((-1) * c / b);
            }
        }
        else {
            cout << "Введены не числа" << endl;
        }
    }
    else if (i == 4) {
        double x1, x2;
        bool f = true;
        cout << "Введите a: ";
        cin >> a;
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
        cout << "Введите c: ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        if (f == true) {
            if (a == 0) {
                if ((b == 0) and (c == 0)) {
                    cout << "Уравнение ax^2+bx+c=0 имеет бесконечное колличество решений" << endl;
                }
                else if (b == 0) {
                    cout << "Уравнение ax^2+bx+c=0  иррационально" << endl;
                }
                else if (c == 0) {
                    cout << "Решение уравнения ax^2+bx+c=0: 0" << endl;
                }
                else {
                    cout << "Решение уравнения ax^2+bx+c=0: " << ((-1) * c / b);
                }
            }
            else if ((b * b - 4 * a * c) >= 0) {
                x1 = ((-1) * b + sqrt(b * b - 4 * a * c)) / (2 * a);
                x2 = ((-1) * b - sqrt(b * b - 4 * a * c)) / (2 * a);
                if (x1 == x2) {
                    cout << "Решение уравнения ax^2+bx+c=0: " << x1 << endl;
                }
                else {
                    cout << "Решения уравнения ax^2+bx+c=0: " << x1 << " " << x2 << endl;
                }
            }
            else {
                cout << "Уравнение ax^2+bx+c=0  иррационально" << endl;
            }
        }
        else {
            cout << "Введены не числа" << endl;
        }
    }
    else if (i == 5) {
        bool d, k, g, f = true;
        cout << "Если ответ да, то введите 1, иначе введите 0" << endl;
        cout << "На улице день?: ";
        cin >> d;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Раздвинуты ли шторы?: ";
        cin >> k;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Включена ли лампа?: ";
        cin >> g;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        if (f = true) {
            if ((g == 1) or ((d == 1) and (k == 1))) {
                cout << "В комнате светло" << endl;
            }
            else {
                cout << "В комнате темно" << endl;
            }
        }
        else {
            cout << "Ошибка ввода данных" << endl;
        }
    }
}