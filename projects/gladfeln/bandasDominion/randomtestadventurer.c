#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// code has been modified to fit my needs from gitHub user maysw. It can be found at https://github.com/maysw/CS-362/blob/Assignment-3/dominion/randomtestadventurer.c
// Adventurer card test

#define NUM_TESTS 10
#define CARD_COUNT treasure_map

int main() {
	struct gameState G;
	int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
	
	int i;
	int j;
	int player_count;
	int player;
	int seed;
	int deck_treasures;
	int hand_count;
	int pre_count = 0;
	int post_count = 0;
	
	srand(time(NULL));

	printf("\nAdventurer card test ....\n");
	
	for(i = 0; i < NUM_TESTS; i++) {
		seed = rand() % 100;
		if(initializeGame(player_count, k, seed, &G) == -1) {
			printf("Error initializing game\n");
			exit(0);
			}
	}
	player = rand() % player_count;
	G.whoseTurn = player;
	G.numActions = 1;
	G.handCount[player] = 5;
	G.deckCount[player] = rand() % MAX_HAND;
	G.discardCount[player] = 0;
	
	for(j = 0; j < G.deckCount[player]; j++) {
		G.deck[player][j] = rand() % CARD_COUNT;
		if(G.deck[player][j] >= copper && G.deck[player][j] <= gold) {
			deck_treasures++;
		}
	}
	for(j = 0; j < G.handCount[player]; j++) {
		if(G.hand[player][j] >= copper && G.hand[player][j] <= gold) {
			pre_count++;
		}
	G.hand[player][0] = adventurer;
	hand_count = G.handCount[player];
	playCard(0, 0, 0, 0, &G);
	if(hand_count + 2 != G.handCount[player]) {
		printf("Error - two cards into player hand\n");
		exit(0);
	}
	
	for(j = 0; j < G.handCount[player]; j++) {
		if(G.hand[player][j] >= copper && G.hand[player][j] <= gold){
			post_count++;
		}
	}
	
	printf("Pre %d\n", pre_count);
	printf("Post %d\n", post_count);

	if(pre_count +2 != post_count) {
		printf("Error - two cards into player hand\n");
	}
	
	printf("i= %d \n", i);
	}
	printf("End of adventurer test\n");

	return 0;
}