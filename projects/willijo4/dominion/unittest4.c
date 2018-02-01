//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for  function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	// Initialize gameState Struct
	struct gameState teststate;
	
	int numplayers = 2;
	int players[4] = {adventurer, smithy, sea_hag, minion};
	
	initializeGame(numplayers, players, 2000, &teststate);
	

	
	return 0;
}
