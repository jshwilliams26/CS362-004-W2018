//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for treasure map card
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


// Treasure Map function
/*int treasure_map_func(struct gameState *state, int currentPlayer, int handPos) {
	// search hand for another treasure_map
	int index = -1;

	int i;
	for (i = 0; i < state->handCount[currentPlayer]; i++) {
		if (state->hand[currentPlayer][i] == treasure_map && i != handPos) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		// trash both treasure cards
		discardCard(handPos, currentPlayer, state, 0);
		discardCard(index, currentPlayer, state, 0);

		// gain 4 Gold cards
		for (i = 0; i < 4; i++) {
			gainCard(gold, state, 1, currentPlayer);
		}

		// return success
		return 1;
	}

	//no second treasure_map found in hand
	return -1;
}*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
    int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	int cards[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};		

	int i, j;
	int numplayers = 2;
	memset(&teststate, '\0', sizeof(struct gameState));
	printf("\n*** Initializing game with 2 players ***\n");
	initializeGame(numplayers, cards, 2000, &teststate);
	printf("--- Showing the initial state of each player's hand and deck\n");
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
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	for (i = 0; i < teststate.numPlayers; i++) {
		for (j = 0; j < teststate.handCount[i]; j++) {
			teststate.hand[i][j] = estate;
		}
		for (j = 0; j < teststate.deckCount[i]; j++) {
			teststate.deck[i][j] = estate;
		}
	}

	printf("--- Results for 0 treasure cards in each player's deck\n");
	cardEffect(adventurer, choice1, choice2, choice3, &teststate, handPos, &bonus);
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}


	memset(&teststate, '\0', sizeof(struct gameState));
	printf("\n*** Reinitializing game with 2 players ***\n");
	initializeGame(numplayers, cards, 2000, &teststate);
	for (i = 0; i < teststate.numPlayers; i++) {
		for (j = 0; j < teststate.handCount[i]-1; j++) {
			teststate.hand[i][j] = estate;
		}
		teststate.hand[i][teststate.handCount[i]-2] = treasure_map;
		for (j = 0; j < teststate.deckCount[i]; j++) {
			teststate.deck[i][j] = estate;
		}
	}
	printf("--- Results for 1 treasure card in each player's deck\n");
	cardEffect(adventurer, choice1, choice2, choice3, &teststate, handPos, &bonus);
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}


	memset(&teststate, '\0', sizeof(struct gameState));
	printf("\n*** Reinitializing game with 2 players ***\n");
	initializeGame(numplayers, cards, 2000, &teststate);
	for (i = 0; i < teststate.numPlayers; i++) {
		for (j = 0; j < teststate.handCount[i]-2; j++) {
			teststate.hand[i][j] = estate;
		}
		teststate.hand[i][teststate.handCount[i]-3] = treasure_map;
		teststate.hand[i][teststate.handCount[i]-2] = treasure_map;
		for (j = 0; j < teststate.deckCount[i]; j++) {
			teststate.deck[i][j] = estate;
		}
	}
	printf("--- Results for 2 treasure cards in each player's deck\n");
	cardEffect(adventurer, choice1, choice2, choice3, &teststate, handPos, &bonus);
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	
	return 0;
}