#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

// Функція для обчислення чисел Стірлінга другого роду
void computeStirlingNumbers(int n, vector<vector<long long>>& stirling) {
    // Ініціалізуємо таблицю чисел Стірлінга другого роду
    for (int j = 1; j <= n; ++j) {
        stirling[j][1] = 1; // перший стовпчик: S(j, 1) = 1
        stirling[j][j] = 1; // головна діагональ: S(j, j) = 1
    }

    // Обчислюємо решту значень чисел Стірлінга другого роду
    for (int j = 3; j <= n; ++j) {
        for (int k = 2; k < j; ++k) {
            stirling[j][k] = stirling[j - 1][k - 1] + k * stirling[j - 1][k];
        }
    }
}

// Функція для обчислення чисел Белла
int computeBellNumbers(int n, vector<vector<long long>>& stirling, vector<long long>& bell) {
    // Ініціалізуємо числа Белла
    for (int j = 1; j <= n; ++j) {
        bell[j] = 0;
        // Обчислюємо число Белла як суму чисел Стірлінга другого роду
        for (int k = 1; k <= j; ++k) {
            bell[j] += stirling[j][k];
        }
    }
    return 0;
}

// Основна програма
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i; // Номер варіанту
    cout << "Введіть номер варіанту: ";
    cin >> i;

    // Обчислюємо n
    int n = i + 5;

    // Ініціалізуємо таблицю чисел Стірлінга другого роду (n x n)
    vector<vector<long long>> stirling(n + 1, vector<long long>(n + 1, 0));

    // Ініціалізуємо масив для чисел Белла
    vector<long long> bell(n + 1, 0);

    // Обчислюємо числа Стірлінга другого роду
    computeStirlingNumbers(n, stirling);

    // Обчислюємо числа Белла
    computeBellNumbers(n, stirling, bell);

    // Виводимо таблицю чисел Стірлінга другого роду
    cout << "\nТаблиця чисел Стірлінга другого роду для n = " << n << ":\n";
    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= j; ++k) {
            cout << stirling[j][k] << "\t";
        }
        cout << endl;
    }

    // Виводимо числа Белла
    cout << "\nЧисла Белла для n = " << n << ":\n";
    for (int j = 1; j <= n; ++j) {
        cout << "B(" << j << ") = " << bell[j] << endl;
    }

    return 0;
}
