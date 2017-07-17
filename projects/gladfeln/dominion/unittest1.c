#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// unit test has been modified from gitHub to fit my needs. It can be found on gitHub username maysw and can be found at https://github.com/maysw/CS-362/blob/Assignment-2/dominion/unittest4.c

int main(int argc, char** argv) {
	
	struct gameState G;
	int a;

	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	
	//printf ("\n Starting Test \n");
	fprintf(stderr, "\n ... Start unit test 1 ........ \n");
	
	for (int x = 2; x < 5; ++x) {
		a = initializeGame(2, k, 5, &G);
		a = whoseTurn(&G);
		assert(a == G.whoseTurn);
			printf("\nPass\n");		
	}
	
	//printf ("\nEnd of Test\n");
	fprintf(stderr, "\n ... End unit test 1 ........ \n");

	return 0;
}