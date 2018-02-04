//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for sea hag card
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
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

	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		
			
	int numplayers = 2;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, players, 2000, &teststate);
	cardEffect(sea_hag, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("\n*** Testing sea_hag_func with 2 players ***\n");
	
	/*
	Current player shouldn't have a curse on top of their deck, the
	other player should
	*/
	int i;
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("player: %d\tcard: %d\tcardCount: %d\n", i, curse, fullDeckCount(i, curse, &teststate));
		printf("player: %d\tcard: %d\tcardCount: %d\n", i, gold, fullDeckCount(i, gold, &teststate));
	}
	
	return 0;
}
