#include "pch.h"
#include "CppUnitTest.h"
#include "..\№1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<std::string>A = { "a", "b", "c" };
			std::vector<std::string> B = { "x", "y", "z" };
			std::vector<int> C = { 0, 1 };
			Assert::AreEqual(0, ACB(A, B, C));
		}
	};
}
