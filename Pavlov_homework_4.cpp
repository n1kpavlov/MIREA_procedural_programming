#include <Windows.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
using Matrix = vector<vector<double>>;

int sign(int x)
{
    if (x > 0) {
        return 1;
    }
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return -1;
    }
}

double rectangle(double a, double b)
{
    if ((a > 0) and (b > 0)) {
        return (a * b);
    }
    else {
        cout << "Ошибка. Отрицательные стороны" << endl;
        return 0;
    }
}

double triangle(double a, double b, double c)
{
    double p;
    if ((a > 0) and (b > 0) and (c > 0)) {
        if ((a + b > c) and (b + c > a) and (a + c > b)) {
            p = (a + b + c) / 2;
            return (sqrt(p * (p - a) * (p - b) * (p - c)));
        }
        else {
            cout << "Ошибка. Такой треугольник не существует" << endl;
            return 0;
        }
    }
    else {
        cout << "Ошибка. Отрицательные стороны" << endl;
        return 0;
    }
}

double circle(double r)
{
    if (r > 0) {
        return (M_PI * pow(r, 2));
    }
    else {
        cout << "Ошибка. Отрицательный радиус" << endl;
        return 0;
    }
}

string ToRoman(int x) {
    string m[3001];
    m[1] = "I";
    m[2] = "II";
    m[3] = "III";
    m[4] = "IV";
    m[5] = "V";
    m[6] = "VI";
    m[7] = "VII";
    m[8] = "VIII";
    m[9] = "IX";
    m[10] = "X";
    m[20] = "XX";
    m[30] = "XXX";
    m[40] = "XL";
    m[50] = "L";
    m[60] = "LX";
    m[70] = "LXX";
    m[80] = "LXXX";
    m[90] = "XC";
    m[100] = "C";
    m[200] = "CC";
    m[300] = "CCC";
    m[400] = "CD";
    m[500] = "D";
    m[600] = "DC";
    m[700] = "DCC";
    m[800] = "DCCC";
    m[900] = "CM";
    m[1000] = "M";
    m[2000] = "MM";
    m[3000] = "MMM";
    string ans = "";
    int d = 1;
    while (x > 0) {
        d = d * 10;
        int k = x % (d);
        ans = m[k] + ans;
        x = x - k;
    }
    return ans;
}

string from_dec(int x, int n)
{
    string res;
    if (n < 2 or n > 36) {
        cout << "Неправильная система счисления!";
        exit(0);
    }
    while (x != 0) {
        int k = (x % n);
        char c;
        if (0 <= k and k <= 9) {
            c = char(k + '0');
        }
        else if (10 <= k <= 36) {
            c = char(k - 10 + 'A');
        }
        res = c + res;
        x = x / n;
    }
    return res;
}

int to_dec(string x, int n)
{
    int res = 0;
    if (n < 2 or n > 36) {
        cout << "Неправильная система счисления!";
        exit(0);
    }
    for (auto c : x) {
        int k;
        if ('0' <= c and c <= '9') {
            k = int(c - '0');
        }
        else if ('A' <= c and c <= 'Z') {
            k = int(c + 10 - 'A');
        }
        else {
            cout << "Неправильный формат числа!";
            exit(0);
        }
        if (k >= n) {
            cout << "Неправильный формат числа!";
            exit(0);
        }
        res = (res * n) + k;
    }
    return res;
}

string from_x_to_y(string s, int x, int y)
{
    return from_dec(to_dec(s, x), y);
}

Matrix multiply_matrix(Matrix A, Matrix B)
{
    Matrix C(A.size());
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            C[i].resize(B[0].size());
            double cur_el = 0;
            for (int k = 0; k < B.size(); k++) {
                cur_el += A[i][k] * B[k][j];
            }
            C[i][j] = cur_el;
        }
    }
    return C;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int i;
    cout << "Введите № задания: ";
    cin >> i;
    if (i == 1) {
        string s;
        double x, k = 0, summ = 0;
        ofstream fout("copy4.txt");
        cout << "Введите 10 чисел (через пробел)" << endl;
        cin.ignore();
        getline(cin, s);
        fout << s << endl;
        fout.close();
        cout << "Файл записан" << endl;
        s.clear();
        ifstream fin("copy4.txt");
        if (fin.is_open()) {
            do {
                if (fin >> x) {
                    summ += x;
                    k++;
                }
                else {
                    fin.clear();
                    fin.ignore();
                }
            } while (!fin.eof());
            if (k == 10) {
                cout << "Сумма чисел в файле:" << summ << endl;
            }
            else {
                cout << "Ошибка. Введено не 10 чисел" << endl;
            }
        }
        else {
            cout << "Файл не найден" << endl;
        }
        fin.close();
    }
    else if (i == 2) {
        int x;
        cout << "Введите число: ";
        cin >> x;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Ошибка ввода. Введите число: ";
            cin >> x;
        }
        cout << "Знак введенного числа: " << sign(x) << endl;
    }
    else if (i == 3) {
        int x;
        double a, b, c, r;
        cout << "Выберете фигуру (1-прямоугольник, 2-треугольник, 3-круг): ";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "1 сторона прямоугольника: ";
            cin >> a;
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Ошибка ввода. Введите число: ";
                cin >> a;
            }
            cout << "2 сторона прямоугольника: ";
            cin >> b;
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Ошибка ввода. Введите число: ";
                cin >> b;
            }
            if (rectangle(a, b) != 0) {
                cout << "Площадь прямоугольника: " << rectangle(a, b) << endl;
            }
            break;
        case 2:
            cout << "1 сторона треугольника: ";
            cin >> a;
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Ошибка ввода. Введите число: ";
                cin >> a;
            }
            cout << "2 сторона треугольника: ";
            cin >> b;
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Ошибка ввода. Введите число: ";
                cin >> b;
            }
            cout << "3 сторона треугольника: ";
            cin >> c;
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Ошибка ввода. Введите число: ";
                cin >> c;
            }
            if (triangle(a, b, c) != 0) {
                cout << "Площадь треугольника: " << triangle(a, b, c) << endl;
            }
            break;
        case 3:
            cout << "Радиус окружности: ";
            cin >> r;
            while (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "Ошибка ввода. Введите число: ";
                cin >> r;
            }
            if (circle(r) != 0) {
                cout << "Площадь круга: " << circle(r) << endl;
            }
            break;
        default:
            cout << "Ошибка ввода" << endl;
            break;
        }
    }
    else if (i == 4) {
        HANDLE h;
        h = GetStdHandle(STD_OUTPUT_HANDLE);
        for (int j = 1; j <= 13; j++) {
            if (j <= 7) {
                SetConsoleTextAttribute(h, ((1 << 4) | 15));
                for (int k = 1; k <= 8; k++) {
                    if (j == 7) {
                        cout << "  ";
                    }
                    else {
                        cout << "* ";
                    }
                }
                if ((j % 2) == 1) {
                    SetConsoleTextAttribute(h, ((4 << 4) | 4));
                }
                else {
                    SetConsoleTextAttribute(h, ((15 << 4) | 15));
                }
                for (int k = 1; k <= 25; k++) {
                    cout << "_";
                }
                cout << endl;
            }
            else {
                if ((j % 2) == 1) {
                    SetConsoleTextAttribute(h, ((4 << 4) | 4));
                }
                else {
                    SetConsoleTextAttribute(h, ((15 << 4) | 15));
                }
                for (int k = 1; k <= 41; k++) {
                    cout << "_";
                }
                cout << endl;
            }
        }
        SetConsoleTextAttribute(h, ((0 << 4) | 15));
    }
    else if (i == 5) {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        HWND hWnd = GetConsoleWindow();
        HDC hDC = GetDC(hWnd);
        HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
        SelectObject(hDC, Pen);
        MoveToEx(hDC, 0, 85, NULL);
        LineTo(hDC, 200, 85);
        MoveToEx(hDC, 100, 0, NULL);
        LineTo(hDC, 100, 170);
        for (float x = -8.0f; x <= 8.0f; x += 0.01f) {
            MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 85, NULL);
            LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
        }
        ReleaseDC(hWnd, hDC);
        cin.get();
    }
    else if (i == 6) {
        string s, s1;
        int x, j, xn;
        bool f = true;
        cout << "Введите число в римской сс: ";
        cin.ignore();
        getline(cin, s);
        x = 0;
        j = 0;
        while ((j <= s.size() - 1) and (f == true)) {
            switch (s[j])
            {
            case 'I':
                if (s[j + 1] == 'V') {
                    x += 4;
                    j += 2;
                }
                else if (s[j + 1] == 'X') {
                    x += 9;
                    j += 2;
                }
                else {
                    x++;
                    j++;
                }
                break;
            case 'V':
                x += 5;
                j++;
                break;
            case 'X':
                if (s[j + 1] == 'L') {
                    x += 40;
                    j += 2;
                }
                else if (s[j + 1] == 'C') {
                    x += 90;
                    j += 2;
                }
                else {
                    x += 10;
                    j++;
                }
                break;
            case 'L':
                x += 50;
                j++;
                break;
            case 'C':
                if (s[j + 1] == 'D') {
                    x += 400;
                    j += 2;
                }
                else if (s[j + 1] == 'M') {
                    x += 900;
                    j += 2;
                }
                else {
                    x += 100;
                    j++;
                }
                break;
            case 'D':
                x += 500;
                j++;
                break;
            case 'M':
                x += 1000;
                j++;
                break;
            default:
                f = false;
                break;
            }
        }
        xn = x;
        if (x < 4000) {
            s1 = ToRoman(x);
        }
        else {
            f = false;
        }
        if ((s == s1) and (f == true)) {
            cout << "Число в арабской сс: " << xn << endl;
        }
        else {
            cout << "Несуществующее число" << endl;
        }
    }
    else if (i == 7) {
        long int s[101];
        long int m = 37, b = 3, c = 64;
        //m = 25173; b = 13849; c = 65537;
        s[0] = 0;
        for (int i = 0; i < 100; i++) {
            s[i + 1] = (s[i] * m + b) % c;
        }
        for (int i = 0; i < 101; i++) {
            cout << s[i] << endl;
        }
    }
    else if (i == 8) {
        Matrix A{
            { 5, 2, 0, 10},
            { 3, 5, 2, 5},
            {20, 0, 0, 0}
        };
        Matrix B{
            {1.20, 0.50},
            {2.80, 0.40},
            {5.00, 1.00},
            {2.00, 1.50}
        };
        Matrix C = multiply_matrix(A, B);

        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[0].size(); j++) {
                cout << C[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        double total_com = 0;
        double total_v = 0;
        double max_com = -100000000;
        double max_v = -100000000;
        double min_com = 100000000000000000;
        double min_v = 100000000000000000;
        double ans1_1;
        double ans1_2;
        double ans2_1;
        double ans2_2;
        for (int j = 0; j < 3; j++)
        {
            double current_v = C[j][0];
            double current_com = C[j][1];
            total_com += current_com;
            total_v += current_v;
            if (current_v > max_v)
            {
                max_v = current_v;
                ans1_1 = j + 1;
            }
            if (current_v < min_v)
            {
                min_v = current_v;
                ans1_2 = j + 1;
            }
            if (current_com > max_com)
            {
                max_com = current_com;
                ans2_1 = j + 1;
            }
            if (current_com < min_com)
            {
                min_com = current_com;
                ans2_2 = j + 1;
            }
        }
        cout << "1) " << ans1_1 << " " << ans1_2 << endl;
        cout << "2) " << ans2_1 << " " << ans2_2 << endl;
        cout << "3) " << total_v << endl;
        cout << "4) " << total_com << endl;
        cout << "5) " << total_v + total_com << endl;
    }
    else if (i == 9) {
        string x1;
        int n1, n2;
        cout << "Введите число: ";
        cin >> x1;
        cout << "Введите исходную систему счисления: ";
        cin >> n1;
        cout << "Введите целевую систему счисления: ";
        cin >> n2;
        cout << from_x_to_y(x1, n1, n2);
    }
}
