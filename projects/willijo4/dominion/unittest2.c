//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for supplyCount function
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
	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		

	printf ("\n*** Testing supplyCount after initialization with 1 player ***\n");
	int numplayers = 1;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, players, 2000, &teststate);
	printf("Supply counts for estate, duchy, province, and curse should be 0\n");
	assert(supplyCount(estate, &teststate) == 0 && supplyCount(duchy, &teststate) == 0 && supplyCount(province, &teststate) == 0 && supplyCount(curse, &teststate) == 0);
	printf("Supply count for estate = 0: %s\n", supplyCount(estate, &teststate) == 0 ? "True" : "False");
	printf("Supply count for estate = 0: %s\n", supplyCount(duchy, &teststate) == 0 ? "True" : "False");
	printf("Supply count for estate = 0: %s\n", supplyCount(province, &teststate) == 0 ? "True" : "False");
	printf("Supply count for curse = 0: %s\n\n", supplyCount(curse, &teststate) == 0 ? "True" : "False");

	printf ("*** Testing supplyCount after initialization with 2 players ***\n");
	numplayers = 2;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, players, 2000, &teststate);
	printf("Supply counts for estate, duchy, and province should be 8, and curse should be 10\n");
	assert(supplyCount(estate, &teststate) == 8 && supplyCount(duchy, &teststate) == 8 && supplyCount(province, &teststate) == 8 && supplyCount(curse, &teststate) == 10);
	printf("Supply count for estate = 8: %s\n", supplyCount(estate, &teststate) == 8 ? "True" : "False");
	printf("Supply count for estate = 8: %s\n", supplyCount(duchy, &teststate) == 8 ? "True" : "False");
	printf("Supply count for estate = 8: %s\n", supplyCount(province, &teststate) == 8 ? "True" : "False");
	printf("Supply count for curse = 10: %s\n\n", supplyCount(curse, &teststate) == 10 ? "True" : "False");
	
	printf ("*** Testing supplyCount after initialization with 3 players ***\n");
	numplayers = 3;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, players, 2000, &teststate);
	printf("Supply counts for estate, duchy, and province should be 12, and curse should be 20\n");
	assert(supplyCount(estate, &teststate) == 12 && supplyCount(duchy, &teststate) == 12 && supplyCount(province, &teststate) == 12 && supplyCount(curse, &teststate) == 20);
	printf("Supply count for estate = 12: %s\n", supplyCount(estate, &teststate) == 12 ? "True" : "False");
	printf("Supply count for estate = 12: %s\n", supplyCount(duchy, &teststate) == 12 ? "True" : "False");
	printf("Supply count for estate = 12: %s\n", supplyCount(province, &teststate) == 12 ? "True" : "False");
	printf("Supply count for curse = 20: %s\n\n", supplyCount(curse, &teststate) == 20 ? "True" : "False");

	printf ("*** Testing supplyCount after initialization with 4 players ***\n");
	numplayers = 4;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, players, 2000, &teststate);
	printf("Supply counts for estate, duchy, and province should be 12, and curse should be 30\n");
	assert(supplyCount(estate, &teststate) == 12 && supplyCount(duchy, &teststate) == 12 && supplyCount(province, &teststate) == 12 && supplyCount(curse, &teststate) == 30);
	printf("Supply count for estate = 12: %s\n", supplyCount(estate, &teststate) == 12 ? "True" : "False");
	printf("Supply count for estate = 12: %s\n", supplyCount(duchy, &teststate) == 12 ? "True" : "False");
	printf("Supply count for estate = 12: %s\n", supplyCount(province, &teststate) == 12 ? "True" : "False");
	printf("Supply count for curse = 30: %s\n\n", supplyCount(curse, &teststate) == 30 ? "True" : "False");

	printf ("*** Testing supplyCount after initialization with 5 players ***\n");
	memset(&teststate, '\0', sizeof(struct gameState));
	numplayers = 5;
	initializeGame(numplayers, players, 2000, &teststate);
	printf("Supply counts for estate, duchy, province, and curse should be 0\n");
	assert(supplyCount(estate, &teststate) == 0 && supplyCount(duchy, &teststate) == 0 && supplyCount(province, &teststate) == 0 && supplyCount(curse, &teststate) == 0);
	printf("Supply count for estate = 0: %s\n", supplyCount(estate, &teststate) == 0 ? "True" : "False");
	printf("Supply count for estate = 0: %s\n", supplyCount(duchy, &teststate) == 0 ? "True" : "False");
	printf("Supply count for estate = 0: %s\n", supplyCount(province, &teststate) == 0 ? "True" : "False");
	printf("Supply count for curse = 0: %s\n\n", supplyCount(curse, &teststate) == 0 ? "True" : "False");

	return 0;
}
