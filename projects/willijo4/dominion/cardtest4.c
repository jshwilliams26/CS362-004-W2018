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
		printf("Card count for player %d for gold > 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
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

	printf("\n--- Results for 0 treasure cards in each player's deck before calling treasure_map_func\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold > 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	cardEffect(treasure_map, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("--- Results for 0 treasure cards in each player's deck after calling treasure_map_func\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold > 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
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
	printf("\n--- Results for 1 treasure card in each player's deck before calling treasure_map_func\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold > 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	cardEffect(treasure_map, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("--- Results for 1 treasure card in each player's deck after calling treasure_map_func\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold > 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
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
	printf("\n--- Results for 2 treasure cards in each player's deck before calling treasure_map_func\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold > 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	cardEffect(treasure_map, choice1, choice2, choice3, &teststate, handPos, &bonus);
	printf("--- Results for 2 treasure cards in each player's deck after calling treasure_map_func\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		printf("Current player: %d\n", i);
		printf("Hand count for player %d: %d\n", i, teststate.handCount[i]);
		printf("Deck count for player %d: %d\n", i, teststate.deckCount[i]);
		printf("Card count for player %d for treasure_map: %d\n", i, fullDeckCount(i, treasure_map, &teststate));
		printf("Card count for player %d for gold > 0: %s\n", i, fullDeckCount(i, gold, &teststate) > 0 ? "True" : "False");
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	
	return 0;
}
