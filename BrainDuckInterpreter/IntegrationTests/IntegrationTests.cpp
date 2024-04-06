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
		
		// testing lexer reads input as expected
		TEST_METHOD(INP_LEX_01)
		{
			char input[] = "><,";
			for(int i = 0; i < 3; i++){
				char expected = input[i];
				char actual = extractChar(input, &i);

				Assert::AreEqual(expected, actual);
			}
		}

		// testing the accuracy of token conversion - normal usage 
		TEST_METHOD(TOK_LEX_02)
		{ 
			ITEM i = createItem('<');
			TOKENTYPE actual = getType(i);

			Assert::AreEqual((int)MOVE_LEFT, (int)actual);
		}

		// testing the accuracy of token conversion - invalid usage 
		TEST_METHOD(TOK_LEX_03) 
		{
			ITEM i = createItem('Q');
			TOKENTYPE actual = getType(i);
			
			Assert::AreEqual((int)INVALID, (int)actual);
		}

		// testing that queue contents are visible to parser 
		TEST_METHOD(QUE_LEX_04)
		{
			ITEM i = createItem('+');
			TOKEN t = createToken(i, getType(i));
			CHARQUEUE* q = initQueue();
			enqueue(q, createNode(t));
			int result = errorNullTokenList();

			Assert::AreNotEqual(0, result);
		}

		// testing the items in the queue are in the right order 
		TEST_METHOD(QUE_LEX_05)
		{
			char string[] = "+/.";
			CHARQUEUE* cq = initQueue();
			for(int i = 0; i < 3; i++){
				ITEM item = createItem(string[i]);
				TOKEN t = createToken(item, getType(item));
				QNODE* n = createNode(t);
				enqueue(cq, n);
			}

			//check all to verify order
			QNODE dqA = dequeue(cq);
			char actualA = dqA.token.i.data;
			char expectedA = '+';

			QNODE dqB= dequeue(cq);
			char actualB = dqB.token.i.data;
			char expectedB = '/';

			QNODE dqC = dequeue(cq);
			char actualC = dqC.token.i.data;
			char expectedC = '.';
			
			Assert::AreEqual(expectedA, actualA);
			Assert::AreEqual(expectedB, actualB);
			Assert::AreEqual(expectedC, actualC);

		}

		// testing accuracy of token type to token name 
		TEST_METHOD(OUT_LEX_06)
		{
			TOKENTYPE type = DOUBLE;
			const char* expected = "DOUBLE";
			const char* actual = TOKENNAME[(int)type];
	
			Assert::AreEqual(expected, actual); 
		}

		// testing that token name is accurate when accessing through token
		TEST_METHOD(OUT_LEX_07)
		{
			ITEM i = createItem('[');
			TOKENTYPE type = getType(i);
			TOKEN token = createToken(i, type);

			const char* expected = "JUMP BACK";
			const char* actual = TOKENNAME[(int)token.t];

			Assert::AreEqual(expected, actual);
		}

	};

	TEST_CLASS(IntegrationTestsParser)
	{
	public:

		TEST_METHOD(INT_PAR_01)
		{
			ITEM i = createItem('+');
			TOKEN t = createToken(i, INCREMENT);
			QNODE* q = createNode(t);
			CHARQUEUE* cq = initQueue();
			enqueue(cq, q);
			Assert::IsNotNull(cq);
		}
		TEST_METHOD(INT_PAR_02)
		{
			ITEM i = createItem('n');
			TOKEN inv = createToken(i, INVALID);
			int expected = 1;
			int actual = errorInvalidToken(inv.t, 26);
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(INT_PAR_03)
		{
			ITEM i = createItem('\0');
			TOKEN t = createToken(i, END_TOKEN);
			QNODE* q = createNode(t);
			CHARQUEUE* cq = initQueue();
			enqueue(cq, q);
			PTREENODE p = parseProgram(cq);
			Assert::IsNotNull(p);
			destroyAST(p);
		}
		/*TEST_METHOD(INT_PAR_04)
		{
			// SEE INT_AST_07
		}*/
		TEST_METHOD(INT_PAR_05)
		{
			// Prereq: Run the program with too many arguments
			Assert::IsTrue(errorTooManyArgs());
		}
	};

	TEST_CLASS(IntegrationTestsAST)
	{
	public:

		TEST_METHOD(INT_AST_01)
		{
			ITEM i = createItem('\0');
 			TOKEN t = createToken(i, END_TOKEN);
			QNODE* q = createNode(t);
			CHARQUEUE* cq = initQueue();
			enqueue(cq, q);
			PTREENODE p = parseProgram(cq);
			Assert::AreEqual(1, p->value);
			destroyAST(p);
		}
		TEST_METHOD(INT_AST_02)
		{
			TOKEN t1 = createToken(createItem('+'), INCREMENT);
			TOKEN t2 = createToken(createItem('*'), DOUBLE);
			TOKEN t3 = createToken(createItem('>'), MOVE_RIGHT);
			PTREENODE p = createTreeNode(t1);
			addNode(p, t2);
			addNode(p, t3);
			Assert::IsTrue(destroyAST(p));
			
		}
		TEST_METHOD(INT_AST_03)
		{
			TOKEN t1 = createToken(createItem('+'), INCREMENT);
			TOKEN t2 = createToken(createItem('*'), DOUBLE);
			TOKEN t3 = createToken(createItem('>'), MOVE_RIGHT);
			PTREENODE p = createTreeNode(t1);
			addNode(p, t2);
			addNode(p, t3);
			Assert::IsNotNull(p);
			Assert::IsNotNull(p->right);
			Assert::IsNull(p->left); // Left should be NULL
			destroyAST(p);
		}
		// Redacted
		/*TEST_METHOD(INT_AST_04)
		{
		}*/
		TEST_METHOD(INT_AST_05)
		{
			TOKEN t1 = createToken(createItem('+'), INCREMENT);
			TOKEN t2 = createToken(createItem('*'), DOUBLE);
			TOKEN t3 = createToken(createItem('.'), OUTPUT);
			PTREENODE p = createTreeNode(t1);
			addNode(p, t2);
			addNode(p, t3);
			ini();
			Eval(p);
			//Eval should print to console
			Assert::IsNotNull(p);
			destroyAST(p);
		}
		TEST_METHOD(INT_AST_06)
		{
			TOKEN t1 = createToken(createItem('+'), INCREMENT);
			TOKEN t2 = createToken(createItem('*'), DOUBLE);
			PTREENODE p = createTreeNode(t1);
			addNode(p, t2);
			Assert::IsNotNull(p);
			Assert::IsNotNull(p->right);
			Assert::IsNull(p->left); // Left should be NULL
			destroyAST(p);
		}
		// Test to make sure the tree is built correctly
		TEST_METHOD(INT_AST_07)
		{
			TOKEN t1 = createToken(createItem('+'), INCREMENT);
			TOKEN t2 = createToken(createItem('*'), DOUBLE);
			TOKEN t3 = createToken(createItem('+'), INCREMENT);
			TOKEN t4 = createToken(createItem('+'), INCREMENT);
			TOKEN t5 = createToken(createItem('+'), INCREMENT);
			TOKEN t6 = createToken(createItem('>'), MOVE_RIGHT);
			TOKEN t7 = createToken(createItem('+'), INCREMENT);
			PTREENODE p = createTreeNode(t1);
			addNode(p, t2);
			addNode(p, t3);
			addNode(p, t4);
			addNode(p, t5);
			addNode(p, t6);
			addNode(p, t7);
			Assert::IsNotNull(p); // +
			Assert::IsNotNull(p->right); // *
			Assert::IsNull(p->left);
			Assert::IsNotNull(p->right->right); // +
			Assert::IsNull(p->right->left);
			destroyAST(p);
		}
		
	};

	TEST_CLASS(IntegrationTestsEvaluator)
	{
	public:

		//test to see if eval's input is in a correct form
		TEST_METHOD(INP_EVA_01)
		{
			TOKEN t1 = createToken(createItem('+'), INCREMENT);
			TOKEN t2 = createToken(createItem('*'), DOUBLE);
			TOKEN t3 = createToken(createItem('+'), INCREMENT);
			TOKEN t4 = createToken(createItem('\0'), END_TOKEN);
			CHARQUEUE* cq = initQueue();
			enqueue(cq, createNode(t1));
			enqueue(cq, createNode(t2));
			enqueue(cq, createNode(t3));
			enqueue(cq, createNode(t4));
			PTREENODE test = parseProgram(cq);	//manual: PTREENODE can assign to parseProgram
			Assert::IsNotNull(test);
			while (cq != NULL) {
				dequeue(cq);
			}
		};
		//test to see if random function gives data in a valid range
		TEST_METHOD(INT_EVA_04)
		{
			/*randNum(tape, &idx);
			bool test = false;
			if (tape[idx]<256 && tape[idx]>-1)test = true;
			Assert::IsTrue(test);*/
		};
	};
}
