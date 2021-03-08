CC= gcc
CFLAGS= -O3

all:
	$(CC) $(CFLAGS) test.c -o test.out -lm -g
	$(CC) $(CFLAGS) encode.c -o enc.out -lm -g

clean:
	rm -f *.exe *.out *.o
