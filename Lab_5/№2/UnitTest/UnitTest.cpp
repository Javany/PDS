#include "pch.h"
#include "CppUnitTest.h"
#include "..\№2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::bitset<n> A("11010100");
			Assert::AreEqual(8, printSet("A", A));
		}
	};
}
