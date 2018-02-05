//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for fullDeckCount function
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
	
	// Test with 1 player, the returned count should be 0
	printf("*** Testing with 1 player and summing number of cards for all cards,\n*** this should be equal to 0 ***\n");
	int numplayers = 1;
	initializeGame(numplayers, cards, 2000, &teststate);
	int i, totalcards = 0;
	for (i = 0; i < 25; i++) {
		totalcards += fullDeckCount(0, i, &teststate);
	}
	printf("Full deck count for player %d is 0: %s\n", whoseTurn(&teststate), totalcards == 0 ? "True": "False");
		
	// Test with game state where none of the card are in the deck
	printf("\n*** Initializing with 2 players, will run fullDeckCount for cards 1 and 4 ***\n");
	numplayers = 2;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);
	for (i = 0; i < numplayers; i++) {
		printf("Full deck count for player %d for card %d is 3: %s\n", i, 1, fullDeckCount(i, 1, &teststate) == 3 ? "True" : "False");
		printf("Full deck count for player %d for card %d is 7: %s\n", i, 4, fullDeckCount(i, 4, &teststate) == 7 ? "True" : "False");
		printf("Deck count for player %d is 5: %s\n", i, teststate.deckCount[i] == 5 ? "True" : "False");
		printf("Hand count for player %d is 5: %s\n", i, teststate.handCount[i] == 5 ? "True" : "False");
		endTurn(&teststate);
	}
	printf("*** Drawing a card for each player ***\n");
	for (i = 0; i < numplayers; i++) {
		drawCard(i, &teststate);
		printf("Full deck count for player %d for card %d is 3: %s\n", i, 1, fullDeckCount(i, 1, &teststate) == 3 ? "True" : "False");
		printf("Full deck count for player %d for card %d is 7: %s\n", i, 4, fullDeckCount(i, 4, &teststate) == 7 ? "True" : "False");
		printf("Deck count for player %d is 4: %s\n", i, teststate.deckCount[i] == 4 ? "True" : "False");
		printf("Hand count for player %d is 6: %s\n", i, teststate.handCount[i] == 6 ? "True" : "False");
		endTurn(&teststate);
	}
	printf("*** Discarding a card for each player ***\n");
	for (i = 0; i < numplayers; i++) {
		discardCard(teststate.handCount[i], i, &teststate, 0);
		printf("Deck count for player %d is 5: %s\n", i, teststate.deckCount[i] == 5 ? "True" : "False");
		printf("Hand count for player %d is 4: %s\n", i, teststate.handCount[i] == 4 ? "True" : "False");
		endTurn(&teststate);
	}
	
	printf("\n");
	
	return 0;
}


