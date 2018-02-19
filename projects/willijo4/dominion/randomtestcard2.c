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
			
	int numplayers = 4;
	int cursesBefore[4], cursesAfter[4];
	int deckBefore[4], deckAfter[4];
	int giverCorrect = 0, giverIncorrect = 0, receiversCorrect = 0, receiversIncorrect = 0;

	int i, r, j;
	for (r = 0; r < 100000; r++) {
		memset(&teststate, '\0', sizeof(struct gameState));
		initializeGame(numplayers, cards, 2000, &teststate);

		for (i = 0; i < teststate.numPlayers; i++) {
			for (j = 0; j < teststate.handCount[i]; j++)
				teststate.hand[i][j] = (rand() % (26 + 1 - 0)) + 0;
			for (j = 0; j < teststate.deckCount[i]; j++)
				teststate.deck[i][j] = (rand() % (26 + 1 - 0)) + 0;
		}
		
		for (i = 0; i < teststate.numPlayers; i++) {
			deckBefore[i] = teststate.deckCount[i];
			cursesBefore[i] = fullDeckCount(i, curse, &teststate);
			//endTurn(&teststate);
		}
	
		cardEffect(sea_hag, choice1, choice2, choice3, &teststate, handPos, &bonus);
		
		for (i = 0; i < teststate.numPlayers; i++) {
			deckAfter[i] = teststate.deckCount[i];
			cursesAfter[i] = fullDeckCount(i, curse, &teststate);
			//endTurn(&teststate);
		}
		
		int numReceivers = 0;
		for (i = 0; i < teststate.numPlayers; i++) {
			if (i == whoseTurn(&teststate)) {
				if (cursesBefore[i] == cursesAfter[i] && deckBefore[i] == deckAfter[i])
					giverCorrect++;
				else
					giverIncorrect++;
			} else {
				if (cursesBefore[i]+1 == cursesAfter[i] && deckBefore[i] == deckAfter[i])
					numReceivers++;
			}
		}
		
		if (numReceivers == 3)
			receiversCorrect++;
		else
			receiversIncorrect++;
	}

	printf("Sea hag player doesn't gain curse cards and deck count stays same: %d times\n", giverCorrect);
	printf("Sea hag player gains curse cards or deck count changes: %d times\n", giverIncorrect);
	printf("All runs accounted for: %s\n\n", (giverCorrect + giverIncorrect) == 100000 ? "True" : "False");

	printf("Other players gain curse cards and deck count stays same: %d times\n", receiversCorrect);
	printf("Other players gain curse cards or deck count changes: %d times\n", receiversIncorrect);
	printf("All runs accounted for: %s\n\n", (receiversCorrect + receiversIncorrect) == 100000 ? "True" : "False");
		
	return 0;
}