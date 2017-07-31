#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// code has been modified to fit my needs from gitHub user maysw. It can be found at https://github.com/maysw/CS-362/blob/Assignment-3/dominion/randomtestcard.c

// Village card test

#define MAX_TESTS 1000

int main() {
	struct gameState state;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	int r = 0;
	int i = 0;
	int players = 0;
	int player = 0;
	int seed = 0;
	int errors = 0;
	struct gameState temp;

	srand(time(NULL));
	
	printf("Beginning village random card test.....\n");
	
	for(i = 0; i < MAX_TESTS; i++) {
		do {
			players = rand() % 4;
		} while (players < 2);
	
	seed = rand();
	initializeGame(players, k, seed, &state);

		do {
			player = rand() % players;
		} while (player == 0);	
		
		
	state.whoseTurn = player;
	state.deckCount[player] = rand() % MAX_DECK;
	state.discardCount[player] = rand() % MAX_DECK;
	state.handCount[player] = rand() % MAX_HAND;
	state.hand[player][0] = village;
	state.numActions = rand() % 10;
	memcpy(&temp, &state, sizeof(struct gameState));
	r = cardEffect(village, 0, 0, 0, &state, 0, 0);
	assert(r == 0);
	
	if (state.deckCount[player] != (temp.deckCount[player] - 1)) {errors++;}
	if (state.numActions != (temp.numActions + 2)) {errors++;}
	
	}
	printf("%d\n errors in random village test... \n", errors);
	
	
	return 0;
}