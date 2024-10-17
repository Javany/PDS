#include "pch.h"
#include "CppUnitTest.h"
#include "../№1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 4, quantityValue = 1;
			std::string value = "";
			for (int i = 1; i <= n; i++)
			{
				quantityValue *= i;
				value += std::to_string(i);
			}
			std::string* valueArr = new std::string[quantityValue];
			std::string firstNumberS = "";
			firstNumberS += value[0];
			int firstNumber = std::stoi(firstNumberS);
			std::string partOfValue = "", valueRepeat = value;
			for (int i = 1; i < n; i++)									
			{
				partOfValue += value[i];
			}
			Assert::AreEqual(0, calculate(quantityValue, valueArr, value, partOfValue, valueRepeat, n, firstNumber));
		}
	};
}
