#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// unit test has been modified from gitHub to fit my needs. It can be found on gitHub username maysw and can be found at https://github.com/maysw/CS-362/blob/Assignment-2/dominion/unittest2.c

int main(int argc, char** argv) {

	struct gameState G;
	
	printf ("\n Starting unit test 3 ..... \n");
	
	G.numBuys = 2;
	G.coins = 2;
	printf ("\n Testing for insufficient coins: \n");
	int test = buyCard(2, &G);
		if(test == -1)
			printf ("\n Passed - Insufficient coins \n");
		else
			printf ("\n Failed - Not insufficient coins \n");
	printf ("\n Test good purchase: \n");
		G.coins = 10;
		test = buyCard(2, &G);
			if(test == 0)
				printf ("\n Passed - Good purchase \n");
			else
				printf ("\n Failed - Not good purchase \n");
	printf ("\n Test exact amount: \n");
		test = buyCard(2, &G);
			if(test == 0)
				printf ("\n Passed - Exact amount \n");
			else
				printf ("\n Failed - Not exact amount \n");
	printf ("\n Test if there are no buys left: \n");
		G.coins = 6;
		test = buyCard(2, &G);
			if(test == -1)
				printf ("\n Passed - Disallowed additional buy \n");
			else
				printf ("\n Failed - Allowed additional buy \n");
	printf ("\n Ending unit test 3 ..... \n");

	return 0;
	
}