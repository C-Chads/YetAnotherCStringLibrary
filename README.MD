# Another string utility library for C

CC0 implementation of some basic string/file utilities which I find infinitely useful/

Never write them again. Please. Just stop.

strcatalloc (strcat, but it mallocs the memory for you)

stcatallocf1, f2, fb (strcat, but it mallocs for you, and it frees its first, second, or both arguments.)

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

This library comes with bOnUs CoNtEnT! you also get a free text compression scheme.
This is what it looks like:
```c
\~t3~THEfis7~FISHINGfl11~FLOUNDERING\~t ~fis BOAT IS ~fl.\\!\~^
```
The first two characters define the characters to be used for "escape" and "token"

Then comes a list of token definitions, ~ used to denote "tokenmark" (as in example) and \ used to indicate "escape"
~<name><length>~<tokendefinition>

