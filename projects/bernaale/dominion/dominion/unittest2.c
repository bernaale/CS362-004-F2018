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
	printf ("\nTesting isGameOver():\n");  
	
	//Set the game to be not over and see if isGameOver
	//returns an accurate status
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	//initializeGame sets GS->supplyCount[province] = 12
	initializeGame(numPlayer, kCards, seed, &GS);
	
	//game should be over due to no province cards
	//isGameOver should return 1
	GS.supplyCount[province] = 0;
	if (isGameOver(&GS) != 1) {
		printf("isGameOver() ERROR when no province cards remain.\n");
	} else {
		#if (OUTPUT == 1)
		printf("isGameOver() working when provinces depleted.\n");
		#endif
	}
	//Set the game to have province cards, but three empty supply piles 
	//see if isGameOver returns an accurate status (i.e. 1)
	GS.supplyCount[province] = 12;
	GS.supplyCount[curse] = 0;
	GS.supplyCount[estate] = 0;
	GS.supplyCount[duchy] = 0;
	if (isGameOver(&GS) != 1) {
                printf("isGameOver() ERROR when provinces > 0 but 3 empty supply piles.\n");
        } else {
        	#if (OUTPUT == 1)
        	printf("isGameOver() working when provinces > 0 but 3 empty supply piles.\n");
        	#endif
	}

	//Set the game to have province cards and two empty supply piles
	//game should be ongoing (i.e. return 0)
        GS.supplyCount[province] = 12;
        GS.supplyCount[curse] = 3; //reset from previous test
	GS.supplyCount[estate] = 0;
        GS.supplyCount[duchy] = 0;
        if (isGameOver(&GS) != 0) {
                printf("isGameOver() ERROR when provinces > 0 and 2 empty supply piles.\n");
        } else {
        	#if (OUTPUT == 1)
        	printf("isGameOver() working when province > 0 and 2 empty supply piles.\n");
        	#endif
	}
	return 0;
}
