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
			Assert::IsFalse(formula(0, 0, 0));
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::IsFalse(formula(0, 0, 1));
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::IsTrue(formula(1, 0, 1));
		}
		TEST_METHOD(TestMethod4)
		{
			Assert::IsTrue(formula(1, 1, 0));
		}
	};
}
