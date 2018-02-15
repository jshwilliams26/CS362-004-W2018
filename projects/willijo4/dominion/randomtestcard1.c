//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 4
// Description: Random tester for smithy card
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	srand(time(NULL));

	// Initialize gameState Struct
	struct gameState teststate;
	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int numplayers = 2;
	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	printf("\n*** Running smithy_func for 2 players ***\n");

	// Test with game state where none of the card are in the deck
	numplayers = 2;
	int numHand5before = 0, numHandNot5before = 0, numHand7after = 0, numHandNot7after = 0;

	int t;
	for (t = 0; t < 10000; t++) {
		handPos = rand() % 100 + -2;
		memset(&teststate, '\0', sizeof(struct gameState));
		initializeGame(numplayers, cards, 2000, &teststate);
		
		// There should be 3 more cards after the smithy card is drawn than before
		printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
		if (numHandCards(&teststate) == 5) numHand5before++;
		else numHandNot5before++;
		cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
		printf("Player %d's number of cards in hand == 7 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 7 ? "True" : "False");			endTurn(&teststate);
		if (numHandCards(&teststate) == 7) numHand7after++;
		else numHandNot7after++;
		
		// There should be 3 more cards after the smithy card is drawn than before
		printf("Player %d's number of cards in hand == 5 before smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 5 ? "True" : "False");
		if (numHandCards(&teststate) == 5) numHand5before++;
		else numHandNot5before++;
		cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
		printf("Player %d's number of cards in hand == 7 after smithy_func: %s\n", whoseTurn(&teststate), numHandCards(&teststate) == 7 ? "True" : "False");			endTurn(&teststate);
		endTurn(&teststate);
		if (numHandCards(&teststate) == 7) numHand7after++;
		else numHandNot7after++;
	}
	
	printf("%d\t%d\t%d\t%d\n", numHand5before, numHandNot5before, numHand7after, numHandNot7after);
	
	return 0;
}