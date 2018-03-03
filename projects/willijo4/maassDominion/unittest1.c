//****************************************************************
// Name: Josh Williams (willijo4)
// Assignment: 3
// Description: Unit test for getCost function
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
	int i;
	for (i = -1; i < 30; i++) {
		switch (i) 
		{
			case 0:
				printf("Card curse returns %d: %s\n", 0, getCost(i) == 0 ? "True" : "False");
				break;
			case 1:
				printf("Card estate returns %d: %s\n", 2, getCost(i) == 2 ? "True" : "False");
				break;
			case 2:
				printf("Card duchy returns %d: %s\n", 5, getCost(i) == 5 ? "True" : "False");
				break;
			case 3:
				printf("Card province returns %d: %s\n", 8, getCost(i) == 8 ? "True" : "False");
				break;
			case 4:
				printf("Card copper returns %d: %s\n", 0, getCost(i) == 0 ? "True" : "False");
				break;
			case 5:
				printf("Card silver returns %d: %s\n", 3, getCost(i) == 3 ? "True" : "False");
				break;
			case 6:
				printf("Card gold returns %d: %s\n", 6, getCost(i) == 6 ? "True" : "False");
				break;
			case 7:
				printf("Card adventurer returns %d: %s\n", 6, getCost(i) == 6 ? "True" : "False");
				break;
			case 8:
				printf("Card council_room returns %d: %s\n", 5, getCost(i) == 5 ? "True" : "False");
				break;
			case 9:
				printf("Card feast returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 10:
				printf("Card gardens returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 11:
				printf("Card mine returns %d: %s\n", 5, getCost(i) == 5 ? "True" : "False");
				break;
			case 12:
				printf("Card remodel returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 13:
				printf("Card smithy returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 14:
				printf("Card village returns %d: %s\n", 3, getCost(i) == 3 ? "True" : "False");
				break;
			case 15:
				printf("Card baron returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 16:
				printf("Card great_hall returns %d: %s\n", 3, getCost(i) == 3 ? "True" : "False");
				break;
			case 17:
				printf("Card minion returns %d: %s\n", 5, getCost(i) == 5 ? "True" : "False");
				break;
			case 18:
				printf("Card steward returns %d: %s\n", 3, getCost(i) == 3 ? "True" : "False");
				break;
			case 19:
				printf("Card tribute returns %d: %s\n", 5, getCost(i) == 5 ? "True" : "False");
				break;
			case 20:
				printf("Card ambassador returns %d: %s\n", 3, getCost(i) == 3 ? "True" : "False");
				break;
			case 21:
				printf("Card cutpurse returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 22: 
				printf("Card embargo returns %d: %s\n", 2, getCost(i) == 2 ? "True" : "False");
				break;
			case 23:
				printf("Card outpost returns %d: %s\n", 5, getCost(i) == 5 ? "True" : "False");
				break;
			case 24:
				printf("Card salvager returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 25:
				printf("Card sea_hag returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			case 26:
				printf("Card treasure_map returns %d: %s\n", 4, getCost(i) == 4 ? "True" : "False");
				break;
			default:
				printf("Input %d returns -1: %s\n", i, getCost(i) == -1 ? "True" : "False");
		}
	}
	
	return 0;
}



