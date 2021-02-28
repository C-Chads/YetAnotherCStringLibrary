#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef STRUTIL_ALLOC
#define STRUTIL_ALLOC malloc
#endif

//Strcat but with malloc.
static inline char* strcatalloc(const char* s1, const char* s2){
	char* d = STRUTIL_ALLOC(strlen(s1) + strlen(s2) + 1);
	strcpy(d, s1);
	strcat(d, s2);
	return d;
}

//Read file until terminator character is found.
//Returns the number of characters copied.
static inline unsigned int read_until_terminator(FILE* f, char* buf, const unsigned int buflen, char terminator){
	unsigned int i = 0;
	char c;
	for(i = 0; i < (buflen-1); i++)
	{
		if(feof(f))break;
		c = fgetc(f);
		if(c == terminator)break;
		buf[i] = c;
	}
	buf[buflen-1] = '\0'; //READ_UNTIL_TERMINATOR ALWAYS RETURNS A VALID STRING!
	return i;
}
