//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for smithy card
//****************************************************************
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// Function for the smithy card
/*int smithy_func(int currentPlayer, struct gameState *state, int handPos) {
	// +3 Cards
	int i;
	for (i = 0; i <= 3; i++) {
		drawCard(currentPlayer, state);
	}

	// discard card from hand
	discardCard(handPos, currentPlayer, state, 2);

	return 0;
}*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int numplayers = 2;
	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		
			
	// Test with game state where none of the card are in the deck
	initializeGame(numplayers, players, 2000, &teststate);

	//choice1 = 1;
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	//smithy_func(0, teststate, handPos);

	
	return 0;
}
