CC= gcc
CFLAGS= -O3

all:
	$(CC) $(CFLAGS) test.c -o test.out -lpthread -lm

clean:
	rm -f *.exe *.out *.o
