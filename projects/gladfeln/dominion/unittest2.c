#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// unit test has been modified from gitHub to fit my needs. It can be found on gitHub username maysw and can be found at https://github.com/maysw/CS-362/blob/Assignment-2/dominion/unittest3.c

int main(int argc, char** argv) {
	
	struct gameState state;
	
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};

	int a = initializeGame(2, k, 3, &state);
	
	printf ("\n Starting unit test 2 ..... \n");
	
	int j = isGameOver(&state);
	assert(j == 0);
	
	printf ("\n Passed \n");
	
	printf ("\n Ending unit test 2 ..... \n");

	assert(a == 0);

	return 0;
}