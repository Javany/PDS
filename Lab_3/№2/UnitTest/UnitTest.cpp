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
			int n = 4;
			vector<vector<long long>> stirling(n + 1, vector<long long>(n + 1, 0));
			vector<long long> bell(n + 1, 0);
			Assert::IsFalse(computeBellNumbers(n, stirling, bell));
		}
	};
}
