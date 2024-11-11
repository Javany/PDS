#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

bool readGraph(const string& filename, vector<pair<int, int>>& edges, int& n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return false;  // Повертаємо false, якщо файл не відкрився
    }

    int m; // Кількість ребер
    file >> n >> m;
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        file >> edges[i].first >> edges[i].second;
    }

    return true;  // Якщо зчитано без помилок
}

bool isIrreflexive(const vector<pair<int, int>>& edges) {
    for (const auto& edge : edges) {
        if (edge.first == edge.second) return false;  // Якщо є (v, v), то не іррефлексивне
    }
    return true;
}

bool isSymmetric(const vector<pair<int, int>>& edges) {
    set<pair<int, int>> edgeSet(edges.begin(), edges.end()); // Додаємо пари в множину без змін

    for (const auto& edge : edges) {
        pair<int, int> reverseEdge = { edge.second, edge.first };  // Обертаємо пару
        if (edgeSet.find(reverseEdge) == edgeSet.end()) {
            return false;  // Якщо немає оберненого ребра, то не симетричне
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename = "D:/University/ПДС/Lab_14/graph2.txt"; // Вкажіть шлях до вашого файлу
    vector<pair<int, int>> edges;
    int n;

    if (!readGraph(filename, edges, n)) return 1;  // Якщо файл не відкрився, зупиняємо

    cout << (isIrreflexive(edges) ? "Відношення є іррефлексивним." : "Відношення не є іррефлексивним.") << endl;
    cout << (isSymmetric(edges) ? "Відношення є симетричним." : "Відношення не є симетричним.") << endl;

    return 0;
}
