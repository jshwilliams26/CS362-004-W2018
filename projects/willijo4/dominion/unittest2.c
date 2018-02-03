//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for supplyCount function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		

	printf ("*** Testing supplyCount after initialization with 2 players ***\n");
	int numplayers = 2;
	initializeGame(numplayers, players, 2000, &teststate);
	printf("Supply counts for estate, duchy, and province should be 8\n");
	assert(supplyCount(estate, &teststate) == 8 && supplyCount(duchy, &teststate) == 8 && supplyCount(province, &teststate) == 8);
	printf("Supply count for estate = 8: %s\n", supplyCount(estate, &teststate) == 8 ? "True" : "False");
	printf("Supply count for estate = 8: %s\n", supplyCount(duchy, &teststate) == 8 ? "True" : "False");
	printf("Supply count for estate = 8: %s\n\n", supplyCount(province, &teststate) == 8 ? "True" : "False");
	
	printf ("*** Testing supplyCount after initialization with 3 players ***\n");
	numplayers = 3;
	initializeGame(numplayers, players, 2000, &teststate);
	printf("Supply counts for estate, duchy, and province should be 12\n");
	assert(supplyCount(estate, &teststate) == 12 && supplyCount(duchy, &teststate) == 12 && supplyCount(province, &teststate) == 12);
	printf("Supply count for estate = 12: %s\n", supplyCount(estate, &teststate) == 12 ? "True" : "False");
	printf("Supply count for estate = 12: %s\n", supplyCount(duchy, &teststate) == 12 ? "True" : "False");
	printf("Supply count for estate = 12: %s\n\n", supplyCount(province, &teststate) == 12 ? "True" : "False");

	return 0;
}
