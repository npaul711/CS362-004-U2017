#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// code has been modified to fit my needs from gitHub user rogersza. It can be found at https://github.com/CS362-Winter-2016/cs362w16_rogersza/blob/master/dominion/randomtestcard.c

// Council room card test

#define NUM_TESTS 32

int main() {
	struct gameState *g = NULL;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	int i;
	int a = 0;
	int b = 0;
	
	for(i = 0; i < NUM_TESTS; i++){
		int num_players = rand() % 4;
		int rand_seed = rand();
		int player = 0;
		
		g = malloc(sizeof(struct gameState));
		int status = initializeGame(num_players, k, rand_seed, g);
		
		g->deckCount[player] = rand() % MAX_DECK;
		g->discardCount[player] = rand() % MAX_DECK;
		g->handCount[player] = rand() % MAX_HAND;
		
		int pre_count = g->handCount[player];
		cardEffect(council_room, 1, 1, 1, g, 0, 0);
		
		int post_count = g->handCount[player];
		
		if((pre_count + 4) == post_count) a++;
		else b++;
		
		printf("Test %d/%d complete\n", i + 1, NUM_TESTS);
		free(g);
		
		return 0;
	}
	
	return 0;
}