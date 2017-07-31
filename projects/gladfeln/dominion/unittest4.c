#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// unit test has been modified from gitHub to fit my needs. It can be found on gitHub username maysw and can be found at https://github.com/maysw/CS-362/blob/Assignment-2/dominion/unittest1.c

int main(int argc, char** argv) {
	
	struct gameState G;	
	printf ("\n Start Unit test 4.....\n");	
	
	G.coins = 0;
	printf ("\n Testing copper coins .....\n");	
	
	G.hand[0][0] = copper;
	G.hand[0][1] = copper;
	G.hand[0][2] = copper;
	G.hand[0][3] = copper;
	G.hand[0][4] = copper;
	G.hand[0][5] = copper;
	G.hand[0][6] = copper;
	G.hand[0][7] = copper;
	G.hand[0][8] = copper;
	G.hand[0][9] = copper;
	updateCoins(0, &G, 0);
	
	printf ("\n Copper coins should equal 10.....\n");	
	
	if(G.coins == 10)
		printf("\n Passed - Copper coins equal to 10 \n");
	else
		printf("\n Failed - Copper coins not equal to 10 \n");
	
	printf ("\n Testing silver coins .....\n");	
	
	G.hand[0][0] = silver;
	G.hand[0][1] = silver;
	G.hand[0][2] = silver;
	G.hand[0][3] = silver;
	G.hand[0][4] = silver;
	G.hand[0][5] = silver;
	G.hand[0][6] = silver;
	G.hand[0][7] = silver;
	G.hand[0][8] = silver;
	G.hand[0][9] = silver;
	updateCoins(0, &G, 0);
	
	printf ("\n Silver coins should equal 10.....\n");	
	if(G.coins == 20)
		printf("\n Passed - Silver coins equal to 10 \n");
	else
		printf("\n Failed - Silver coins not equal to 10 \n");	
		
	printf ("\n Testing gold coins .....\n");	
	
	G.hand[0][0] = gold;
	G.hand[0][1] = gold;
	G.hand[0][2] = gold;
	G.hand[0][3] = gold;
	G.hand[0][4] = gold;
	G.hand[0][5] = gold;
	G.hand[0][6] = gold;
	G.hand[0][7] = gold;
	G.hand[0][8] = gold;
	G.hand[0][9] = gold;
	updateCoins(0, &G, 0);
	
	printf ("\n Gold coins should equal 10.....\n");	
	if(G.coins == 30)
		printf("\n Passed - Gold coins equal to 10 \n");
	else
		printf("\n Failed - Gold coins not equal to 10 \n");		
		
	printf ("\n Testing non money card .....\n");	
	
	G.hand[0][0] = adventurer;
	G.hand[0][1] = adventurer;
	G.hand[0][2] = adventurer;
	G.hand[0][3] = adventurer;
	G.hand[0][4] = adventurer;
	G.hand[0][5] = adventurer;
	G.hand[0][6] = adventurer;
	G.hand[0][7] = adventurer;
	G.hand[0][8] = adventurer;
	G.hand[0][9] = adventurer;
	updateCoins(0, &G, 0);
	
	printf ("\n There should be zero coins .....\n");	
	if(G.coins == 0)
		printf("\n Passed - Zero cards \n");
	else
		printf("\n Failed - Not zero cards \n");		
		
	printf ("\n End of Unit Test 4.....\n");

	return 0;
}