# Another string utility library for C

CC0 implementation of some basic string/file utilities which I find infinitely useful/

Never write them again. Please. Just stop.

strcatalloc (strcat, but it mallocs the memory for you)

stcatallocf1, f2, fb (strcat, but it mallocs/reallocs for you, and it frees its first, second, or both arguments.)

strcata, strcataf1, f2, fb (Aliases for the above functions.)

read_until_terminator (Like readline, but not dependent on compiler-specific nonsense and none of that "prompt" nonsense)

read_until_terminator_alloced (Like readline again, but it has INFINITE CAPACITY. Automatically resizes its buffer to fit the string.)

read_file_into_alloced_buffer (Read an entire file into an allocated buffer.)

if you have a custom memory allocator, then 
```c
#define STRUTIL_ALLOC(s) my_memory_allocator(s)
#define STRUTIL_REALLOC(s,t) my_memory_realloc(s,t)
#define STRUTIL_FREE my_free(s)
```

### BONUS CONTENT!

This library comes with bOnUs CoNtEnT! 

## A simple token-based parser ready for compiler authors.

Want to write a simple compiler? Want to put it in the public domain?

you can tokenize text into a linked list using `tokenize`.

- tokenize assumes that the text is allocated and can be free'd with STRUTIL_FREE.
- tokenize will free your text.
- tokenize will give you a `strll` (string linked list) which is a linked list of structs that looks like this:

```c
typedef struct strll{
	char* text;
	unsigned long identification;
	void* data;
	struct strll* right;
	struct strll* child;
	struct strll* left;
}strll;
```
- right is the following node in the AST.
- child is the owned set of right-progressing nodes in the AST.
	- You might decide for instance that a function declaration has an AST that looks like this
		-'int'
			-'myfunc'
				-'('
					-'int'
						-'a'
					-','
					-'int'
						-'b'
					-','
				-')'
			-'{'
				-'return'
					-'+'
						-left:'a' right:'b'
					-';'
			-'}'
					
- left is the owned set of left-progressing nodes in the AST.
- text is the literal text as a result of tokenization that you get back from `tokenize`
- identification is for your use to identify nodes in the AST.
- data is for your use to organize compiled code.


you also get a free text compression scheme.
This is what it looks like:
```c
\~t3~THEfis7~FISHINGfl11~FLOUNDERING\~t ~fis BOAT IS ~fl.\\!\~^
```
The first two characters define the characters to be used for "escape" and "token"

Then comes a list of token definitions, ~ used to denote "tokenmark" (as in example) and \ used to indicate "escape"
~<name><length>~<tokendefinition>

