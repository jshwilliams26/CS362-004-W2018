//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for fullDeckCount function
//****************************************************************
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/*int fullDeckCount(int player, int card, struct gameState *state) {
	int i;
	int count = 0;

	for (i = 0; i < state->deckCount[player]; i++)
	{
		if (state->deck[player][i] == card) count++;
	}

	for (i = 0; i < state->handCount[player]; i++)
	{
		if (state->hand[player][i] == card) count++;
	}

	for (i = 0; i < state->discardCount[player]; i++)
	{
		if (state->discard[player][i] == card) count++;
	}

	return count;
}*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;

	int numplayers = 2;
	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		
			
	// Test with game state where none of the card are in the deck
	initializeGame(numplayers, players, 2000, &teststate);
	int i, j;
	for (i = 0; i < numplayers; i++) {
		printf("Player %d cards: \n", i);
		printf("Player %d's deck count: %d\n", i, teststate.deckCount[i]);
		printf("Player %d's hand count: %d\n", i, teststate.handCount[i]);
		printf("Player %d's discard count: %d\n", i, teststate.discardCount[i]);
		/*for (j = 0; j < 25; j++) {
			printf("*****\n");
			printf("%d: %d\n", j, teststate.deck[i][j]);
			printf("%d: %d\n", j, teststate.hand[i][j]);
			printf("%d: %d\n", j, teststate.discard[i][j]);
		}*/
		printf("\n\n");
	}
	printf("%d\n\n", fullDeckCount(0, 0, &teststate));
	drawCard(0, teststate);
	discardCard(0, 0, teststate, 1);
	
	// Tests with game state where each player has the card
	/*for (i = 0; i < numplayers; i++) {
		printf("Player %d cards: \n", i);
		printf("Player %d's deck count: %d\n", i, teststate.deckCount[i]);
		printf("Player %d's hand count: %d\n", i, teststate.handCount[i]);
		printf("Player %d's discard count: %d\n", i, teststate.discardCount[i]);
		for (j = 0; j < 25; j++) {
			printf("*****\n");
			printf("%d: %d\n", j, teststate.deck[i][j]);
			printf("%d: %d\n", j, teststate.hand[i][j]);
			printf("%d: %d\n", j, teststate.discard[i][j]);
		}
		printf("\n\n");
	}
	printf("%d\n\n", fullDeckCount(0, 0, &teststate));*/
	
	
	// See if I can test each of the 3 for statements individually
	
	
	return 0;
}


