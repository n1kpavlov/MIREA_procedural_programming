#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

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

long long nod1(long long a, long long b)
{
    if (a % b == 0) {
        return b;
    }
    else {
        return nod1(b, a % b);
    }
}

long long nod2(long long a, long long b)
{
    if (a - b == 0) {
        return b;
    }
    else {
        while (a > b) {
            a -= b;
        }
        return nod2(max(a, b), min(a, b));
    }
}

void mark_primes(bool* a, int n)
{
    int j, m = 2;
    while (m < n) {
        if (a[m] != 0) {
            j = m * 2;
            while (j < n) {
                a[j] = 0;
                j += m;
            }
        }
        m++;
    }
}

int char_to_int(char c)
{
    switch (c)
    {
    case 'a':
        return 0;
        break;
    case 'A':
        return 0;
        break;
    case 'e':
        return 1;
        break;
    case 'E':
        return 1;
        break;
    case 'y':
        return 2;
        break;
    case 'Y':
        return 2;
        break;
    case 'u':
        return 3;
        break;
    case 'U':
        return 3;
        break;
    case 'i':
        return 4;
        break;
    case 'I':
        return 4;
        break;
    case 'o':
        return 5;
        break;
    case 'O':
        return 5;
        break;
    default:
        return 6;
        break;
    }
}

char int_to_char(int x)
{
    switch (x)
    {
    case 0:
        return 'a';
        break;
    case 1:
        return 'e';
        break;
    case 2:
        return 'y';
        break;
    case 3:
        return 'u';
        break;
    case 4:
        return 'i';
        break;
    case 5:
        return 'o';
        break;
    }
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

string reverse(string const &s)
{
    string rev;
    for (int i = s.size() - 1; i >= 0; i--) {
        rev = rev.append(1, s[i]);
    }
    return rev;
}

string number_phone(string s)
{
    int i = s.size();
    string num = "";
    while ((s[i - 1] >= '0') and (s[i - 1] <= '9')) {
        num = num.append(1, s[i - 1]);
        i--;
    }
    num = reverse(num);
    return num;
}

long long string_to_long(string s)
{
    long long x = 0;
    for (int k = 0; k < s.size(); k++) {
        x += ((int)s[k] - '0') * pow(10, s.size() - k - 1);
    }
    return x;
}

void number_1()
{
    long long a, b;
    cout << "Введите 1 число: ";
    a = test();
    cout << "Введите 2 число: ";
    b = test();
    a = abs(a);
    b = abs(b);
    if ((a == 0) or (b == 0)) {
        if ((a == 0) and (b == 0)) {
            cout << "НОД: inf" << endl;
        }
        else {
            cout << "НОД: " << max(a, b) << endl;
        }
    }
    else {
        cout << "НОД (делением): " << nod1(max(a, b), min(a, b)) << endl;
        cout << "НОД (вычитанием): " << nod2(max(a, b), min(a, b)) << endl;
    }
}

void number_2()
{
    int n;
    cout << "Введите число: ";
    n = test();
    if (n <= 2) {
        cout << "Нет простых чисел до введенного числа" << endl;
    }
    else if (n<1000000){
        cout << "Простые числа, до введенного числа: ";
        bool* a = new bool[n];
        for (int i = 2; i < n; i++) {
            *(a + i) = 1;
        }
        *(a + 1) = 0;
        int j, m = 2;
        while (m < n) {
            if (*(a + m) != 0) {
                j = m * 2;
                while (j < n) {
                    *(a + j) = 0;
                    j += m;
                }
            }
            m++;
        }
        for (int i = 2; i < n; i++) {
            if (*(a + i) == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
        delete[] a;
    }
    else {
        cout << "Ошибка" << endl;
    }
}

void number_3_20()
{
    ifstream fin("input.txt");
    if (fin.is_open()) {
        const int sz = 256;
        int arr[sz] = { 0 };
        char c;
        int min;
        do {
            fin >> c;
            arr[(int)c]++;
            min = (int)c;
        } while (!fin.eof());
        for (int j = 0; j <= 255; j++) {
            if (arr[j] > 0) {
                cout << (char)j << " " << arr[j] << endl;
            }
        }
        for (int j = 0; j <= 255; j++) {
            if ((arr[j] > 0) and (arr[j] < arr[min])) {
                min = j;
            }
        }
        cout << "Наименее часто встречающиеся символы:";
        for (int j = 0; j <= 255; j++) {
            if (arr[j] == arr[min]) {
                c = (char)j;
                cout << " " << c;
            }
        }
        cout << endl;
    }
    else {
        cout << "Файл не найден" << endl;
    }
    fin.close();
}

void number_3_21()
{
    ifstream fin("input.txt");
    if (fin.is_open()) {
        const int sz = 6;
        int arr[sz] = { 0 };
        char c;
        int max, x;
        do {
            fin >> c;
            x = char_to_int(c);
            if (x < 6) {
                arr[x]++;
                max = x;
            }
        } while (!fin.eof());
        for (int j = 0; j <= 5; j++) {
            if (arr[j] > 0) {
                c = int_to_char(j);
                cout << c << " " << arr[j] << endl;
            }
        }
        for (int j = 0; j <= 5; j++) {
            if ((arr[j] > 0) and (arr[j] > arr[max])) {
                max = j;
            }
        }
        cout << "Наиболее часто встречающиеся гласные:";
        for (int j = 0; j <= 5; j++) {
            if (arr[j] == arr[max]) {
                c = int_to_char(j);
                cout << " " << c;
            }
        }
        cout << endl;
    }
    else {
        cout << "Файл не найден" << endl;
    }
    fin.close();
}

void number_4_20()
{
    ifstream fin("input2.txt");
    if (fin.is_open()) {
        int n, x;
        fin >> n;
        string* arr2 = new string[n];
        string* arr4 = new string[n];
        for (int j = 0; j < n; j++) {
            fin >> *(arr2 + j);
            cout << *(arr2 + j) << endl;
        }
        for (int j = 0; j < n; j++) {
            *(arr4 + j) = from_x_to_y(*(arr2 + j), 2, 4);
            cout << *(arr4 + j) << endl;
        }
        delete[] arr2;
        delete[] arr4;
    }
    else {
        cout << "Файл не найден" << endl;
    }
    fin.close();
}

void number_4_49()
{
    int n;
    cout << "Введите размерность квадратной матрицы: ";
    n = test1();
    double** matrix = new double* [n];
    for (int j = 0; j < n; j++) {
        matrix[j] = new double[n];
    }
    for (int j = 0; j < n; j++) {
        cout << "Введите значения " << (j + 1) << " строки:" << endl;
        for (int k = 0; k < n; k++) {
            cout << (k + 1) << " элемент: ";
            matrix[j][k] = test();
        }
    }
    double* summ = new double[n + n + 2] {0};
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            *(summ + j) += matrix[j][k];
            *(summ + n + j) += matrix[k][j];
        }
        *(summ + n + n) += matrix[j][j];
        *(summ + n + n + 1) += matrix[n - j - 1][j];
    }
    bool f = true;
    for (int j = 0; j < (n + n); j++) {
        if (*(summ + j) != *(summ + j + 1)) {
            f = false;
        }
    }
    if (f == true) {
        cout << "Матрица является магическим квадратом" << endl;
    }
    else {
        cout << "Матрица не является магическим квадратом" << endl;
    }
    for (int j = 0; j < n; j++) {
        delete[] matrix[j];
    }
    delete[] matrix;
    delete[] summ;
}

void number_5_20()
{
    ofstream fout("phone.txt");
    int n;
    string s;
    long long x;
    cout << "Введите колличество контактов: ";
    n = test();
    for (int j = 0; j < n; j++) {
        cout << "Введите фамилию " << (j + 1) << " абонента: ";
        cin.ignore();
        cin >> s;
        cout << "Введите номер " << (j + 1) << " абонента: ";
        x = test();
        s += " - " + to_string(x);
        fout << s << endl;
    }
    fout.close();
    ifstream fin("phone.txt");
    ofstream fout2("output.txt");
    if (fin.is_open()) {
        int c = 0;
        long long x;
        string* full = new string[n]{ "" };
        long long* phone = new long long[n] {0};
        for (int j = 0; j < n; j++) {
            getline(fin, s);
            string num;
            num = number_phone(s);
            bool f = true;
            for (int k = 0; k < num.size(); k++) {
                if ((int)num[k] % 2 != 0) {
                    f = false;
                }
            }
            if (f == true) {
                *(full + j) = s;
                *(phone + j) = string_to_long(num);
                c++;
            }
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n - j; k++) {
                if (*(phone + k) > *(phone + k + 1)) {
                    x = *(phone + k);
                    *(phone + k) = *(phone + k + 1);
                    *(phone + k + 1) = x;
                    s = *(full + k);
                    *(full + k) = *(full + k + 1);
                    *(full + k + 1) = s;
                }
            }
        }
        for (int j = n - c; j < n; j++) {
            fout2 << *(full + j) << endl;
        }
        delete[] full;
        delete[] phone;
    }
    else {
        cout << "Файл не найден" << endl;
    }
    fin.close();
    fout2.close();
}

void number_5_52()
{
    int n;
    cout << "Введите размерность квадратной матрицы: ";
    n = test1();
    double** matrix = new double* [n];
    for (int j = 0; j < n; j++) {
        matrix[j] = new double[n];
    }
    for (int j = 0; j < n; j++) {
        cout << "Введите значения " << (j + 1) << " строки:" << endl;
        for (int k = 0; k < n; k++) {
            cout << (k + 1) << " элемент: ";
            matrix[j][k] = test();
        }
    }
    int summ = 0;
    for (int j = 0; j < n; j++) {
        summ += matrix[j][j];
        summ += matrix[n - j - 1][j];
    }
    if ((n % 2 != 0) and (n > 1)) {
        summ -= matrix[(n - 1) / 2][(n - 1) / 2];
    }
    else if (n == 1) {
        summ -= 1;
    }
    cout << "Сумма чисел на диагоналях: " << summ << endl;
    for (int j = 0; j < n; j++) {
        delete[] matrix[j];
    }
    delete[] matrix;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int i;
    cout << "Выберите номер задания (1, 2, 31, 32, 41, 42, 51, 52, 0 - заверение работы): ";
    i = test();
    while (i != 0) {
        switch (i)
        {
        case 1: 
            number_1();
            break;
        case 2:
            number_2();
            break;
        case 31:
            number_3_20();
            break;
        case 32:
            number_3_21();
            break;
        case 41:
            number_4_20();
            break;
        case 42:
            number_4_49();
            break;
        case 51:
            number_5_20();
            break;
        case 52:
            number_5_52();
            break;
        default:
            cout << "Некорректный ввод" << endl;
            break;
        }
        cout << "Выберите номер задания (1, 2, 31, 32, 41, 42, 51, 52, 0 - заверение работы): ";
        i = test();
    }
}