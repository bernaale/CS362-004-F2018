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
		    , remodel, smithy, village, outpost, great_hall, cutpurse};
	int seed = 1000;
	int numPlayer = 2;
	printf ("\nTesting the adventurer card:\n");  
	int z, e, r, o, s;
	z = e = r = o = s = 0; 
	
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	//initializeGame sets state->outpostPlayed flag to 0
	initializeGame(numPlayer, kCards, seed, &GS);
	
	// 1.
	//first we'll see if the player received two treasure cards by comparing 
	//the number of cards they have before and after adventurer
	int currplayer = whoseTurn(&GS);
	int beforeNum = GS.handCount[currplayer];
	cardEffect(adventurer, z, e, r, &GS, o, &s); //outpostPlayed should be 1
	if ((beforeNum+2) == GS.handCount[currplayer]) {//add 2 because gain three & discarded smithy
                printf("2 treasure cards successfully given to player from adventurer.\n");
        } else {
        	#if (OUTPUT == 1)
        	printf("ERROR: Player cards did not increase by 2 after adventurer.\n");
        	printf("beforeNum is %d and after is %d.\n", beforeNum, GS.handCount[currplayer]);
		#endif
	}
	

	// 2.
	//do the 3 cards come from player draw pile?
	//They should, we'll compare before and after
        memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	initializeGame(numPlayer, kCards, seed, &GS);
	currplayer = whoseTurn(&GS);
        int beforeNumDeck = GS.deckCount[currplayer];
        cardEffect(adventurer, z, e, r, &GS, o, &s); //outpostPlayed should be 1
        if ((beforeNumDeck-2) == GS.deckCount[currplayer]) {//should be same
                printf("User deck has two cards gone from adventurer.\n");
        } else {
                #if (OUTPUT == 1)
                printf("ERROR: Player's deck not down by two from adventurer.\n");
                printf("beforeNumDeck is %d and after is %d.\n", beforeNumDeck, GS.deckCount[currplayer]);
                #endif
        }


	
	
	// 3.
	//No state changes for other players
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
        //initializeGame resets the parameters
        initializeGame(numPlayer, kCards, seed, &GS);
        
	//similar to before we'll check the before and after card number
        //but this time for the nextPlayer
	int nexplayer = whoseTurn(&GS)+1;
        beforeNum = GS.handCount[nexplayer];
        cardEffect(adventurer, z, e, r, &GS, o, &s); //outpostPlayed should be 1
        if ((beforeNum) == GS.handCount[nexplayer]) {//should be same
                printf("Other player not effected by adventurer.\n");
        } else {
                #if (OUTPUT == 1)
                printf("ERROR: Other player's card count changed by adventurer.\n");
                printf("beforeNum is %d and after is %d.\n", beforeNum, GS.handCount[nexplayer]);
                #endif
        }
	
	// 4.	
	//Not state changes to Victory or Kingdom card piles
	memset(&GS, 23, sizeof(struct gameState)); //clear gamestate, if any
	//initializeGame resets the parameters
	initializeGame(numPlayer, kCards, seed, &GS);
	
	//similar to before we'll check the before and after piles
	//Victory
	int copper = GS.supplyCount[copper];
	int silver = GS.supplyCount[silver];
	int gold = GS.supplyCount[gold];
	int sumCoins = 0;
	sumCoins = copper + silver + gold;
	
	cardEffect(adventurer, z, e, r, &GS, o, &s); //outpostPlayed should be 1
	printf("Coins before adventurer: %d\n", sumCoins);
	printf("Coins after adventurer: %d\n", GS.supplyCount[copper]+
						GS.supplyCount[silver]+
						GS.supplyCount[gold]);
	
	return 0;
}
