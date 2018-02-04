CFLAGS = -Wall -fpic -coverage -lm

testme:
	gcc -o testme testme.c $(CFLAGS)
	testme

.PHONY: clean

clean:
	rm -rf testme *.gcov *.gcda *.gcno a.out