#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\Lab_1_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool x = main();
			Assert::IsFalse(x);
		}
	};
}
