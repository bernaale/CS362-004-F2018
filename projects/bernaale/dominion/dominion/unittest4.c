#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set OUPUT to 0 to stop test output
#define OUTPUT 1

int main() {
	struct gameState GS;
	int kCards[10] = {adventurer, council_room, feast, gardens
		    , remodel, smithy, village, outpost, great_hall};
	int seed = 1000;
	int numPlayer = 2;
	printf ("\nTesting numHandCards():\n");  
	
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	initializeGame(numPlayer, kCards, seed, &GS);
	
	//numHandCards should return the number of cards in the hand
	//of whichever players whose turn it is.
	//return state->handCount[ whoseTurn(state) ];
	if (GS.handCount[whoseTurn(&GS)] == numHandCards(&GS)) {
		#if (OUTPUT == 1)
		printf("numHandCards() is working.\n"); 
		#endif
	} else {
		printf("ERROR: numHandCards() malfunctioning.\n");
	}
	return 0;
}
