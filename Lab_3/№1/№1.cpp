#include <iostream>
#include <windows.h>

void getValue(int &n, int &r)
{
	std::cout << "Введіть значення для змінної n: ";
	std::cin >> n;
	std::cout << "Введіть значення для змінної r: ";
	std::cin >> r;
}

int countFormula(int n, int r)
{
	int p1 = 1, p2 = 1;

	//Визначаємо P1
	for (int i = 1; i <= n; i++)
	{
		p1 = p1 * i;
	}

	//Визначаємо P2
	for (int i = 1; i <= n - r; i++)
	{
		p2 = p2 * i;
	}

	return p1 / p2;
}

void main()
{
	//Підключення кодової сторінки для кирилиці
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0, r = 0;

	//Отримання даних від користувача
	getValue(n, r);

	//Вивід результату
	std::cout << "\nРезультат обчислення формули n! / (n - r)!: " << countFormula(n, r);
}