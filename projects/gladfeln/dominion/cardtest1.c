#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// unit test has been modified from gitHub to fit my needs. It can be found on gitHub username wuzha and can be found at https://github.com/CS362-Winter-2016/cs362w16_wuzha/blob/master/project/wuzha/dominion/cardtest2.c
int bad(int b, char* s) {
	if(!b) {
		printf("Fail: %s\n", s);
	}
}
int main(int argc, char** argv) {
	
	struct gameState G;
	int count;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	printf ("\n CARD 1: Smithy card test ..... \n");
	
	initializeGame(2, k, 1, &G);
	G.hand[0][4] = smithy;
	G.whoseTurn = 0;
	count = G.handCount[0];
	playCard(4, -1, -1, -1, &G);
	
	bad(count <= G.handCount[0], "BUG: Bad hand count");
	bad(G.deckCount[0] == 0, "BUG: Bad deck count");
	bad(count + 2 == G.handCount[0], "BUG: Bad additional cards count");
	
	printf ("\n All tests finished \n");
	printf ("\n CARD 1: Smithy card test ending .... \n");

	return 0;
}