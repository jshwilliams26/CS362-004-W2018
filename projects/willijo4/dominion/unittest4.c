//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for whoseTurn function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*
int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}
*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		
	
	printf("*** Testing whoseTurn 4X with 2 players ***\n");
	int numplayers = 2;	
	initializeGame(numplayers, players, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);

	printf("*** Testing whoseTurn 4X with 3 players ***\n");
	numplayers = 3;	
	initializeGame(numplayers, players, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 2: %s\n", whoseTurn(&teststate) == 2 ? "True" : "False");
	assert(whoseTurn(&teststate) == 2);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);

	printf("*** Testing whoseTurn 4X with 4 players ***\n");
	numplayers = 4;	
	initializeGame(numplayers, players, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 2: %s\n", whoseTurn(&teststate) == 2 ? "True" : "False");
	assert(whoseTurn(&teststate) == 2);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 3: %s\n\n", whoseTurn(&teststate) == 3 ? "True" : "False");
	assert(whoseTurn(&teststate) == 3);
	endTurn(&teststate);	
	return 0;
}
