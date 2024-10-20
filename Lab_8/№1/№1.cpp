#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

// Функція для зчитування графа з файлу
void readGraph(const string& filename, int& n, vector<vector<int>>& adjList) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    int m; // кількість вершин та ребер
    inFile >> n >> m;
    adjList.resize(n);

    for (int i = 0; i < m; ++i) {
        int v, u;
        inFile >> v >> u;
        adjList[v - 1].push_back(u - 1); // Індексація вершин з 0
        adjList[u - 1].push_back(v - 1); // Граф є неорієнтованим
    }

    inFile.close();
}

// Функція для виводу поточного стану стеку
void printStack(const stack<int>& s) {
    stack<int> temp = s;
    cout << "[";
    bool first = true;
    while (!temp.empty()) {
        if (!first) cout << ", ";
        cout << temp.top() + 1; // +1 для індексації з 1
        temp.pop();
        first = false;
    }
    cout << "]";
}

// Функція для обходу графа пошуком у глибину (DFS)
void DFS(int start, const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false);
    vector<int> dfsNumber(adjList.size(), -1); // Номери DFS для вершин
    stack<int> s;
    int dfsCount = 0;

    s.push(start);
    visited[start] = true;
    dfsNumber[start] = ++dfsCount;

    cout << "Iteration | Current Vertex | DFS Number | Stack\n";
    cout << "--------------------------------------------------\n";

    while (!s.empty()) {
        int current = s.top();
        cout << "   " << dfsCount << "       |       " << current + 1 << "       |    "
            << dfsNumber[current] << "       | ";
        printStack(s);
        cout << endl;

        bool foundUnvisited = false;
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dfsNumber[neighbor] = ++dfsCount;
                s.push(neighbor);
                foundUnvisited = true;
                break;
            }
        }

        if (!foundUnvisited) {
            s.pop();
        }
    }
}

int main() {
    string inputFileName;
    int n; // Кількість вершин
    vector<vector<int>> adjList; // Список суміжності

    // Введення вхідного файлу
    cout << "Enter input file name: ";
    cin >> inputFileName;

    // Зчитуємо граф з файлу
    readGraph(inputFileName, n, adjList);

    // Введення початкової вершини
    int startVertex;
    cout << "Enter start vertex (1 to " << n << "): ";
    cin >> startVertex;
    startVertex--; // Перетворюємо на індексацію з 0

    // Обхід графа пошуком у глибину
    DFS(startVertex, adjList);

    return 0;
}