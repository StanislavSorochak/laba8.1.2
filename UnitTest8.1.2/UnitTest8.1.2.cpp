#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest812
{
	TEST_CLASS(UnitTest812)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[20] = "sssabcadbhjsdasabc";
			char q[] = "abc";
			char q1[] = "abc";
			bool b = false;
			b = (strstr(str, q));
			Assert::AreEqual(b, true);
		}
	};
}
