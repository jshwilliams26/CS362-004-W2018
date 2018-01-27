//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for isGameOver function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isGameOver(struct gameState *state) {
	int i;
	int j;

	//if stack of Province cards is empty, the game ends
	if (state->supplyCount[province] == 0)
	{
		return 1;
	}

	//if three supply pile are at 0, the game ends
	j = 0;
	for (i = 0; i < 25; i++)
	{
		if (state->supplyCount[i] == 0)
		{
			j++;
		}
	}
	if ( j >= 3)
	{
		return 1;
	}

	return 0;
}