
/*
Prototypes and macros for functional/ high assurance
programming using a subset of the C language
*/


/*
Loops with bounded execution
*/

#define loop(v, e)\
for(unsigned long v = 0, __geks_internal_##v = 0; __geks_internal_##v < e; __geks_internal_##v++, v = __geks_internal_##v)

#define loople(v, e)\
for(unsigned long v = 0, __geks_internal_##v = 0; __geks_internal_##v <= e; __geks_internal_##v++, v = __geks_internal_##v)




/*
TODO
*/
