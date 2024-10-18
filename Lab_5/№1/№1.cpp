#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

int ACB(std::vector<std::string> &A, std::vector<std::string> &B, std::vector<int> &C)
{
    // Виведення декартового добутку A x C x B
    std::cout << "Множина АхСхВ: " << std::endl;
    for (const std::string& a : A) {
        for (int c : C) {
            for (const std::string& b : B) {
                std::cout << "(" << a << ", " << c << ", " << b << ")" << std::endl;
            }
        }
    }
    return 0;
}

int main() {
    SetConsoleOutputCP(1251);
    // Оголошення множин A, B та C
    std::vector<std::string> A = { "a", "b", "c" };
    std::vector<std::string> B = { "x", "y", "z" };
    std::vector<int> C = { 0, 1 };

    ACB(A, B, C);

    return 0;
}