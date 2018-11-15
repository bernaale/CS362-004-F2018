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
	printf ("\nTesting supplyCount():\n");  
	
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	initializeGame(numPlayer, kCards, seed, &GS);
	
	//we'll manually set the supplyCount of various cards and compare
	//that to what the supplyCount function returns
	//We'll run through 27 integers representing the 27 enum CARD values
	for (int i = 0; i < 27; i++) {
		if (supplyCount(i, &GS) == GS.supplyCount[i]) {
			#if (OUTPUT == 1)
			printf("supplyCount() is accurately retrieving the %dth enum CARD supply value.\n", i+1); 
			#endif
		} else {
			printf("ERROR: supplyCount() retrieved inaccurate supply value for %dth enum CARD.\n", i+1);
		}
	}

	return 0;
}
