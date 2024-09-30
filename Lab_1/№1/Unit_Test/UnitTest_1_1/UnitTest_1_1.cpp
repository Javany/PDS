#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\Lab_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11
{
	TEST_CLASS(UnitTest11)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int p = 1, q = 0;
			bool x = conjunction(p,q);
			Assert::IsFalse(x);
		}
	};
}
