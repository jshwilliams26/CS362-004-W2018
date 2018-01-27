//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for scoreFor function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int scoreFor (int player, struct gameState *state) {

	int i;
	int score = 0;
	//score from hand
	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == curse) { score = score - 1; };
		if (state->hand[player][i] == estate) { score = score + 1; };
		if (state->hand[player][i] == duchy) { score = score + 3; };
		if (state->hand[player][i] == province) { score = score + 6; };
		if (state->hand[player][i] == great_hall) { score = score + 1; };
		if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
	}

	//score from discard
	for (i = 0; i < state->discardCount[player]; i++)
	{
		if (state->discard[player][i] == curse) { score = score - 1; };
		if (state->discard[player][i] == estate) { score = score + 1; };
		if (state->discard[player][i] == duchy) { score = score + 3; };
		if (state->discard[player][i] == province) { score = score + 6; };
		if (state->discard[player][i] == great_hall) { score = score + 1; };
		if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
	}

	//score from deck
	for (i = 0; i < state->discardCount[player]; i++)
	{
		if (state->deck[player][i] == curse) { score = score - 1; };
		if (state->deck[player][i] == estate) { score = score + 1; };
		if (state->deck[player][i] == duchy) { score = score + 3; };
		if (state->deck[player][i] == province) { score = score + 6; };
		if (state->deck[player][i] == great_hall) { score = score + 1; };
		if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
	}

	return score;
}