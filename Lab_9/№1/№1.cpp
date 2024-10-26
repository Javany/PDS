#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <Windows.h>

using namespace std;

// Функція для завантаження графу зі списку суміжності з файлу
unordered_map<int, vector<int>> loadGraph(const string& filename) {
    unordered_map<int, vector<int>> graph;
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        istringstream iss(line);
        int node;
        iss >> node;
        int neighbor;
        while (iss >> neighbor) {
            graph[node].push_back(neighbor);
        }
    }
    infile.close();
    return graph;
}

// BFS обхід з відображенням протоколу обходу
void bfs(const unordered_map<int, vector<int>>& graph, int start) {
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> bfsNumber;
    int bfsCounter = 1;

    q.push(start);
    visited[start] = true;
    bfsNumber[start] = bfsCounter++;

    cout << "Поточна вершина | BFS-номер | Вміст черги" << endl;
    cout << "---------------------------------------" << endl;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Вивести поточну вершину та її BFS-номер
        cout << "        " << current << "       |      " << bfsNumber[current] << "    | ";

        // Вивести вміст черги
        queue<int> tempQueue = q;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;

        // Перевірка сусідів поточної вершини
        for (int neighbor : graph.at(current)) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                bfsNumber[neighbor] = bfsCounter++;
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Завантажити граф з файлу
    string filename = "graph.txt";
    unordered_map<int, vector<int>> graph = loadGraph(filename);

    // Отримати початкову вершину від користувача
    int start;
    cout << "Введіть початкову вершину: ";
    cin >> start;

    // Виконати BFS обхід
    bfs(graph, start);

    return 0;
}
