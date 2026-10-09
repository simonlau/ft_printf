# Variadic Functions in C

> Source: https://dev.to/pauljlucas/variadic-functions-in-c-53ml
> Collected: 2026-10-09
> Published: 2024-04-27

Author: Paul J. Lucas (DEV Community). Posted on Apr 27, 2024. Edited on May 7, 2024.

## Introduction

C has always used functions that can take a varying number of arguments — variadic functions — printf() being the primary example. Originally, C had no way for you to implement your own variadic functions portably. When function prototypes were back-ported from C++ to C, it included syntax for declaring variadic functions, for example:

```
int sum_n( unsigned n, ... );
```

says the function sum_n requires one unsigned argument followed by zero or more other arguments.

## A Simple Example Using a Count

Here is a sample implementation of sum_n() where we use the required parameter to specify how many arguments follow:

```
#include <stdarg.h>  /* for va_*() macros */

int sum_n( unsigned n, ... ) {
  va_list args;
  va_start( args, n );
  int sum = 0;
  while ( n-- > 0 )
    sum += va_arg( args, int );
  va_end( args );
  return sum;
}
```

Then you can call it like:

```
int r = sum_n( 3, 1, 2, 5 );  // r = 8
```

Note that we are using the required parameter to specify how many arguments follow as our own convention here. The compiler does not infer any meaning from the required parameter. As we will see in a later example, the required parameter can be of any type.

## Variadic Function Recipe

Any variadic function must be of the form:

```
R f( T1 p1, T2 p2, TN pN, ... ) {
  // ...
  va_list args;
  va_start( args, pN );

  // ... va_arg( args, T ) ...

  va_end( args );
  // ...
}
```

that is you must:

1. Declare a local variable of type va_list. (You can name it anything you want, but args is conventional.)
2. Call va_start( args, pN ) where pN is the name of the last required parameter. Note that it can be of any type.
3. To iterate over the values of the variadic arguments, call va_arg( args, T ) for each argument where T is its presumed type. (The type T may be different for each call.)
4. Call va_end( args ) before returning.

## Another Simple Example Using a Sentinel

Here is a sample implementation of str_is_any() where the required parameter is a string to compare (the "needle") and the arguments that follow are strings to compare against (the "haystack"). The arguments are terminated by a NULL pointer:

```
_Bool str_is_any( char const *needle, ... ) {
  va_list args;
  va_start( args, needle );
  _Bool found = false;
  do {
    char const *const hay = va_arg( args, char* );
    if ( hay == NULL )
      break;
    found = strcmp( needle, hay ) == 0;
  } while ( !found );
  va_end( args );
  return found;
}
```

And you can call it like:

```
if ( str_is_any( type_str, "struct", "union", NULL ) )
```

## Caveats

Variadic arguments have several serious caveats:

1. There is no way to require that any argument be of a specific type nor is there any way to require that all the arguments be of the same type.
2. There is no way to know for certain what the type of any argument actually is.
3. Because there is no type information, only default argument conversions occur (see below).
4. There is no way to know how many arguments were given. (Attempting to access more arguments than were given results in undefined behavior; however, accessing fewer is OK.)
5. Prior to C23, variadic functions had to have at least one required parameter.
6. The ... must always be last.
7. When iterating over arguments via va_arg(), the given type must match the actual type. If it doesn't, the result is undefined behavior.

The default argument conversions are:

- char, signed char, unsigned char, short, and unsigned short are promoted to either int or unsigned int as appropriate.
- float is promoted to double.
- An array is converted to a pointer to its zeroth element.
- A function name is converted to a pointer to that function.

Hence, the top two problems when implementing a variadic function are:

1. Knowing either the number of arguments or when to stop iterating over them.
2. Knowing their types.

The sum_n() implementation "solves" the first problem by using the required parameter to specify how many arguments follow. However, if you were to specify that there are 3 arguments that follow but there are fewer, the result would be undefined behavior.

Also, the sum_n() implementation can only assume that the provided arguments are of type int. If you were to provide a value of type double (or any other type) where int is expected, the result would be undefined behavior.

The str_is_any() function "solves" the first problem by using a sentinel so it doesn't care how many arguments there are. However, it still can only assume that the provided arguments are strings and that the last argument is NULL. If either of those are false, the result would be undefined behavior.

The standard printf() function "solves" both problems by using the one required argument as the format for what to print: each % within the format is a conversion specifier and has a one-to-one correspondence with an argument. For example, given:

```
printf( "x=%d, y=%d\n", x, y );
```

the printf() implementation scans the format string looking for % characters. Upon encountering one, it fetches the next variadic argument's value via va_arg() using the type specified by the character(s) that follow the %, e.g., %d specifies int (and print it in decimal).

However, just as with sum_n(), if you either provide fewer arguments than specifiers or the type of a specifier and its associated argument don't match, the result would be — you guessed it — undefined behavior.

Fortunately, modern compilers have specific knowledge about printf(), and so can warn when either the number of types of arguments don't match the format string. For your own functions, however, you're generally on your own to get it right.

## Thoughts on Implementing Variadic Functions

Given all their caveats, are variadic functions a good idea? Not really. Their use was a hack stemming from C originally not caring about function arguments at all. Even the introduction of stdarg.h (and varargs.h before that) did only the minimum amount to make implementing variadic functions portable, but not good.

Should you implement your own variadic functions? Generally, no. However, there is one use-case for implementing your own variadic functions.

## Variadic Functions Calling Other Variadic Functions

A va_list parameter allows one variadic function to pass its variable arguments to another. The way this is implemented is that there's an fl_print_error() variadic function that's a wrapper around fprintf() that takes additional file and line arguments whence it was called. Here is the (slightly simplified) implementation:

```
void fl_print_error( char const *file, int line,
                     char const *format, ... ) {
  fprintf( stderr, "error: " );
  if ( opt_cdecl_debug != CDECL_DEBUG_NO )
    fprintf( stderr, "[%s:%d] ", file, line );
  va_list args;
  va_start( args, format );
  vfprintf( stderr, format, args );
  va_end( args );
}
```

If you weren't aware, printf() and fprintf() have vprintf() and vfprintf() counterparts that take a va_list parameter:

```
int vprintf( const char *format, va_list vlist );
int vfprintf( FILE *stream, const char *format, va_list vlist );
```

A va_list parameter allows one variadic function to pass its variable arguments to another.

## A Note on C23

As of C23, variadic functions no longer insist on at least one required parameter; that is you can do:

```
void f( ... ) {      // no required parameter
  va_list args;
  va_start( args );  // no second argument
  // ...
```

This ability was also back-ported from C++.

## Conclusion

Variadic functions in C are basically a hack. Given their serious caveats, you generally should not implement your own unless it's a wrapper around another variadic function.
