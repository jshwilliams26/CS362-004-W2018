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
	int zeroCorrect = 0, zeroIncorrect = 0;
	int smithyCorrect = 0, smithyIncorrect = 0;
	int numhandcardsbefore = 0, numhandcardsafter = 0;

	int t;
	for (t = 0; t < 100000; t++) {
		numplayers = rand() % 5 + 1;
		handPos = rand() % 100;
		bonus = rand() % 100;
		
		memset(&teststate, '\0', sizeof(struct gameState));
    	
		initializeGame(numplayers, cards, 2000, &teststate);
		
		numhandcardsbefore = numHandCards(&teststate);
		cardEffect(smithy, choice1, choice2, choice3, &teststate, handPos, &bonus);
		numhandcardsafter = numHandCards(&teststate);
		endTurn(&teststate);
		
		//printf("%d\t%d\t%d\n", numplayers, numhandcardsbefore, numhandcardsafter);
		if ((numplayers < 2 || numplayers > 4) && numhandcardsbefore == 0 && numhandcardsafter <= numhandcardsbefore)
			zeroCorrect++;
		else if ((numplayers < 2 || numplayers > 4) && numhandcardsbefore == 0 && numhandcardsafter > numhandcardsbefore)
			zeroIncorrect++;
		else if ((numplayers < 5 || numplayers > 1) && numhandcardsbefore > 0 && numhandcardsafter == numhandcardsbefore+2)
			smithyCorrect++;
		else if ((numplayers < 5 || numplayers > 1) && numhandcardsbefore > 0 && numhandcardsafter != numhandcardsbefore+2)
			smithyIncorrect++;
	}
	
	printf("Since the smithy card adds 3 cards to the player's hand and then discards a card, the number of cards in a player's hand after playing the smithy card should be two more than before playing smithy.\n\n");
	printf("Invalid number of players (< 2 || > 4) and hand count not increased: %d times\n", zeroCorrect);
	printf("Invalid number of players (< 2 || > 4) and hand count increased: %d times\n", zeroIncorrect);
	printf("Valid number of players and hand count increased correctly: %d times\n", smithyCorrect);
	printf("Valid number of players and hand count increased incorrectly: %d times\n", smithyIncorrect);
	printf("All runs accounted for: %s\n\n", (zeroCorrect + zeroIncorrect + smithyCorrect + smithyIncorrect) == 100000 ? "True" : "False");

	return 0;
}