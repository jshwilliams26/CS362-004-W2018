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
#include <assert.h>

/*int isGameOver(struct gameState *state) {
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
}*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
	
	int numplayers = 2;
	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};	
	initializeGame(numplayers, players, 2, &teststate);
	
	// Test with gamestate->supplyCount[province] == 0
	int i;
	for (i = 0; i < 25; i++) {
		printf("%d\n", teststate.supplyCount[i]);
	}
	printf("%d\n", isGameOver(&teststate));
	
	// Test with gamestate->supplyCount[province] != 0
	// Get j in the function to be greater than or equal to 3
	
	// Get j to be less than 3
	
	return 0;
}