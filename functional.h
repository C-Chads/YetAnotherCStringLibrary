
/*
Prototypes and macros for functional/ high assurance
programming using a subset of the C language
*/


/*
Loops with bounded execution
*/

#define loop(v, e)\
for(unsigned long v = 0, __internal_##v = 0; __internal_##v < e; __internal_##v++, v = __internal_##v)

#define loople(v, e)\
for(unsigned long v = 0, __internal_##v = 0; __internal_##v <= e; __internal_##v++, v = __internal_##v)




/*
TODO
*/
