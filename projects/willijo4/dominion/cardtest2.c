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

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int numplayers = 1;
	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		
	
	printf("\n*** Running smithy_func for 1 player ***\n");

	// Test with game state where none of the card are in the deck
	initializeGame(numplayers, cards, 2000, &teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 0 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 0 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == -1 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == -1 ? "True" : "False");
	endTurn(&teststate);

	printf("\n*** Running smithy_func for 2 players ***\n");

	// Test with game state where none of the card are in the deck
	numplayers = 2;	
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	
	printf("\n*** Running smithy_func for 3 players ***\n");

	// Test with game state where none of the card are in the deck
	numplayers = 3;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);


	printf("\n*** Running smithy_func for 4 players ***\n");

	// Test with game state where none of the card are in the deck
	numplayers = 4;
	memset(&teststate, '\0', sizeof(struct gameState));
	initializeGame(numplayers, cards, 2000, &teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);

	// There should be 3 more cards after the smithy card is drawn than before
	printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
	cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("Player %d's number of cards in hand == 8 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 8 ? "True" : "False");
	endTurn(&teststate);
	
	
	printf("\n");
	return 0;
}