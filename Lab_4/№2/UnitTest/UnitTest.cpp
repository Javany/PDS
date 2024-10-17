#include "pch.h"
#include "CppUnitTest.h"
#include "../№2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<int> combination;
			Assert::IsFalse(generateCombinations(4,2,1,combination));
		}
	};
}
