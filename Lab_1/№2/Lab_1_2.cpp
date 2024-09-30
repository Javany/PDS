#include <iostream>
#include <Windows.h>

//Операця OR
void funcOrAndXor(std::string &a, std::string &b, unsigned int &n, 
				  std::string &x, std::string &y,  std::string &z)
{
	bool aValue = 0, bValue = 0;
	for (unsigned int i = 0; i < n; i++)
	{
		if (a[i] == '1') aValue = 1;
		else aValue = 0;

		if (b[i] == '1') bValue = 1;
		else bValue = 0;

		//OR
		if (aValue || bValue) x += "1";
		else x += "0";

		//AND
		if (aValue && bValue) y += "1";
		else y += "0";

		//XOR
		if (aValue != bValue) z += "1";
		else z += "0";
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Ініціалізація змінних
	std::string a = "101010110", b = "101110011";
	unsigned int n = a.length();
	std::string x = "", y = "", z = "";

	//Вивід даних
	std::cout << "Бітовий рядок a: " << a << std::endl;
	std::cout << "Бітовий рядок b: " << b << std::endl;
	std::cout << "Довжина рядка a: " << n << "\n\n";

	funcOrAndXor(a, b, n, x, y, z);

	//Вивід результату
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;
	return 0;
}