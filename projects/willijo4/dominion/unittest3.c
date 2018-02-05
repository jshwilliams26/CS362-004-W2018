//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for isGameOver function
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
	
	int cards[10] = {adventurer, embargo, village, minion, province, cutpurse, sea_hag, tribute, smithy, council_room};	

	// When the number of players is 1, the supply count for any card should never increase
	// So the game should be over when the game is initialized with only 1 player
	printf("\n*** Game initialized with 1 player ***\n");
	int numplayers = 1;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");
	
	// Test gameOver after initialization with 2 players, shouldn't be over since no supply
	// piles should be at 0
	printf("\n*** Game initialized with 2 players ***\n");
	numplayers = 2;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("Game should not be over after initialization, no supply piles should be at 0\n");
	int i, j = 0;
	for (i = 0; i < 27; i++)
		if (teststate.supplyCount[i] == 0) j++;
	printf("Number of supply piles at 0: %d\n", j);
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");

	
	// Set the supply count of province to 0 and test again if the game is over
	printf("--- Province supply count set to 0 after initialization ---\n");
	teststate.supplyCount[province] = 0;
	j = 0;
	for (i = 0; i < 27; i++)
		if (teststate.supplyCount[i] == 0) j++;
	printf("Number of supply piles at 0: %d\n", j);
	printf("Province supply at 0: %s\n", teststate.supplyCount[province] == 0 ? "True" : "False");
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");

	// Reinitialize the game, then set the supply of 2 cards to 0, then 3 cards, and
	// determine if the game is over in each instance
	printf("\n*** Game reinitialized, game should not be over ***\n");
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	j = 0;
	for (i = 0; i < 27; i++)
		if (teststate.supplyCount[i] == 0) j++;
	printf("Number of supply piles at 0: %d\n", j);
	printf("Province supply at 0: %s\n", teststate.supplyCount[province] == 0 ? "True" : "False");
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");

	// Set supply of a card to 0
	printf("--- Supply count of cutpurse set to 0 ---\n");
	teststate.supplyCount[cutpurse] = 0;
	j = 0;
	for (i = 0; i < 27; i++)
		if (teststate.supplyCount[i] == 0) j++;
	printf("Number of supply piles at 0: %d\n", j);
	printf("Province supply at 0: %s\n", teststate.supplyCount[province] == 0 ? "True" : "False");
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");

	// Set supply of another card to 0
	printf("--- Supply count of village set to 0 ---\n");
	teststate.supplyCount[village] = 0;
	j = 0;
	for (i = 0; i < 27; i++)
		if (teststate.supplyCount[i] == 0) j++;
	printf("Number of supply piles at 0: %d\n", j);
	printf("Province supply at 0: %s\n", teststate.supplyCount[province] == 0 ? "True" : "False");
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");

	// Set supply of another card to 0
	printf("--- Supply count of treasure_map set to 0 ---\n");
	teststate.supplyCount[treasure_map] = 0;
	j = 0;
	for (i = 0; i < 27; i++)
		if (teststate.supplyCount[i] == 0) j++;
	printf("Number of supply piles at 0: %d\n", j);
	printf("Province supply at 0: %s\n", teststate.supplyCount[province] == 0 ? "True" : "False");
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");

	// Set supply of another card to 0
	printf("--- Supply count of tribute set to 0 ---\n");
	teststate.supplyCount[tribute] = 0;
	j = 0;
	for (i = 0; i < 27; i++)
		if (teststate.supplyCount[i] == 0) j++;
	printf("Number of supply piles at 0: %d\n", j);
	printf("Province supply at 0: %s\n", teststate.supplyCount[province] == 0 ? "True" : "False");
	printf("Game is over: %s\n", isGameOver(&teststate) == 1 ? "True" : "False");
	
	printf("\n");
	
	return 0;
}