//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for treasure map card
//****************************************************************
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


// Treasure Map function
int treasure_map_func(struct gameState *state, int currentPlayer, int handPos) {
	// search hand for another treasure_map
	int index = -1;

	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++) {
		if (state->hand[currentPlayer][i] == treasure_map && i != handPos) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		// trash both treasure cards
		discardCard(handPos, currentPlayer, state, 0);
		discardCard(index, currentPlayer, state, 0);

		// gain 4 Gold cards
		for (i = 0; i < 4; i++) {
			gainCard(gold, state, 1, currentPlayer);
		}

		// return success
		return 1;
	}

	//no second treasure_map found in hand
	return -1;
}