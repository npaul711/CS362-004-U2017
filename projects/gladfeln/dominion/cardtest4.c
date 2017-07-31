#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// unit test has been modified from gitHub to fit my needs. It can be found on gitHub username wuzha and can be found at https://github.com/CS362-Winter-2016/cs362w16_wuzha/blob/master/project/wuzha/dominion/cardtest1.c
int bad(int b, char* s) {
	if(!b) {
		printf("Fail: %s\n", s);
	}
}
int main(int argc, char** argv) {
	
	struct gameState G;
	int a;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	printf ("\n CARD 4: Minion card test ..... \n");
	
	int b = G.coins;
	initializeGame(2, k, 1, &G);
	G.hand[0][0] = minion;
	a = playCard(0, 1, 0, 0, &G);
	
	bad(a == 0, "BUG: Cards not equal");
	bad(G.handCount[whoseTurn(&G)] == 4, "BUG: Bad handcount");
	bad(G.coins == b + 2, "bug");
		printf ("\n CARD 4: Minion card test ending .... \n");

	return 0;
}