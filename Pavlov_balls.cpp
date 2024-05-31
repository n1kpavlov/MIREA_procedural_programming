#include <iostream>

using namespace std;

int test()
{
    int x;
    cin >> x;
    while ((cin.fail()) or (x <= 0) or (x >= 12)) {
        cin.clear();
        cin.ignore();
        cout << "Ошибка. Введите положительное целое число (меньше 12): ";
        cin >> x;
    }
    return x;
}

int generate(int t, int n, int *a, int x)
{
    if (t == n - 1) {
        bool f = false;
        for (int j = 1; j <= n; j++) {
            if (*(a + j - 1) == j) {
                f = true;;
            }
        }
        if (f) {
            x++;
        }
    }
    else {
        for (int j = t; j < n; j++) {
            swap(*(a + t), *(a + j));
            t++;
            x = generate(t, n, a, x);
            t--;
            swap(*(a + t), *(a + j));
        }
    }
    return x;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n, summ = 0;
    cout << "Введите количество шариков: ";
    n = test();
    int* arr = new int[n];
    for (int i = 1; i <= n; i++) {
        *(arr + i - 1) = i;
    }
    for (int i = 1; i <= n; i++) {
        summ = generate(1, n, arr, summ);
        int y = *(arr);
        for (int j = 1; j <= n; j++) {
            *(arr + j - 1) = *(arr + j);
        }
        *(arr + n - 1) = y;
    }
    cout << "Ответ: " << summ << endl;
    
    cout << "Проверка: ";
    long long* count = new long long[n] {0};
    *(count) = 1;
    *(count + 1) = 1;
    for (int j = 2; j < n; j++) {
        *(count + j) = (*(count + j - 2) + *(count + j - 1)) * j;
    }
    cout << *(count + n - 1) << " ";
    delete[] count;
    delete[] arr;
}