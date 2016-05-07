CC=gcc


main: minunit_harness.o example.c
	$(CC) -g example.c minunit_harness.o -o example

minunit_harness.o: minunit_harness.c minunit_harness.h
	$(CC) -c -g minunit_harness.c


clean:
	rm *.o
