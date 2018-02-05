//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for adventurer card
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
		printf("Treasure cards in hand for player %d: %d\n", i, treasurehandcount);
		printf("Card count for player %d for copper: %d\n", i, fullDeckCount(i, copper, &teststate));
		printf("Card count for player %d for silver: %d\n", i, fullDeckCount(i, silver, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	// Setting all cards for both players to estate before starting
	printf("--- Setting all cards in each player's hand and deck to estate\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		for (j = 0; j < teststate.handCount[i]; j++) {
			teststate.hand[i][j] = estate;
		}
		for (j = 0; j < teststate.deckCount[i]; j++) {
			teststate.deck[i][j] = estate;
		}
	}

	// drawntreasure will always == 0, since the function will always be passes
	// a value of 0 for this function
	// For player 1 (0), modify the cards, such that there are 0, 1, and 2
	// treasure cards in their deck, and display cards in deck for each scenario
	// The treasure cards should go to the hand when there are 2
	
	// 0 treasure cards
	printf("--- Results for 0 treasure cards in each player's deck\n");
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
		printf("Treasure cards in hand for player %d == 0: %s\n", i, treasurehandcount == 0 ? "True" : "False");
		printf("Card count for player %d for copper: %d\n", i, fullDeckCount(i, copper, &teststate));
		printf("Card count for player %d for silver: %d\n", i, fullDeckCount(i, silver, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	
		
	// 1 treasure card
	memset(&teststate, '\0', sizeof(struct gameState));
	printf("\n*** Reinitializing game with 2 players ***\n");
	initializeGame(numplayers, cards, 2000, &teststate);
	// Setting all cards for both players to estate before starting
	printf("--- Setting all cards in each player's hand and deck to estate and 1 copper card\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		for (j = 0; j < teststate.handCount[i]; j++) {
			teststate.hand[i][j] = estate;
		}
		for (j = 0; j < teststate.deckCount[i]-1; j++) {
			teststate.deck[i][j] = estate;
		}
		teststate.deck[i][teststate.deckCount[i]-2] = copper;
	}
	printf("--- Results for 1 treasure card in each player's deck\n");
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
		printf("Treasure cards in hand for player %d == 1: %s\n", i, treasurehandcount == 1 ? "True" : "False");
		printf("Card count for player %d for copper: %d\n", i, fullDeckCount(i, copper, &teststate));
		printf("Card count for player %d for silver: %d\n", i, fullDeckCount(i, silver, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
	
	
	
	// 2 treasure cards
	memset(&teststate, '\0', sizeof(struct gameState));
	printf("\n*** Reinitializing game with 2 players ***\n");
	initializeGame(numplayers, cards, 2000, &teststate);
	// Setting all cards for both players to estate before starting
	printf("--- Setting all cards in each player's hand and deck to estate and 2 copper cards\n");
	for (i = 0; i < teststate.numPlayers; i++) {
		for (j = 0; j < teststate.handCount[i]; j++) {
			teststate.hand[i][j] = estate;
		}
		for (j = 0; j < teststate.deckCount[i]-2; j++) {
			teststate.deck[i][j] = estate;
		}
		teststate.deck[i][teststate.deckCount[i]-3] = copper;
		teststate.deck[i][teststate.deckCount[i]-2] = copper;
	}
	printf("--- Results for 2 treasure cards in each player's deck\n");
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
		printf("Treasure cards in hand for player %d == 2: %s\n", i, treasurehandcount == 2 ? "True" : "False");
		printf("Card count for player %d for copper: %d\n", i, fullDeckCount(i, copper, &teststate));
		printf("Card count for player %d for silver: %d\n", i, fullDeckCount(i, silver, &teststate));
		printf("Card count for player %d for gold: %d\n", i, fullDeckCount(i, gold, &teststate));
		printf("Card count for player %d for estate: %d\n", i, fullDeckCount(i, estate, &teststate));
	}
			
		
	return 0;
}