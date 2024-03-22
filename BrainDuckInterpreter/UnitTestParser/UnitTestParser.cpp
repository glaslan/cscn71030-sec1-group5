#include "pch.h"
#include "CppUnitTest.h"
#include "parser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestParser
{
	TEST_CLASS(UnitTestParser)
	{
	public:
		
		TEST_METHOD(REQ_PAR_01)
		{
			int expected = 0;
			int actual = 0;
			Assert::AreEqual(expected, actual);
		}
	};
}
