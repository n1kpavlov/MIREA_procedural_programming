#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <string>
#include <stack>

using namespace std;

long long test()
{
    long long x;
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка. Введите число: ";
        cin >> x;
    }
    return x;
}

long long test1()
{
    long long x;
    cin >> x;
    while ((cin.fail()) or (x <= 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода, повторите попытку: ";
        cin >> x;
    }
    return x;
}

void inverse(long long* a, int n)
{
    long long x;
    for (int i = 1; i <= (n / 2); i++) {
        x = *(a + i - 1);
        *(a + i - 1) = *(a + n - i);
        *(a + n - i) = x;
    }
}

void output(int** a, int n, int m)
{
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(10) << a[i][j] << " ";
        }
        cout << endl;
    }
}

void generate(int open, int close, string s) {
    if ((open == 0) and (close == 0)) {
        cout << s << endl;
        return;
    }
    if (open > 0) {
        generate(open - 1, close, s + "(");
    }
    if (close > open) {
        generate(open, close - 1, s + ")");
    }
}

void simple_arr_33()
{
    const int a = 10;
    long long arr[a];
    for (int i = 0; i < a; i++) {
        cout << "Введите " << i + 1 << " число: ";
        arr[i] = test();
    }
    bool f = false;
    for (int i = 1; i < a - 1; i++) {
        if ((arr[i] > arr[0]) and (arr[i] < arr[9])) {
            f = true;
            cout << i + 1 << endl;
            break;
        }
    }
    if (f == false) {
        cout << 0 << endl;
    }
}

void sort_43()
{
    int n;
    cout << "Введите колличество элементов: ";
    n = test1();
    long long *a = new long long[n] {0};
    for (int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << " элемент: ";
        *(a + i) = test();
    }
    inverse(a, n);
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
    delete[] a;
}

void arr_56()
{
    int n;
    cout << "Введите колличество элементов: ";
    n = test1();
    long long* a = new long long[n];
    for (int i = 0; i < n; i++) {
        cout << "Введите " << i + 1 << " элемент: ";
        a[i] = test();
    }
    long long** matrix = new long long* [n];
    for (int j = 0; j < n; j++) {
        matrix[j] = new long long[n];
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            matrix[j][k] = *(a + j) - *(a + k) * 3;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cout << matrix[j][k] << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < n; j++) {
        delete[] matrix[j];
    }
    delete[] matrix;
    delete[] a;
}

void function_66()
{
    int n = 2, m = 5;
    int** matrix_A = new int* [n];
    int** matrix_B = new int* [n];
    int** matrix_C = new int* [n];
    int** matrix_D = new int* [n];
    int** matrix_E = new int* [n];
    for (int j = 0; j < n; j++) {
        matrix_A[j] = new int[m];
        matrix_B[j] = new int[m];
        matrix_C[j] = new int[m];
        matrix_D[j] = new int[m];
        matrix_E[j] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        cout << "Введите значения " << (i + 1) << " строки:" << endl;
        for (int j = 0; j < m; j++) {
            cout << (j + 1) << " элемент: ";
            matrix_A[i][j] = test();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_B[i][j] = (i + 1) * (j + 1) - (5 - i - j - 2);
        }
    }
    srand(time(0));
    int end = 6, start = -3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_C[i][j] = rand() % (end - start + 1) + start;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_E[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_D[i][j] = 6*matrix_E[i][j]-matrix_C[i][j]-2*matrix_B[i][j]-3*matrix_A[i][j];
        }
    }

    output(matrix_A, n, m);
    output(matrix_B, n, m);
    output(matrix_C, n, m);
    output(matrix_D, n, m);
    output(matrix_E, n, m);
    for (int j = 0; j < n; j++) {
        delete[] matrix_A[j];
        delete[] matrix_B[j];
        delete[] matrix_C[j];
        delete[] matrix_D[j];
        delete[] matrix_E[j];
    }
    delete[] matrix_A;
    delete[] matrix_B;
    delete[] matrix_C;
    delete[] matrix_D;
    delete[] matrix_E;
}

void generate_87()
{
    const int n = 10;
    generate(n / 2, n / 2, "");
}
 
int main()
{
    setlocale(LC_ALL, "rus");
    int i;
    cout << "Выберите номер задания (1, 2, 3, 4, 5, 0 - заверение работы): ";
    i = test();
    while (i != 0) {
        switch (i)
        {
        case 1:
            simple_arr_33();
            break;
        case 2:
            sort_43();
            break;
        case 3:
            arr_56();
            break;
        case 4:
            function_66();
            break;
        case 5:
            generate_87();
            break;
        default:
            cout << "Некорректный ввод" << endl;
            break;
        }
        cout << "Выберите номер задания (1, 2, 3, 4, 5, 0 - заверение работы): ";
        i = test();
    }
}