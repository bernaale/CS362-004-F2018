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
	printf ("\nTesting the gardens card:\n");  
	int z, e, r, o, s;
	z = e = r = o = s = 0; 
	//Set the game to be not over and see if isGameOver
	//returns an accurate status
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	//initializeGame sets GS->supplyCount[province] = 12
	initializeGame(numPlayer, kCards, seed, &GS);
	
	//gardens very simply returns -1
	if (cardEffect(gardens, z, e, r, &GS, o, &s) == -1) { 
                printf("Gardens card returning -1 as expected.\n");
        } else {
        	#if (OUTPUT == 1)
        	printf("ERROR: Gardens card not returning -1.\n");
        	#endif
	}
	return 0;
}
