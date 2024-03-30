#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "abstractSyntaxTree.h"
#include "programQueue.h"
#include "charQueue.h"


// Order of operations:
// 1. Parse arguments
// 2. Open file
// 3. Call lexer on file
// 4. Move the charQueue to the parser.
// 5. Run parser on the charQueue
// 6. Move programQueue to the exaluator
// 7. Run evaluator on the programQueue

int main(int argc, char* argv[]) {
	FILE* fp = fopen(parseArguments(argv, argc), 'r');
	int i = 0;
	while ((i = fgetc(fp)) != EOF) {
		ITEM item = createItem(i);
		createToken(item, getType(item));
	}
	fclose(fp);

	return 0;
}