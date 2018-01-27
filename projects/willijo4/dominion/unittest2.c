//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for handCard function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int handCard(int handPos, struct gameState *state) {
	int currentPlayer = whoseTurn(state);
	return state->hand[currentPlayer][handPos];
}