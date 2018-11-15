#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkGardensFunction(int p) {
	//this function simply returns -1
	int test;
	test = gardensFunction();
	assert(p > test);
	return 0;
}

int main () {

	int n, p;

	printf("Testing Gardens card.\n");
	printf("The Gardens card's function is tested\n");
	printf("against random positive numbers.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    p = floor(Random());
    checkGardensFunction(p);
    
  }

  printf ("Garden card is working!\n");
  return 0;
}
