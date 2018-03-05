CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to enter: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.out randomtestadventurer randomtestcard1 randomtestcard2 

unittest1: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "*** Unit Test 1 Run for getCost ***" >> unittestresults.out
	unittest1 >> unittestresults.out
	echo -e "\n*** Unit Test 1 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "getCost" -A 4 >> unittestresults.out

unittest2: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Unit Test 2 Run for supplyCount ***" >> unittestresults.out
	unittest2 >> unittestresults.out
	echo -e "\n*** Unit Test 2 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "supplyCount" -A 4 >> unittestresults.out

unittest3: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Unit Test 3 Run for isGameOver ***" >> unittestresults.out
	unittest3 >> unittestresults.out
	echo -e "\n*** Unit Test 3 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "isGameOver" -A 4 >> unittestresults.out

unittest4: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Unit Test 4 Run for whoseTurn ***" >> unittestresults.out
	unittest4 >> unittestresults.out
	echo -e "\n*** Unit Test 4 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "whoseTurn" -A 4 >> unittestresults.out

cardtest1: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Card Test 1 Run for playAdventurer ***" >> unittestresults.out
	cardtest1 >> unittestresults.out
	echo -e "\n*** Card Test 1 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "playAdventurer" -A 4 >> unittestresults.out

cardtest2: dominion.o cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Card Test 2 Run for playSmithy ***" >> unittestresults.out
	cardtest2 >> unittestresults.out
	echo -e "\n*** Card Test 2 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "playSmithy" -A 4 >> unittestresults.out

cardtest3: dominion.o cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Card Test 3 Run for Sea Hag ***" >> unittestresults.out
	cardtest3 >> unittestresults.out
	echo -e "\n*** Card Test 3 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "sea_hag_func" -A 4 >> unittestresults.out

cardtest4: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Card Test 4 Run for Treasure Map ***" >> unittestresults.out
	cardtest4 >> unittestresults.out
	echo -e "\n*** Card Test 4 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "treasure_map_func" -A 4 >> unittestresults.out

allunittests: dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	
	echo -e "*** Unit Test 1 Run for getCost ***" >> unittestresults.out
	unittest1 >> unittestresults.out
	echo -e "\n*** Unit Test 1 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "getCost" -A 4 >> unittestresults.out
	echo -e "\n*** Unit Test 2 Run for supplyCount ***" >> unittestresults.out
	unittest2 >> unittestresults.out
	echo -e "\n*** Unit Test 2 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "supplyCount" -A 4 >> unittestresults.out
	echo -e "\n*** Unit Test 3 Run for isGameOver ***" >> unittestresults.out
	unittest3 >> unittestresults.out
	echo -e "\n*** Unit Test 3 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "isGameOver" -A 4 >> unittestresults.out
	echo -e "\n*** Unit Test 4 Run for whoseTurn ***" >> unittestresults.out
	unittest4 >> unittestresults.out
	echo -e "\n*** Unit Test 4 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "whoseTurn" -A 4 >> unittestresults.out
	echo -e "\n*** Card Test 1 Run for adventurer_func ***" >> unittestresults.out
	cardtest1 >> unittestresults.out
	echo -e "\n*** Card Test 1 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "playAdventurer" -A 4 >> unittestresults.out
	echo -e "\n*** Card Test 2 Run for smithy_func ***" >> unittestresults.out
	cardtest2 >> unittestresults.out
	echo -e "\n*** Card Test 2 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "playSmithy" -A 4 >> unittestresults.out
	echo -e "\n*** Card Test 3 Run for sea_hag_func ***" >> unittestresults.out
	cardtest3 >> unittestresults.out
	echo -e "\n*** Card Test 3 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "sea_hag_func" -A 4 >> unittestresults.out
	echo -e "\n*** Card Test 4 Run for treasure_map_func ***" >> unittestresults.out
	cardtest4 >> unittestresults.out
	echo -e "\n*** Card Test 4 Coverage ***" >> unittestresults.out
	gcov -abcfu dominion.c | grep "treasure_map_func" -A 4 >> unittestresults.out

randomtestadventurer: dominion.o randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov -abcfu dominion.c | grep "playAdventurer" -A 4 >> randomtestadventurer.out
	gcov -abcfu dominion.c | grep "dominion" -A 7 >> randomtestadventurer.out

randomtestcard1: dominion.o randomtestcard1.c
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov -abcfu dominion.c | grep "playSmithy" -A 4 >> randomtestcard1.out
	gcov -abcfu dominion.c | grep "dominion" -A 7 >> randomtestcard1.out

randomtestcard2: dominion.o randomtestcard2.c
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov -abcfu dominion.c | grep "sea_hag_func" -A 4 >> randomtestcard2.out
	gcov -abcfu dominion.c | grep "dominion" -A 7 >> randomtestcard2.out

allrandomtests: dominion.o randomtestadventurer.c randomtestcard1.c randomtestcard2.c
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Random Test Coverage for Adventurer ***" >> randomtestadventurer.out
	randomtestadventurer >> randomtestadventurer.out
	gcov -abcfu dominion.c | grep "playAdventurer" -A 4 >> randomtestadventurer.out
	gcov -abcfu dominion.c | grep "dominion" -A 7 >> randomtestadventurer.out
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Random Test Coverage for Smithy ***" >> randomtestcard1.out
	randomtestcard1 >> randomtestcard1.out
	gcov -abcfu dominion.c | grep "playSmithy" -A 4 >> randomtestcard1.out
	gcov -abcfu dominion.c | grep "dominion" -A 7 >> randomtestcard1.out
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	echo -e "\n*** Random Test Coverage for Sea Hag ***" >> randomtestcard2.out
	randomtestcard2 >> randomtestcard2.out
	gcov -abcfu dominion.c | grep "sea_hag_func" -A 4 >> randomtestcard2.out
	gcov -abcfu dominion.c | grep "dominion" -A 7 >> randomtestcard2.out