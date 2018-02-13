//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 4
// Description: Random tester for sea_hag card
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
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		
			
	int numplayers = 2;
	memset(&teststate, '\0', sizeof(struct gameState));
	printf("\n*** Initializing game with 2 players ***\n");
	initializeGame(numplayers, cards, 2000, &teststate);

	int i;
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", whoseTurn(&teststate));
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for curse card is greater than 0: %s\n", i, fullDeckCount(i, curse, &teststate) > 0 ? "True" : "False");
		printf("Card count for player %d for gold card is greater than 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
	}
	
	cardEffect(sea_hag, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("\n*** Testing sea_hag_func with 2 players ***\n");
	
	/*
	Current player shouldn't have a curse on top of their deck, the
	other player should
	*/
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", whoseTurn(&teststate));
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for curse card is greater than 0: %s\n", i, fullDeckCount(i, curse, &teststate) > 0 ? "True" : "False");
		printf("Card count for player %d for gold card is greater than 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
	}
	
	return 0;
}