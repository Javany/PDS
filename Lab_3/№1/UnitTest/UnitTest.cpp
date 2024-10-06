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
			//Тест для n = 8, r = 5 
			Assert::AreEqual(6720, countFormula(8, 5));

			//Тест для n = 1 , r = 2  
			Assert::AreEqual(1, countFormula(1, 2));

			//Тест для n = 2 , r = 2 
			Assert::AreEqual(2, countFormula(2, 2));

			//Тест для n = 5 , r = 10  
			Assert::AreEqual(120, countFormula(5, 10));
		}
	};
}
