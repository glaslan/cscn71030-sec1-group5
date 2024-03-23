#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace inputTESTS
{
	TEST_CLASS(inputTESTS)
	{
	public:
		
		TEST_METHOD(REQ_LEX_02_01)
		{
		// this will test that '+' is properly identified as the 'increment' enum
			ITEM i = createItem('+');

		}
	};
}
