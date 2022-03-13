#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

#define EXPR_NODE_ARRAY_NUM_ELEMS 1024
typedef struct expr_node{
	char name[128]; /*for identifiers, or for ops/paren*/
	struct expr_node* left;
	struct expr_node* right;
	unsigned char udata[4]; /*user data*/
	char mode;  /*0 = operator*/
				/*1 = parentheses*/
				/*2 = identifier*/
}expr_node;
typedef struct{
	expr_node elems[EXPR_NODE_ARRAY_NUM_ELEMS];
	unsigned int n;
}expr_node_array;

const char* unary_prefix_ops[] = {
"~",
"-",
"!",
"&",
"++",
"--"
};

const char* unary_postfix_ops[] = {
"++",
"--"
};

const char* binary_ops[] = {
"+",
"-",
"*",
"/",
"%",
"^",
"|",
"||",
"&",
"&&",
"=",
"==",
"<",
"<=",
">",
">="
};


/*
	Jump to next token in string.	
*/
char* jmp_to_next_tok(char* cur){
	if(*cur == 0) return cur;
	if(isalpha(*cur) || isdigit(*cur) || *cur == '_'){
		while(isalpha(*cur) || isdigit(*cur) || *cur == '_')cur++;
		return cur;
	}
	if(isspace(*cur)){
		while(isspace(*cur))cur++;
		return cur;
	}
	cur++; return cur;
}
