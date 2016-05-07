CC=gcc


main: minunit_harness.o main.c
	$(CC) -g main.c minunit_harness.o

minunit_harness.o: minunit_harness.c minunit_harness.h
	$(CC) -c -g minunit_harness.c


clean:
	rm *.o
