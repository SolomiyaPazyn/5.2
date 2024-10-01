#include "pch.h"
#include "CppUnitTest.h"
#include "../5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x1 = 0.5;
			int n1 = 1;
			double a1 = 2 * x1;  
			A(x1, n1, a1);

			double expected_R1 = (2.0 * n1 - 1) * pow(x1, 2) / (2.0 * n1 + 1);
			double expected_a1 = 2 * x1 * expected_R1;
			Assert::AreEqual(expected_a1, a1, 0.0001);
		}
	};
}
