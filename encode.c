
#include "stringutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
/*LIMITATIONS
* The escape character cannot be used inside of tokens (but the token character can) even if it is escaped.
* Token names must be alphabetic (a-z, A-Z)
* The token mark must be escaped with a backslash.
\
Encoded string:
~t3~THEfis7~FISHINGfl11~FLOUNDERING\~t ~fis BOAT IS ~fl.\\!

THE FISHING BOAT IS FLOUNDERING\!
*/
char* decode(char* inbuf){
	unsigned int lenin = strlen(inbuf);
	if(lenin < 3) {
		puts("\nToo Short!\n");
		return NULL;
	}
	char esc = inbuf[0]; //The escape character is the first one.
	char tokmark = inbuf[1]; //Begin token character.
	printf("Escape is %c, tokmark is %c\n", esc, tokmark);
	char c; unsigned int i = 2;
	char c_str[2] = {0,0};
	//Our decoded text.
	char* out = strcatalloc("","");
	//Tokens for replacement, even is the token,
	//odd is its definition
	char** tokens = NULL;
	unsigned int* toklens = NULL;
	unsigned int ntokens = 0;
#define RETRIEVE() {c = inbuf[i++]; if(i > lenin) {puts("\nRetrieve reached the end.\n");goto end;}}
	//Retrieve the tokens.
	RETRIEVE(); //has to occur before the loop.
	do{	ntokens++;
		tokens = realloc(tokens, ntokens * 2 * sizeof(char*)); 
		toklens = realloc(toklens, ntokens * sizeof(unsigned int));
		toklens[ntokens-1] = 0;
		tokens[(ntokens-1)*2] = strcatalloc("","");
		tokens[(ntokens-1)*2+1] = strcatalloc("","");
		//name of token is tokens[(ntokens-1)*2] and its definition is tokens[(ntokens-1)*2+1]
		//Get the name of the token.
		if(!isalpha(c)) goto end;	//Error! Can't have Break out.
		while(isalpha(c)){
			c_str[0] = c;
			tokens[(ntokens-1)*2] = strcatallocf1(tokens[(ntokens-1)*2], c_str);
			RETRIEVE();
		}
		//The last retrieve() got us the first digit of the token length.
		//Get the length of the token
		unsigned int l = 0;
		if(!isdigit(c)) goto end;
		while(isdigit(c) && c!=tokmark){
			c_str[0] = c;
			l *= 10;
			l += atoi(c_str);
			RETRIEVE();
		}
		toklens[ntokens-1] = l;
		//We have the name of the token and its length, the last RETRIEVE() got us the token character (~ in my example)
		//Now we can grab the token definition.
		for(unsigned int vv = 0; vv < l; vv++){
			RETRIEVE();
			c_str[0] = c;
			tokens[(ntokens-1)*2+1] = strcatallocf1(tokens[(ntokens-1)*2+1], c_str);	
		}
		RETRIEVE();
		printf("\nTOKEN %s IS %s, length %u",tokens[(ntokens-1)*2] ,tokens[(ntokens-1)*2+1], toklens[ntokens-1]);
	}while(c != esc);
	puts("\nREACHED ESCAPE CHARACTER.");
	//Now we attempt to build our string
	RETRIEVE();
	int doescape = 0;
	do{
		if(!doescape && c==esc){
			doescape=1;RETRIEVE();continue;
		}
		if(!doescape && c==tokmark){
			//TODO: See if it maches one of our tokens. if it does, insert the token definition.
			RETRIEVE();
			continue;
		}else{
			c_str[0] = c;
			out = strcatallocf1(out, c_str);
			doescape = 0;
			RETRIEVE();
		}
	}while(i<=lenin);
	end:
	for(unsigned int j = 0; j < ntokens; j++)
		{free(tokens[j*2]);free(tokens[j*2+1]);}
	free(toklens);
	return out;
}

#undef RETRIEVE

int main(){
	puts("\nHello World!\n");
	unsigned int l;
	char* b = read_until_terminator_alloced(stdin, &l, '^', 1024);
	char* q = decode(b);
	if(q) puts(q);
	free(b); free(q);
	puts("\nGoodbye World!\n");
}
