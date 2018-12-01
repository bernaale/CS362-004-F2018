#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set OUPUT to 0 to stop test output
#define OUTPUT 1

int main() {
    
	printf ("\nTesting getCost():\n");  
	//array of costs as outlined in getCost with one error
	//value at the end if enum case not found
	int expectedCosts[] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4, /*case missing*/-1};
	//getCost compares the passed enum as an integer, 
	//therefore because the order of cards in getCost is
	//the same as in the enum CARD where they are defined, 
	//we can simply substitute their names for sequential
	//integers. This will allow us to use a for loop 
	//rather than typing every card name out.
	for (int i = 0; i < 28; i++) { //there are 27 enum values, the 28th is the null case
		if (getCost(i) == expectedCosts[i]) {
			#if (OUTPUT == 1)
			if (i != 27) {
				printf("The %dth enum from CARD had the correct cost.\n", i+1);
			} else {
				printf("The null case returns the correct value.\n");
			}
			#endif
		}
		else {
			if (i != 27) {
				printf("ERROR: The %dth enum from CARD had the wrong cost.\n", i+1);
			} else {
				printf("ERROR: The null case returns incorrect value.\n");
			}
		}
	}
	
	return 0;
}
