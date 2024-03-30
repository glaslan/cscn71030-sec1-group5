
#include "CppUnitTest.h"

extern "C" {
#include "../Interpreter/charQueue.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace queueTESTS
{
	TEST_CLASS(queueTESTS)
	{
	public:
		
		TEST_METHOD(isEmpty_True)
		{
			initQueue();
			Assert::IsTrue(isEmpty());
		}
		
		TEST_METHOD(isEmpty_False)
		{
			initQueue();
			ITEM i = createItem('-');
			TOKEN t = createToken(i, getType(i));
			enqueue(createNode(t));
			Assert::IsFalse(isEmpty());
			dequeue();
		}
	};
}
