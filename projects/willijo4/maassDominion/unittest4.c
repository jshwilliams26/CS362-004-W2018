//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for whoseTurn function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		

	printf("\n*** Testing whoseTurn 5X with 1 player ***\n");
	int numplayers = 1;	
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
		
	printf("*** Testing whoseTurn 5X with 2 players ***\n");
	numplayers = 2;	
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);

	printf("*** Testing whoseTurn 5X with 3 players ***\n");
	numplayers = 3;	
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 2: %s\n", whoseTurn(&teststate) == 2 ? "True" : "False");
	assert(whoseTurn(&teststate) == 2);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);

	printf("*** Testing whoseTurn 5X with 4 players ***\n");
	numplayers = 4;	
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 1: %s\n", whoseTurn(&teststate) == 1 ? "True" : "False");
	assert(whoseTurn(&teststate) == 1);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 2: %s\n", whoseTurn(&teststate) == 2 ? "True" : "False");
	assert(whoseTurn(&teststate) == 2);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 3: %s\n", whoseTurn(&teststate) == 3 ? "True" : "False");
	assert(whoseTurn(&teststate) == 3);
	endTurn(&teststate);	
	printf("whoseTurn(teststate) == 0: %s\n\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);

	printf("*** Testing whoseTurn 5X with 5 players ***\n");
	numplayers = 5;	
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);
	printf("whoseTurn(teststate) == 0: %s\n", whoseTurn(&teststate) == 0 ? "True" : "False");
	assert(whoseTurn(&teststate) == 0);
	endTurn(&teststate);

	return 0;
}

