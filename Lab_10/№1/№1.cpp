#include <Windows.h>
#undef max
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip> // Для std::setw() та std::left

using namespace std;

// Константа для позначення відсутності ребра
const int INF = numeric_limits<int>::max();

void loadGraph(const string& filename, vector<vector<int>>& matrix, int& n) {
    ifstream infile(filename);
    int m, u, v, w;
    infile >> n >> m;

    // Ініціалізація матриці ваг INF
    matrix.assign(n, vector<int>(n, INF));

    // Зчитування ребер
    for (int i = 0; i < m; ++i) {
        infile >> u >> v >> w;
        matrix[u][v] = w;  // Орієнтований граф
    }
    infile.close();
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF)
                cout << setw(6) << left << "INF"; // Вирівняння значення INF
            else
                cout << setw(6) << left << matrix[i][j]; // Вирівняння чисел
        }
        cout << endl;
    }
}

void saveMatrix(const string& filename, const vector<vector<int>>& matrix) {
    ofstream outfile(filename);
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF)
                outfile << "INF ";
            else
                outfile << matrix[i][j] << " ";
        }
        outfile << endl;
    }
    outfile.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputFilename = "graph.txt";
    string outputFilename = "matrix.txt";
    int n;
    vector<vector<int>> matrix;

    // Завантаження графа з файлу
    loadGraph(inputFilename, matrix, n);

    // Виведення матриці ваг на екран
    cout << "Матриця ваг:" << endl;
    printMatrix(matrix);

    // Збереження матриці ваг у файл
    saveMatrix(outputFilename, matrix);

    return 0;
}
