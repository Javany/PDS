#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Функція для зчитування графу з файлу
void readGraph(const string& filename, int& n, int& m, vector<pair<int, int>>& edges) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    inFile >> n >> m; // Читаємо кількість вершин та ребер
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        inFile >> edges[i].first >> edges[i].second;
    }

    inFile.close();
}

// Функція для обчислення напівстепенів виходу та заходу
void calculateDegrees(int n, const vector<pair<int, int>>& edges, vector<int>& outDegree, vector<int>& inDegree) {
    outDegree.assign(n, 0);
    inDegree.assign(n, 0);

    for (const auto& edge : edges) {
        int v = edge.first - 1; // Початкова вершина
        int u = edge.second - 1; // Кінцева вершина
        outDegree[v]++; // Збільшуємо напівстепінь виходу для вершини v
        inDegree[u]++;  // Збільшуємо напівстепінь заходу для вершини u
    }
}

// Функція для перевірки однорідності графа
bool isHomogeneous(const vector<int>& outDegree, const vector<int>& inDegree, int& degree) {
    degree = outDegree[0] + inDegree[0]; // Початкове значення для перевірки

    for (int i = 1; i < outDegree.size(); ++i) {
        if (outDegree[i] + inDegree[i] != degree) {
            return false;
        }
    }
    return true;
}

// Функція для виведення напівстепенів вершин
void printDegrees(const vector<int>& outDegree, const vector<int>& inDegree, const string& filename, bool toFile) {
    ofstream outFile;
    if (toFile) {
        outFile.open(filename, ios::app);
    }

    for (int i = 0; i < outDegree.size(); ++i) {
        string result = "Vertex " + to_string(i + 1) + ": Out-degree = " + to_string(outDegree[i]) + ", In-degree = " + to_string(inDegree[i]) + "\n";
        cout << result;
        if (toFile) {
            outFile << result;
        }
    }

    if (toFile) {
        outFile.close();
    }
}

// Функція для виведення висячих та ізольованих вершин
void printHangingAndIsolatedVertices(const vector<int>& outDegree, const vector<int>& inDegree, const string& filename, bool toFile) {
    ofstream outFile;
    if (toFile) {
        outFile.open(filename, ios::app);
    }

    string hangingVertices = "Hanging vertices: ";
    string isolatedVertices = "Isolated vertices: ";

    for (int i = 0; i < outDegree.size(); ++i) {
        if (outDegree[i] + inDegree[i] == 1) {
            hangingVertices += to_string(i + 1) + " ";
        }
        else if (outDegree[i] + inDegree[i] == 0) {
            isolatedVertices += to_string(i + 1) + " ";
        }
    }

    hangingVertices += "\n";
    isolatedVertices += "\n";

    cout << hangingVertices << isolatedVertices;
    if (toFile) {
        outFile << hangingVertices << isolatedVertices;
        outFile.close();
    }
}

int main() {
    string inputFileName, outputFileName;
    bool toFile;

    // Введення вхідного файлу
    cout << "Enter input file name: ";
    cin >> inputFileName;

    // Зчитуємо граф з файлу
    int n, m;
    vector<pair<int, int>> edges;
    readGraph(inputFileName, n, m, edges);

    // Обчислюємо напівстепені виходу та заходу
    vector<int> outDegree, inDegree;
    calculateDegrees(n, edges, outDegree, inDegree);

    // Запитуємо користувача, чи потрібно виводити результати у файл
    cout << "Do you want to output to file? (1 = yes, 0 = no): ";
    cin >> toFile;
    if (toFile) {
        cout << "Enter output file name: ";
        cin >> outputFileName;
    }

    // Виводимо напівстепені вершин
    printDegrees(outDegree, inDegree, outputFileName, toFile);

    // Перевірка, чи є граф однорідним
    int degree;
    if (isHomogeneous(outDegree, inDegree, degree)) {
        string result = "The graph is homogeneous with degree " + to_string(degree) + ".\n";
        cout << result;
        if (toFile) {
            ofstream outFile(outputFileName, ios::app);
            outFile << result;
            outFile.close();
        }
    }
    else {
        string result = "The graph is not homogeneous.\n";
        cout << result;
        if (toFile) {
            ofstream outFile(outputFileName, ios::app);
            outFile << result;
            outFile.close();
        }
    }

    // Виводимо висячі та ізольовані вершини
    printHangingAndIsolatedVertices(outDegree, inDegree, outputFileName, toFile);

    return 0;
}
