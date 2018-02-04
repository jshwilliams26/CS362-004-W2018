//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for smithy card
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// Function for the smithy card
/*int smithy_func(int currentPlayer, struct gameState *state, int handPos) {
	// +3 Cards
	int i;
	for (i = 0; i <= 3; i++) {
		drawCard(currentPlayer, state);
	}

	// discard card from hand
	discardCard(handPos, currentPlayer, state, 2);

	return 0;
}*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int numplayers = 1;
	int players[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		
	
	printf("\n*** Running smithy_func for 2 players ***\n");

	// Test with game state where none of the card are in the deck
	initializeGame(numplayers, players, 2000, &teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %d\n", whoseTurn(&teststate), numHandCards(&teststate));
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 before smithy_func: %d\n", whoseTurn(&teststate), numHandCards(&teststate));
	endTurn(&teststate);

	printf("\n*** Running smithy_func for 2 players ***\n");

	// Test with game state where none of the card are in the deck
	numplayers = 2;	
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, players, 2000, &teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	
	printf("\n*** Running smithy_func for 3 players ***\n");

	// Test with game state where none of the card are in the deck
	numplayers = 3;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, players, 2000, &teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);
	
	printf("\n");
	return 0;
}