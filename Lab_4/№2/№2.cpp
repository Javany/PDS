#include <iostream>
#include <vector>
#include <Windows.h>

// Функція для виведення поточної комбінації
void printCombination(const std::vector<int>& combination) {
    for (int num : combination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Рекурсивна функція для генерації комбінацій
int generateCombinations(int n, int r, int start, std::vector<int>& combination) {
    if (combination.size() == r) {
        printCombination(combination); // Якщо набрано r елементів, виводимо комбінацію
        return 0;
    }

    for (int i = start; i <= n; ++i) {
        combination.push_back(i); // Додаємо елемент до комбінації
        generateCombinations(n, r, i + 1, combination); // Генеруємо наступні елементи
        combination.pop_back(); // Після завершення прибираємо останній елемент для наступних ітерацій
    }
    return 0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, r;

    // Введення n і r
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;
    std::cout << "Введіть ціле число r (r <= n): ";
    std::cin >> r;

    std::vector<int> combination; // Вектор для зберігання поточної комбінації

    // Генерація та виведення всіх r-сполучень
    std::cout << "Усі можливі r-сполучення:\n";
    generateCombinations(n, r, 1, combination);

    return 0;
}