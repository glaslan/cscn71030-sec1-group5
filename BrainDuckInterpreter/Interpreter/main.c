#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "charQueue.h"


int main() {
	
	// the queue to pass to parser 
	QNODE* h = NULL;

	// testing input gathering 
	char* input;
	input = getInput();
	int index = 0;
	printf("You entered: %s\n\n", input);

	// testing char extraction 
	printf("\nExtracting chars...\n");
	while (input[index] != '\0') {
		char c = extractChar(input, &index);
		printf("Processing character: %c \n", c);

		// testing tokenization 
		ITEM iTest = createItem(c);
		TOKENTYPE tTest = getType(iTest);
		TOKEN testToken = createToken(iTest, tTest);
		printf("New token created: \ndata = %c\ntype = %s\n", testToken.i.data, TOKENNAME[testToken.t]);

		// add token to queue
		enqueue(createNode(testToken));
	}
	printf("\n");

	printQueue();
	free(h);

	return 0;
}