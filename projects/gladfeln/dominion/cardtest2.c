#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// unit test has been modified from gitHub to fit my needs. It can be found on gitHub username maysw and can be found at https://github.com/maysw/CS-362/blob/Assignment-2/dominion/cardtest4.c
int main(int argc, char** argv) {
	
	struct gameState G;
	int r;
	
	//int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	
	printf ("\n CARD 2: Starting gardens test ....... \n");
	G.hand[0][0] = gardens;
	G.numActions = 1;
	r = playCard(0, -1, -1, -1, &G);
	
	assert(G.numActions == 1);
	assert(r == -1);
	
	printf ("\n All test finished \n");
	
	
	printf ("\n CARD 2: End of gardens test ...... \n");

	
	return 0;
}