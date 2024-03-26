#include "CppUnitTest.h"

extern "C" {
#include "../Interpreter/lexer.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace inputTESTS
{
	TEST_CLASS(inputTESTS)
	{
	public:
		
		TEST_METHOD(REQ_LEX_02_01)
		{
		// this will test that '+' is properly identified as the 'increment' enum
			ITEM item = createItem('+');
			TOKENTYPE type = getType(item);
			Assert::AreEqual(static_cast<int>(INCREMENT), static_cast<int>(type), L"Token type should be increment");

		}
	};
}
