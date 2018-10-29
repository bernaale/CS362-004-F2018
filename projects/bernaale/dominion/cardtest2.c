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
	printf ("\nTesting the outpost card:\n");  
	int z, e, r, o, s;
	z = e = r = o = s = 0; 
	//Set the game to be not over and see if isGameOver
	//returns an accurate status
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	//initializeGame sets state->outpostPlayed flag to 0
	initializeGame(numPlayer, kCards, seed, &GS);

	//playing cardEffect should increment outpostPlayed and call discardCard
	cardEffect(outpost, z, e, r, &GS, o, &s); //outpostPlayed should be 1
	if (GS.outpostPlayed == 1) {
                printf("Outpost flag correctly incremented.\n");
        } else {
        	#if (OUTPUT == 1)
        	printf("Outpost flag did not increment properly\n");
        	#endif
	}

	//discardCard(handPos, currentPlayer, state, 0);
	//because discardCard was called, outpost should not appear in the
	//players hand any longer and it should appear in the playedCards array
	if (GS.playedCards[0] == outpost) {//in played cards?
		printf("Outpost card properly discarded.\n");
        } else {
                #if (OUTPUT == 1)
                printf("ERROR: Outpost card not discarded.\n");
                printf("first played card was %d and outpost is %d\n", GS.playedCards[0], outpost);
		#endif
        }
	
	
	return 0;
}
