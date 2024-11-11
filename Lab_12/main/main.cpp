#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
#include <string>
#include <algorithm> // Для std::reverse

const int INF = std::numeric_limits<int>::max();

// Функція для зчитування графу з файлу
void readGraph(const std::string& filename, std::vector<std::vector<std::pair<int, int>>>& graph) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return;
    }

    int n; // Кількість вершин
    file >> n;
    graph.resize(n);

    int u, v, weight;
    while (file >> u >> v >> weight) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            graph[u].push_back({ v, weight }); // Орієнтований граф
        }
    }

    file.close();
}

// Функція для алгоритму Дейкстри
std::vector<int> dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<int>& prev) {
    int n = graph.size();
    std::vector<int> dist(n, INF);
    prev.assign(n, -1);

    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}

// Функція для відновлення шляху з масиву prev
std::vector<int> getPath(int start, int end, const std::vector<int>& prev) {
    std::vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());
    if (path[0] == start) return path;
    return {}; // Повертає порожній вектор, якщо шляху немає
}

// Функція для друку шляху
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
    SetConsoleCP(1251); // Підтримка української мови для консолі
    SetConsoleOutputCP(1251); // Підтримка української мови для консолі

    std::vector<std::vector<std::pair<int, int>>> graph;
    std::string filename = "D:/University/ПДС/Lab_12/graph.txt"; // Вкажіть ваш файл
    readGraph(filename, graph);

    int start, end;

    // Перевірка коректності вводу
    std::cout << "Введіть початкову вершину: ";
    while (!(std::cin >> start) || start < 0 || start >= graph.size()) {
        std::cout << "Невірний ввід! Введіть число в межах кількості вершин: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Введіть кінцеву вершину: ";
    while (!(std::cin >> end) || end < 0 || end >= graph.size()) {
        std::cout << "Невірний ввід! Введіть число в межах кількості вершин: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Запуск алгоритму Дейкстри для знаходження найкоротшого шляху
    std::vector<int> prev;
    std::vector<int> dist = dijkstra(start, graph, prev);

    if (dist[end] == INF) {
        std::cout << "Шлях між вершинами " << start << " та " << end << " не існує." << std::endl;
    }
    else {
        std::cout << "Найкоротша відстань між вершинами " << start << " та " << end << ": " << dist[end] << std::endl;
        std::cout << "Найкоротший шлях: ";
        printPath(getPath(start, end, prev));
    }

    // Частина 2: Найкоротші відстані від однієї вершини до всіх інших
    std::cout << "\nВведіть вершину для обчислення відстаней до всіх інших вершин: ";
    while (!(std::cin >> start) || start < 0 || start >= graph.size()) {
        std::cout << "Невірний ввід! Введіть число в межах кількості вершин: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    dist = dijkstra(start, graph, prev);
    std::cout << "Найкоротші відстані від вершини " << start << ":" << std::endl;
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i] == INF) {
            std::cout << "Вершина " << i << ": INF" << std::endl;
        }
        else {
            std::cout << "Вершина " << i << ": " << dist[i] << std::endl;
        }
    }

    return 0;
}
