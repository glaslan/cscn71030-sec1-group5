#include "pch.h"
#include "CppUnitTest.h"
#include "../../BrainDuckInterpreter/Interpreter/parser.h"
#include "../../BrainDuckInterpreter/Interpreter/abstractSyntaxTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestParserAndAST
{


	TEST_CLASS(UnitTestParserAndAST)
	{
	public:
		
		/*TEST_METHOD(REQ_PAR_01)
		{
			typedef struct token {
				char item;
			}TOKEN;

			typedef struct qnode {
				TOKEN token;
				struct qnode* next;
			}QNODE;

			TOKEN t;
			t.item = '+';
			QNODE* q;
			q->token = t;
			q->next = NULL;
			Assert::IsNotNull(parseProgram(q));
		}*/
		//TEST_METHOD(REQ_PAR_02)
		//{
		//	errorInvalidToken('c', 10);
		//	// Program must exit and print an error
		//}
		TEST_METHOD(parseShifts)
		{
			PTREENODE tn = NULL;
			QNODE* qn = NULL;
			Assert::IsFalse(parseShiftRight(tn, qn));
			Assert::IsFalse(parseShiftLeft(tn, qn));
		}

	};
}
