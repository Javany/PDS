#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

// Функція для перевірки, чи можна поставити ферзя в поточну клітинку (row, col)
bool isSafe(int row, int col, const vector<int>& board) {
    // Перевірка вертикалі
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Функція для розміщення ферзів
void solveNQueens(int n, int row, vector<int>& board, vector<vector<int>>& solutions) {
    // Якщо всі ферзі розставлені, додаємо рішення в список
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    // Перебираємо всі стовпці для поточного рядка
    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board)) {
            board[row] = col;  // Розміщаємо ферзя
            solveNQueens(n, row + 1, board, solutions);  // Пробуємо наступний рядок
            board[row] = -1;  // Повертаємось назад
        }
    }
}

// Функція для виведення розв'язків
void printSolutions(const vector<vector<int>>& solutions) {
    for (const auto& solution : solutions) {
        for (int col : solution) {
            for (int i = 0; i < solution.size(); ++i) {
                if (i == col) {
                    cout << "Q ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть розмір шахівниці (n): ";
    cin >> n;

    // Якщо n = 2 або n = 3, то розв'язку немає
    if (n == 2 || n == 3) {
        cout << "Розв'язку для n = " << n << " немає!" << endl;
        return 0;
    }

    vector<int> board(n, -1);  // Вектор для зберігання позицій ферзів на шахівниці
    vector<vector<int>> solutions;  // Вектор для зберігання всіх розв'язків

    solveNQueens(n, 0, board, solutions);  // Запуск пошуку рішень

    if (solutions.empty()) {
        cout << "Розв'язку немає!" << endl;
    }
    else {
        cout << "Знайдено " << solutions.size() << " розв'язків:" << endl;
        printSolutions(solutions);  // Виведення всіх знайдених розв'язків
    }

    return 0;
}
