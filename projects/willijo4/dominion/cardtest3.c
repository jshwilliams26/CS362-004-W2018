//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for sea hag card
//****************************************************************
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// Sea Hag function
/*int sea_hag_func(struct gameState *state, int currentPlayer) {
	int i;
	for (i = 0; i < state->numPlayers; i++) {
		if (i != currentPlayer){
			state->discard[i][state->discardCount[i]] = state->deck[i][--state->deckCount[i]];
			--state->deckCount[i];
			++state->discardCount[i];

			// Top card now a curse
			state->deck[i][--state->deckCount[i]] = gold;
		}
	}

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

	choice1 = 1;
	cardEffect(sea_hag, choice1, choice2, choice3, &teststate, handPos, &bonus);
	//smithy_func(0, teststate, handPos);
	choice1 = 0;
	choice2 = 1;
	cardEffect(sea_hag, choice1, choice2, choice3, &teststate, handPos, &bonus);

	choice2 = 0;
	choice3 = 1;
	cardEffect(sea_hag, choice1, choice2, choice3, &teststate, handPos, &bonus);

	
	return 0;
}
