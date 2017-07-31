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
	int a;
	int count;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	printf ("\n CARD 3: Village card test ..... \n");
	
	initializeGame(2, k, 1, &G);
	count = G.handCount[0];
	G.hand[0][0] = village;
	a = playCard(0, 1, 0, 0, &G);
	
	bad(a == 0, "BUG: Cards not equal");
	bad(count == G.handCount[0], "BUG: Bad handcount");

	
	printf ("\n All tests finished \n");
	printf ("\n CARD 3: Village card test ending .... \n");

	return 0;
}