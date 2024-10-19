#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Функція для виводу матриці в консоль і файл
void printMatrixToFileAndConsole(const vector<vector<int>>& matrix, const string& filename, const string& matrixName) {
    ofstream outFile(filename, ios::app); // Відкриваємо файл для дописування

    cout << matrixName << ":" << endl;
    outFile << matrixName << ":" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
            outFile << val << " ";
        }
        cout << endl;
        outFile << endl;
    }
    cout << endl;
    outFile << endl;
}

// Функція для створення та виведення матриці інцидентності
void createAndPrintIncidenceMatrix(int n, int m, const vector<pair<int, int>>& edges, const string& filename) {
    vector<vector<int>> incidenceMatrix(n, vector<int>(m, 0));

    for (int i = 0; i < m; ++i) {
        int v = edges[i].first - 1; // зменшуємо на 1 для індексації з 0
        int u = edges[i].second - 1;
        incidenceMatrix[v][i] = 1;  // початкова вершина
        incidenceMatrix[u][i] = -1; // кінцева вершина
    }

    printMatrixToFileAndConsole(incidenceMatrix, filename, "Incidence Matrix");
}

// Функція для створення та виведення матриці суміжності
void createAndPrintAdjacencyMatrix(int n, const vector<pair<int, int>>& edges, const string& filename) {
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    for (const auto& edge : edges) {
        int v = edge.first - 1; // зменшуємо на 1 для індексації з 0
        int u = edge.second - 1;
        adjacencyMatrix[v][u] = 1; // для орієнтованого графа
    }

    printMatrixToFileAndConsole(adjacencyMatrix, filename, "Adjacency Matrix");
}

int main() {
    // Зчитуємо вхідний файл з графом
    string inputFileName, outputFileName;
    cout << "Enter input file name: ";
    cin >> inputFileName;

    ifstream inFile(inputFileName);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n, m; // Кількість вершин і ребер
    inFile >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        inFile >> edges[i].first >> edges[i].second;
    }

    inFile.close();

    // Запитуємо у користувача, куди виводити матриці
    cout << "Enter output file name: ";
    cin >> outputFileName;

    // Створюємо та виводимо матриці інцидентності та суміжності
    createAndPrintIncidenceMatrix(n, m, edges, outputFileName);
    createAndPrintAdjacencyMatrix(n, edges, outputFileName);

    return 0;
}
