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

/*
Set up

test with 1 - 4 players
Set random cards in hand and deck to random numbers (0-26)
Test different hand pos

*/


int main() {
	srand(time(NULL));

	// Initialize gameState Struct
	struct gameState teststate;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		

	int i, j;
	int numplayers = 2;

	int r;
	for (r = 0; r < 10000; r++) {
		memset(&teststate, '\0', sizeof(struct gameState));
		printf("\n*** Initializing game with 2 players ***\n");
		initializeGame(numplayers, cards, 2000, &teststate);
		//printf("--- Showing the initial state of each player's hand and deck\n");

		int handBefore = 0, deckBefore = 0, handAfter = 0, deckAfter = 0, treasureBefore = 0, treasureAfter = 0;

		// Setting all cards for both players to estate before starting
		printf("--- Setting all cards in each player's hand to random cards\n");
		for (i = 0; i < teststate.numPlayers; i++) {
			for (j = 0; j < teststate.handCount[i]; j++) {
				teststate.hand[i][j] = (rand() % (26 + 1 - 0)) + 0;
			}
			for (j = 0; j < teststate.deckCount[i]; j++) {
				teststate.deck[i][j] = (rand() % (26 + 1 - 0)) + 0;
			}
		}
		for (i = 0; i < teststate.numPlayers; i++) {
			printf("Current player: %d\n", i);
			printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
			printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
			int treasurehandcount = 0;
			for (j = 0; j < teststate.handCount[i]; j++) {
				if (teststate.hand[i][j] == copper || teststate.hand[i][j] == silver || teststate.hand[i][j] == gold) {
					treasurehandcount++;
				}
			}
			printf("Treasure cards in hand for player %d: %d\n", i, treasurehandcount);
			int treasuredeckcount = 0;
			for (j = 0; j < teststate.deckCount[i]; j++) {
				if (teststate.deck[i][j] == copper || teststate.deck[i][j] == silver || teststate.deck[i][j] == gold) {
					treasuredeckcount++;
				}
			}
			printf("Treasure cards in deck for player %d: %d\n", i, treasuredeckcount);
		}
		// Random number of treasure cards
		printf("--- Playing the adventurer card\n");
		cardEffect(adventurer, choice1, choice2, choice3, &teststate, handPos, &bonus);
		for (i = 0; i < teststate.numPlayers; i++) {
			printf("Current player: %d\n", i);
			printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
			printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
			int treasurehandcount = 0;
			for (j = 0; j < teststate.handCount[i]; j++) {
				if (teststate.hand[i][j] == copper || teststate.hand[i][j] == silver || teststate.hand[i][j] == gold) {
					treasurehandcount++;
				}
			}
			printf("Treasure cards in hand for player %d: %d\n", i, treasurehandcount);
			int treasuredeckcount = 0;
			for (j = 0; j < teststate.deckCount[i]; j++) {
				if (teststate.deck[i][j] == copper || teststate.deck[i][j] == silver || teststate.deck[i][j] == gold) {
					treasuredeckcount++;
				}
			}
			printf("Treasure cards in deck for player %d: %d\n", i, treasuredeckcount);
		}
	}
		
	return 0;
}