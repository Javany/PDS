#include <iostream>
#include <cmath>

bool formula(bool p = 0, bool q = 0, bool r = 0)
{
	return (p && q) != (p && r);
}

void countUniqueBitValues(int bitLineLength)
{
	//bitLineLength - довжина бітового рядка
	//Обчислення кількостів унікальних значень
	int quantity = pow(2, bitLineLength);

	//Ініціалізація Першого і поточного значення
	std::string currentValue = "";
	for (int i = 0; i < bitLineLength; i++)
	{
		currentValue += "0";
	}

	bool p = 0, q = 0, r = 0;
	/*std::string line = "";*/
	for (int i = 0; i < quantity; i++) 
	{
		if (currentValue[0] == '1') p = 1;
		else p = 0;
		if (currentValue[1] == '1') q = 1;
		else q = 0;
		if (currentValue[2] == '1') r = 1;
		else r = 0;

		std::cout << p << " " << q << " " << r << "\t" << formula(p, q, r)<<std::endl;

		// Інкрементація двійкового числа
		for (int j = currentValue.size() - 1; j >= 0; j--) {
			if (currentValue[j] == '0') {
				currentValue[j] = '1';
				break;
			}
			else {
				currentValue[j] = '0';
			}
		}
	}
}

void main()
{
	std::cout << "p q r\tresult" << std::endl;
	std::cout << "_______________" << std::endl;
	countUniqueBitValues(3);
}





