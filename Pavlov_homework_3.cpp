#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int partition(char a[], int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for (int j = start; j < end; j++) {
        if (a[j] <= pivot) {
            swap(a[j], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}

void quicksort(char a[], int start, int end)
{
    if (start >= end) {
        return;
    }
    int pivot = partition(a, start, end);
    quicksort(a, start, pivot - 1);
    quicksort(a, pivot + 1, end);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int i;
    double S, n, p, r, m;
    cout << "Введите № задания: ";
    cin >> i;
    if (i == 1) {
        bool f = true;
        cout << "Введите S: ";
        cin >> S;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Введите p: ";
        cin >> p;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Введите n: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        if (f == true) {
            if ((S > 0) and (p != 0) and (n > 0) and (n < 100)) {
                r = (p / 100);
                cout << "Ответ: " << (round(((S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1))) * 100) / 100) << endl;
            }
            else if ((S > 0) and (p == 0) and (n > 0) and (n < 100)) {
                cout << "Ответ: " << (S / (n * 12)) << endl;
            }
            else {
                cout << "Ошибка. Числа вне диапазона" << endl;
            }
        }
        else {
            cout << "Введены не числа" << endl;
        }
    }
    if (i == 2) {
        bool f = true;
        cout << "Введите S: ";
        cin >> S;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Введите m: ";
        cin >> m;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        cout << "Введите n: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            f = false;
        }
        if (f == true) {
            if ((S > 0) and (m > 0) and (n > 0) and (n < 100)) {
                for (r = 0.01; r < 1; r = (r + 0.01)) {
                    if ((round(((S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1))) * 100) / 100) == m) {
                        cout << "Ответ: " << (r * 100) << "%" << endl;
                        break;
                    }
                }
            }
            else {
                cout << "Ошибка. Числа вне диапазона" << endl;
            }
        }
        else {
            cout << "Введены не числа" << endl;
        }
    }
    if (i == 3) {
        string s;
        ofstream fout("copy3.txt");
        cout << "Введите строку для записи: ";
        cin.ignore();
        getline(cin, s);
        fout << s << endl;
        fout.close();
        cout << "Файл записан." << endl;
        s.clear();
        ifstream fin("copy3.txt");
        if (fin.is_open()) {
            getline(fin, s);
            cout << "Прочтено из файла: " << s << endl;
        }
        else {
            cout << "Файл не найден" << endl;
        }
        fin.close();
    }
    if (i == 4) {
        ifstream fin("copy3.txt");
        if (fin.is_open()) {
            int c;
            do {
                if (fin >> c) {
                    cout << c << " ";
                }
                else {
                    fin.clear();
                    fin.ignore();
                }
            } while (!fin.eof());
        }
        else {
            cout << "Файл не найден" << endl;
        }
        fin.close();
    }
    if (i == 5) {
        const int n = 30;
        char a[n];
        string s;
        cin.ignore();
        getline(cin, s);
        if (s.size() == n) {
            for (int j = 0; j < n; j++) {
                a[j] = s[j];
            }
            quicksort(a, 0, n - 1);
            for (int j = 0; j < n; j++) {
                cout << a[j] << "";
            }
        }
        else {
            cout << "Несоответсвие длине строки" << endl;
        }
    }
}
