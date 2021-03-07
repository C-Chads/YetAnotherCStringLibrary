

#include "stringutil.h"


int main(int argc, char** argv){
	
	char* one_and_two = NULL;
	if(argc > 2)
		one_and_two = strcatalloc(argv[1],argv[2]);
	if(one_and_two)
		printf("Arguments 1 and 2 combined together are %s", one_and_two);
	if(one_and_two) free(one_and_two);

	puts("\nReading from stdin until terminator B or 9 characters...\n");
	char* buf = malloc(10);
	if(!buf)return 1;
	unsigned int blen = read_until_terminator(stdin, buf, 10, 'B');
	printf("\nYou entered a string of length %u:\n%s\n",blen, buf);
	free(buf);

	FILE* f = fopen("README.MD", "rb");
	if(!f) return 1;
	unsigned int len;
	buf = NULL; buf = read_file_into_alloced_buffer(f, &len);
	if(buf){
		printf("\nThe entire contents of README.MD are:\n%s\n~~~\n",buf);
		free(buf);
	}
	if(f) fclose(f);

	//Substring search.
	const char* text = "Oh, what a mighty fine day it is!";
	int pos = strfind(text, "mighty"); //-1 means it could not find it
	int pos2 = strfind(text, "Mighty"); //-1 means it could not find it
	printf("\n\"mighty\" is at %d\n", pos);
	printf("\"Mighty\" is at %d\n", pos2);
	return 0;
}
