#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurerCard(int drawnTreasure, int currentPlayer,
			struct gameState *state, int* cardDrawn,
			int* temphand, int z) {
	int test;
	test = adventurerFunction(drawnTreasure, currentPlayer, state, cardDrawn, temphand, z);
	assert (test == 0); //adventurer should return 0
	return 0;
}

int main () {
	int i;
	struct gameState G;

	printf("Testing the Adventurer Card!\n");
	printf("These tests are randomly generated.\n");

	SelectStream(3);
	PutSeed(3);

	for (int x=0; x<3000; x++) {
		for (int y=0; y < sizeof(struct gameState); y++) {
			((char*)&G)[y] = floor(Random() * 256);
		}
		int treasure = 0;//floor(Random() * 2); //should give a number between 0 & 2
		
		int currentPlayer = 2;
		int cardDrawn[] = {1, 2, 3, 4, 5};
		int tempHand[] = {1, 2, 3, 4, 5};
		
		i = checkAdventurerCard(treasure, currentPlayer, &G, cardDrawn, tempHand, 0);
		assert(i == 0); //make sure the function worked as expected
	}

	printf("All the tests have passed.\n");
	return 0;
}
