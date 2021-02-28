# Another string utility library for C

CC0 implementation of some basic string/file utilities...

Never write them again. Please. Just stop.

strcatalloc (strcat, but it mallocs the memory for you)

read_until_terminator (Like readline, but not dependent on compiler-specific nonsense and none of that "prompt" nonsense)

read_file_into_alloced_buffer (Read an entire file into an allocated buffer.)

if you have a custom memory allocator, then 
```c
#define STRUTIL_ALLOC(s) my_memory_allocator(s)
```
