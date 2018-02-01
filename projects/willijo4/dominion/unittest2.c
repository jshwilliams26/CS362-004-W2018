//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for handCard function
//****************************************************************
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed,
		struct gameState *state) {

	int i;
	int j;
	int it;			
	//set up random number generator
	SelectStream(1);
	PutSeed((long)randomSeed);

	//check number of players
	if (numPlayers > MAX_PLAYERS || numPlayers < 2)
	{
		return -1;
	}

	//set number of players
	state->numPlayers = numPlayers;

	//check selected kingdom cards are different
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j != i && kingdomCards[j] == kingdomCards[i])
			{
				return -1;
			}
		}
	}


	//initialize supply
	///////////////////////////////

	//set number of Curse cards
	if (numPlayers == 2)
	{
		state->supplyCount[curse] = 10;
	}
	else if (numPlayers == 3)
	{
		state->supplyCount[curse] = 20;
	}
	else
	{
		state->supplyCount[curse] = 30;
	}

	//set number of Victory cards
	if (numPlayers == 2)
	{
		state->supplyCount[estate] = 8;
		state->supplyCount[duchy] = 8;
		state->supplyCount[province] = 8;
	}
	else
	{
		state->supplyCount[estate] = 12;
		state->supplyCount[duchy] = 12;
		state->supplyCount[province] = 12;
	}

	//set number of Treasure cards
	state->supplyCount[copper] = 60 - (7 * numPlayers);
	state->supplyCount[silver] = 40;
	state->supplyCount[gold] = 30;

	//set number of Kingdom cards
	for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
	{
		for (j = 0; j < 10; j++)           		//loop chosen cards
		{
			if (kingdomCards[j] == i)
			{
				//check if card is a 'Victory' Kingdom card
				if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
				{
					if (numPlayers == 2){ 
						state->supplyCount[i] = 8; 
					}
					else{ state->supplyCount[i] = 12; }
				}
				else
				{
					state->supplyCount[i] = 10;
				}
				break;
			}
			else    //card is not in the set choosen for the game
			{
				state->supplyCount[i] = -1;
			}
		}

	}

	////////////////////////
	//supply intilization complete

	//set player decks
	for (i = 0; i < numPlayers; i++)
	{
		state->deckCount[i] = 0;
		for (j = 0; j < 3; j++)
		{
			state->deck[i][j] = estate;
			state->deckCount[i]++;
		}
		for (j = 3; j < 10; j++)
		{
			state->deck[i][j] = copper;
			state->deckCount[i]++;		
		}
	}

	//shuffle player decks
	for (i = 0; i < numPlayers; i++)
	{
		if ( shuffle(i, state) < 0 )
		{
			return -1;
		}
	}

	//draw player hands
	for (i = 0; i < numPlayers; i++)
	{  
		//initialize hand size to zero
		state->handCount[i] = 0;
		state->discardCount[i] = 0;
		//draw 5 cards
		// for (j = 0; j < 5; j++)
		//	{
		//	  drawCard(i, state);
		//	}
	}

	//set embargo tokens to 0 for all supply piles
	for (i = 0; i <= treasure_map; i++)
	{
		state->embargoTokens[i] = 0;
	}

	//initialize first player's turn
	state->outpostPlayed = 0;
	state->phase = 0;
	state->numActions = 1;
	state->numBuys = 1;
	state->playedCardCount = 0;
	state->whoseTurn = 0;
	state->handCount[state->whoseTurn] = 0;
	//int it; move to top

	//Moved draw cards to here, only drawing at the start of a turn
	for (it = 0; it < 5; it++){
		drawCard(state->whoseTurn, state);
	}

	updateCoins(state->whoseTurn, state, 0);

	return 0;
}
int supplyCount(int card, struct gameState *state) {
	return state->supplyCount[card];
}*/

int main() {
	// Initialize gameState Struct
	struct gameState teststate;
	
	int players[4] = {adventurer, smithy, sea_hag, minion};
	
	initializeGame(2, players, 1000, &teststate);
	printf("%d\t%d\n", supplyCount(curse, &teststate), supplyCount(estate, &teststate));
	
	initializeGame(3, players, 2000, &teststate);
	printf("%d\t%d\n", supplyCount(curse, &teststate) == 20, supplyCount(estate, &teststate) == 12);

	initializeGame(4, players, 2000, &teststate);
	printf("%d\t%d\n", supplyCount(curse, &teststate) == 30, supplyCount(estate, &teststate) == 12);

	return 0;
}
