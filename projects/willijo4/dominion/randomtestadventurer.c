//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 4
// Description: Random tester for adventurer card
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main() {
	srand(time(NULL));

	// Initialize gameState Struct
	struct gameState teststate;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		

	int j;
	int numplayers = 2;

	int treasureInDeckAndWorking = 0, treasureInDeckAndNOTWorking = 0, treasureNotInDeckBefore = 0, numTreasureOneWorking = 0, numTreasureOneNOTWorking = 0;

	int r;
	for (r = 0; r < 100000; r++) {
		memset(&teststate, '\0', sizeof(struct gameState));
		initializeGame(numplayers, cards, 2000, &teststate);

		// Setting all cards for first player to random cards
		for (j = 0; j < teststate.handCount[0]; j++)
			teststate.hand[0][j] = rand() % (27);
		for (j = 0; j < teststate.deckCount[0]; j++)
			teststate.deck[0][j] = rand() % (27);

		int treasurehandbefore = 0;
		for (j = 0; j < teststate.handCount[0]; j++)
			if (teststate.hand[0][j] == copper || teststate.hand[0][j] == silver || teststate.hand[0][j] == gold)
				treasurehandbefore++;
		
		int treasuredeckbefore = 0;
		for (j = 0; j < teststate.deckCount[0]; j++)
			if (teststate.deck[0][j] == copper || teststate.deck[0][j] == silver || teststate.deck[0][j] == gold)
				treasuredeckbefore++;
		
		// Random number of treasure cards
		cardEffect(adventurer, choice1, choice2, choice3, &teststate, handPos, &bonus);

		for (j = 0; j < teststate.handCount[0]; j++)
			teststate.hand[0][j] = rand() % (27);
		for (j = 0; j < teststate.deckCount[0]; j++)
			teststate.deck[0][j] = rand() % (27);

		int treasurehandafter = 0;
		for (j = 0; j < teststate.handCount[0]; j++)
			if (teststate.deck[0][j] == copper || teststate.deck[0][j] == silver || teststate.deck[0][j] == gold)
				treasurehandafter++;
		
		int treasuredeckafter = 0;
		for (j = 0; j < teststate.deckCount[0]; j++)
			if (teststate.deck[0][j] == copper || teststate.deck[0][j] == silver || teststate.deck[0][j] == gold)
				treasuredeckafter++;
		
		if (treasuredeckbefore >= 2 && (treasurehandafter - treasurehandbefore == treasuredeckbefore - treasuredeckafter))
			treasureInDeckAndWorking++;
		else if (treasuredeckbefore >= 2 && (treasurehandafter - treasurehandbefore != treasuredeckbefore - treasuredeckafter))
			treasureInDeckAndNOTWorking++;
		else if (treasuredeckbefore == 1 && (treasurehandafter - treasurehandbefore == treasuredeckbefore - treasuredeckafter))
			numTreasureOneWorking++;
		else if (treasuredeckbefore == 1 && (treasurehandafter - treasurehandbefore != treasuredeckbefore - treasuredeckafter))
			numTreasureOneNOTWorking++;
		else if (treasuredeckbefore == 0)
			treasureNotInDeckBefore++;
	}
	
	printf("> 1 treasure in deck and correct number of treasures deck -> hand: %d\n", treasureInDeckAndWorking);
	printf("> 1 treasure in deck and incorrect number of treasures deck -> hand: %d\n", treasureInDeckAndNOTWorking);
	printf("Just 1 treasure in deck and correct number of treasures deck -> hand: %d\n", numTreasureOneWorking);
	printf("Just 1 treasure in deck and incorrect number of treasures deck -> hand: %d\n", numTreasureOneNOTWorking);
	printf("No treasure cards in deck before playing adventure card: %d\n", treasureNotInDeckBefore);
	printf("All runs accounted for: %s\n\n", (treasureInDeckAndWorking + treasureInDeckAndNOTWorking + numTreasureOneWorking + numTreasureOneNOTWorking + treasureNotInDeckBefore) == 100000 ? "True" : "False");
		
	return 0;
}