//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for fullDeckCount function
//****************************************************************
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*int fullDeckCount(int player, int card, struct gameState *state) {
	int i;
	int count = 0;

	for (i = 0; i < state->deckCount[player]; i++)
	{
		if (state->deck[player][i] == card) count++;
	}

	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == card) count++;
	}

	for (i = 0; i < state->discardCount[player]; i++)
	{
		if (state->discard[player][i] == card) count++;
	}

	return count;
}*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
	
	int numplayers = 2;
	int players[4] = {adventurer, smithy, sea_hag, minion};
	
	initializeGame(numplayers, players, 2000, &teststate);
	
	// Test with game state where none of the card are in the deck
	
	
	// Tests with game state where each player has the card
	
	
	// See if I can test each of the 3 for statements individually
	
	
	return 0;
}


