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

	// Test with game state where none of the card are in the deck
	int numcardshandchange = 0, numcardszero = 0;

	int t, i;
	for (t = 0; t < 100000; t++) {
		numplayers = rand() % 5 + 1;
		handPos = rand() % 100 + -2;
		bonus = rand() % 100 + -2;
		int numhandcardsbefore = 0, numhandcardsafter = 0;
		
		memset(&teststate, '\0', sizeof(struct gameState));
    	
		initializeGame(numplayers, cards, 2000, &teststate);
		
		numhandcardsbefore = numHandCards(&teststate);
		cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
		numhandcardsafter = numHandCards(&teststate);
		endTurn(&teststate);
	}
	
	printf("Since the smithy card adds 3 cards to the player's hand and then discards a card, the number of cards in a player's hand after playing the smithy card should be two more than before playing smithy.\n\n");
	printf("Number of plays where number of cards in hand after playing smithy is 2 more than number of cards in hand before: %d\n", numcardshandchange);
	
	return 0;
}