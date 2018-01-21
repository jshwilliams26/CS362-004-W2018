#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

int adventurer_func(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int *temphand, int z);
int smithy_func(int currentPlayer, struct gameState *state, int handPos);
int sea_hag_func(struct gameState *state, int currentPlayer);
int minion_func(struct gameState *state, int handPos, int currentPlayer, int choice1, int choice2);
int treasure_map_func(struct gameState *state, int currentPlayer, int handPos);

#endif
