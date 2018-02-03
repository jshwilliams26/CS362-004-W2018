//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for adventurer card
//****************************************************************
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// Function for the Adventurer card
int adventurer_func(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int *temphand) {
	int z = 0;
	
	while (drawntreasure < 1) {
		//if the deck is empty we need to shuffle discard and add to deck
		if (state->deckCount[currentPlayer] < 1) {
			shuffle(currentPlayer, state);
		}

		drawCard(currentPlayer, state);

		//top card of hand is most recently drawn card.
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];

		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}

	while (z - 1 > 0) {
		// discard all cards in play that have been drawn
		state->discard[currentPlayer][++state->discardCount[currentPlayer]] = temphand[z-1];
		z=z-1;
	}

	return 0;
}