#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <string>

const int INF = std::numeric_limits<int>::max(); // Нескінченність для алгоритму Флойда-Уоршелла

void readGraph(const std::string& filename, std::vector<std::vector<int>>& graph) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return;
    }

    int n; // Кількість вершин
    file >> n;
    graph.assign(n, std::vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    int u, v, weight;
    while (file >> u >> v >> weight) {
        graph[u][v] = weight; // Орієнтований граф, тому тільки від u до v
    }

    file.close();
}

void floydWarshall(std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& next) {
    int n = graph.size();
    next.assign(n, std::vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INF && i != j) {
                next[i][j] = j;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF) {
                std::cout << "INF ";
            }
            else {
                std::cout << matrix[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

std::vector<int> getPath(int start, int end, const std::vector<std::vector<int>>& next) {
    if (next[start][end] == -1) return {}; // Немає шляху

    std::vector<int> path = { start };
    while (start != end) {
        start = next[start][end];
        path.push_back(start);
    }
    return path;
}

void printPath(const std::vector<int>& path) {
    if (path.empty()) {
        std::cout << "Шлях не існує" << std::endl;
        return;
    }
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> next;

    // Зчитування графу з файлу
    std::string filename = "D:/University/ПДС/Lab_11/graph.txt";
    readGraph(filename, graph);

    // Виконання алгоритму Флойда-Уоршелла
    floydWarshall(graph, next);

    // Виведення матриці відстаней
    std::cout << "Матриця найкоротших відстаней між усіма парами вершин:" << std::endl;
    printMatrix(graph);

    // Пошук найкоротшого шляху між обраними вершинами
    int start, end;
    std::cout << "\nВведіть початкову вершину: ";
    std::cin >> start;
    std::cout << "Введіть кінцеву вершину: ";
    std::cin >> end;

    if (graph[start][end] == INF) {
        std::cout << "Шлях між вершинами " << start << " та " << end << " не існує." << std::endl;
    }
    else {
        std::cout << "Найкоротша відстань: " << graph[start][end] << std::endl;
        std::cout << "Найкоротший шлях: ";
        printPath(getPath(start, end, next));
    }

    return 0;
}
