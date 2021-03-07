# Another string utility library for C

CC0 implementation of some basic string/file utilities...

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
```
