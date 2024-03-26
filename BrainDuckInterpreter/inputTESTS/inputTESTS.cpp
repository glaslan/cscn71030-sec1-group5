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
			ITEM itemA = createItem('+');
			TOKENTYPE typeA = getType(itemA);
			Assert::AreEqual(static_cast<int>(INCREMENT), static_cast<int>(typeA));

		}

		TEST_METHOD(REQ_LEX_02_02)
		{
			// this will test that '<' is properly identified as the 'move left' enum
			ITEM itemB = createItem('<');
			TOKENTYPE typeB = getType(itemB);
			Assert::AreEqual(static_cast<int>(MOVE_LEFT), static_cast<int>(typeB));

		}

		TEST_METHOD(REQ_LEX_02_03)
		{
			// this will test that '[' is properly identified as the 'jump back' enum
			ITEM itemC = createItem('[');
			TOKENTYPE typeC = getType(itemC);
			Assert::AreEqual(static_cast<int>(JUMP_BACK), static_cast<int>(typeC));

		}

		TEST_METHOD(REQ_LEX_02_04)
		{
			// this will test that 'a' is properly identified as the 'invalid' enum
			ITEM itemD = createItem('a');
			TOKENTYPE typeD = getType(itemD);
			Assert::AreEqual(static_cast<int>(INVALID), static_cast<int>(typeD));

		}
	};
}
