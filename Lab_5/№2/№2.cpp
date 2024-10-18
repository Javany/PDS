#include <iostream>
#include <bitset>
#include <Windows.h>

const int n = 8; // Розмір універсуму

int printSet(const std::string& name, std::bitset<n> set) {
    std::cout << name << ": {";
    int i = 0;
    for (i; i < n; i++) {
        if (set[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << "}" << std::endl;
    return i;
}

int main() {
    SetConsoleOutputCP(1251);
    // Задати множини A і B як бітові рядки
    std::bitset<n> A("11010100"); // Множина A: {2, 4, 5, 7}
    std::bitset<n> B("10111000"); // Множина B: {3, 4, 6, 7}

    // Обчислення операцій
    std::bitset<n> notA = ~A;        // Доповнення A
    std::bitset<n> intersection = A & B; // Перетин A ∩ B
    std::bitset<n> unionAB = A | B;      // Об'єднання A ∪ B
    std::bitset<n> difference = A & ~B;  // Різниця A \ B
    std::bitset<n> xorAB = A ^ B;        // Симетрична різниця A ⊕ B

    // Виведення результатів
    printSet("A", A);
    printSet("not A", notA);
    printSet("A intersection B", intersection);
    printSet("A union B", unionAB);
    printSet("A \\ B", difference);
    printSet("A xor B", xorAB);

    return 0;
}
