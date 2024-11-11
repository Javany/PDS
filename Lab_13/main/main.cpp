#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
#include <set>

using namespace std;

// Функція для зчитування графу з файлу
void readGraph(const string& filename, vector<vector<int>>& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    int n, m; // Кількість вершин і кількість ребер
    file >> n >> m;
    graph.resize(n);

    int u, v;
    for (int i = 0; i < m; ++i) {
        file >> u >> v;
        // Задаємо зв'язок між вершинами u і v
        graph[u - 1].push_back(v - 1); // Зауважимо, що зчитуємо з індексацією з 1, тому віднімаємо 1
        graph[v - 1].push_back(u - 1); // Оскільки граф невизначений (неорієнтований), додаємо зворотній зв'язок
    }

    file.close();
}

// Функція для жадібного розфарбування графу
void greedyColoring(const vector<vector<int>>& graph, vector<int>& colors) {
    int n = graph.size();
    colors.assign(n, -1); // Ініціалізуємо кольори для всіх вершин як -1 (без кольору)

    // Масив для перевірки доступних кольорів
    set<int> availableColors;

    // Розфарбовуємо кожну вершину
    for (int u = 0; u < n; ++u) {
        // Додаємо всі кольори до доступних
        availableColors.clear();

        // Видаляємо кольори, які вже використовуються сусідами
        for (int neighbor : graph[u]) {
            if (colors[neighbor] != -1) {
                availableColors.insert(colors[neighbor]);
            }
        }

        // Знаходимо перший доступний колір
        int color = 0;
        while (availableColors.find(color) != availableColors.end()) {
            ++color;
        }

        // Присвоюємо колір вершини
        colors[u] = color;
    }
}

// Функція для виведення результатів
void printResult(const vector<int>& colors) {
    int maxColor = *max_element(colors.begin(), colors.end()) + 1;
    cout << "Мінімальна кількість кольорів: " << maxColor << endl;
    cout << "Розфарбовані вершини:" << endl;
    for (int i = 0; i < colors.size(); ++i) {
        cout << "Вершина " << i + 1 << " має колір " << colors[i] << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename = "D:/University/ПДС/Lab_13/graph.txt"; // Вкажіть шлях до вашого файлу

    vector<vector<int>> graph;
    readGraph(filename, graph);

    vector<int> colors;
    greedyColoring(graph, colors);

    printResult(colors);

    return 0;
}
