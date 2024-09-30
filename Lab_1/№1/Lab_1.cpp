#include <iostream>
#include <Windows.h>

//Отримання значень від користувача
void getValues(int &value1, int &value2) 
{
	while(true)
	{
		system("cls");

	//Отримання змінної p
		if(value1 == 0 || value1 == 1) std::cout << "Введіть значення для змінної p(1 або 0): " << value1 << std::endl;
		else
		{
			std::cout << "Введіть значення для змінної p(1 або 0): ";
			std::cin >> value1;
			if (value1 != 0 && value1 != 1) continue;
		}

		//Отримання змінної q
		if (value2 == 0 || value2 == 1) std::cout << "Введіть значення для змінної q(1 або 0): " << value2 << std::endl;
		else
		{
			std::cout << "Введіть значення для змінної q(1 або 0): ";
			std::cin >> value2;
			if (value2 == 0 || value2 == 1) break;
		}
	}
}

//Стан
std::string state(bool state)
{
	if (state) return "Істинний (1)";
	else return "Хибний   (0)";
}

//Кон'юнкція
bool conjunction(int v1, int v2)
{
	return v1 && v2;
}

//Диз'юнкція
bool disjunction(int v1, int v2)
{
	return v1 || v2;
}

//Альтернативне "АБО"
bool alternativeOR(int v1, int v2)
{
	if (v1 == v2) return false;
	else return true;
}

//Імплікація
bool implication(int v1, int v2)
{
	if (v1 == 1 && v2 == 0) return false;
	else return true;
}

//Еквівалентність
bool equivalence(int v1, int v2)
{
	if (v1 == v2) return true;
	else return false;
}

void main()
{
	//Підключення кодової сторінки для введення та виведення кирилиці в консолі
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Ініціалізація змінних
	int p = 2, q = 2;

	//Отримання значень від користувача
	getValues(p, q);

	//Кон'юнкція
	std::cout << std::endl << "Результат Кон'юнкції значень p та q -              " << state(conjunction(p, q));
	
	//Диз'юнкція
	std::cout << std::endl << "Результат Диз'юнкції значень p та q -              " << state(disjunction(p, q));

	//Альтернативне "АБО"
	std::cout << std::endl << "Результат Альтернативного \"АБО\" значень p та q -   " << state(alternativeOR(p, q));

	//Імплікація
	std::cout << std::endl << "Результат Імплікації значень p та q -              " << state(implication(p, q));

	//Еквівалентність
	std::cout << std::endl << "Результат Еквівалентності значень p та q -         " << state(equivalence(p, q));
	std::cout << std::endl;
}