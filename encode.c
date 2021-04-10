
#include "stringutil.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



const char* enctable[12] = {
	"t",
	"THE",
	"w",
	"WHAT",
	
	"fis",
	"FISHING",
	"fl",
	"FLOUNDERING",
	
	"b",
	"BOAT",
	"f",
	"FRICK",
};
const unsigned int ntokenc = 6;



int main(int argc, char** argv){
	unsigned long l;
	if(argc < 2){
		char* b = read_until_terminator_alloced(stdin, &l, '\n', 1024);
		char* q = strdecodealloc(b);
		if(q) puts(q);
		STRUTIL_FREE(b); STRUTIL_FREE(q);
	} else {
		char* b = read_until_terminator_alloced(stdin, &l, '\n', 1024);
		char* q = strencodealloc(b, enctable, ntokenc, '\\', '~');
		if(q) puts(q);
		STRUTIL_FREE(b); STRUTIL_FREE(q);
	}
}
