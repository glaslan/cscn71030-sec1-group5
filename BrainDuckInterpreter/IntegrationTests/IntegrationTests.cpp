#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Interpreter/lexer.h"
#include "../Interpreter/charQueue.h"
#include "../Interpreter/parser.h"
#include "../Interpreter/abstractSyntaxTree.h"
#include "../Interpreter/programQueue.h"
#include "../Interpreter/evaluator.h"
#include "../Interpreter/const.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegrationTests
{
	TEST_CLASS(IntegrationTestsLexer)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
		}
	};

	TEST_CLASS(IntegrationTestsParser)
	{
	public:

		TEST_METHOD(INT_PAR_01)
		{
			ITEM i = createItem('a');
			TOKEN t = createToken(i, INCREMENT);
			QNODE q = createNode(t);
			QNODE* qPtr = &q;
			PTREENODE p = parseProgram(qPtr);
			Assert::IsNotNull(p);
		}
		TEST_METHOD(INT_PAR_02)
		{
		}
		TEST_METHOD(INT_PAR_03)
		{
		}
		TEST_METHOD(INT_PAR_04)
		{
		}
		TEST_METHOD(INT_PAR_05)
		{
		}
		TEST_METHOD(INT_PAR_06)
		{
		}
	};

	TEST_CLASS(IntegrationTestsAST)
	{
	public:

		TEST_METHOD(INT_AST_01)
		{
		}
		TEST_METHOD(INT_AST_02)
		{
		}
		TEST_METHOD(INT_AST_03)
		{
		}
		TEST_METHOD(INT_AST_04)
		{
		}
		TEST_METHOD(INT_AST_05)
		{
		}
		TEST_METHOD(INT_AST_06)
		{
		}
	};

	TEST_CLASS(IntegrationTestsEvaluator)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
		}
	};
}
