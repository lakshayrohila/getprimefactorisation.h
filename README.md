# getprimefactorisation.h
C/C++ library to get the prime factorisation of a number.

## Typedef:
`primefactorisation_t` -  Structure (C/C++ `struct`) to save prime factorisation of a number.<br /><br />
It includes-<br />
  `total` - Total count of numbers found in `factorisation`. Count is always 1 more than the numbers in factorisation.<br />
  <br />
  `factorisation` - Factorisation saved as a dynamic array.<br />

## Functions:
`primefactorisation_t getprimefactorisation(long long n)` -<br />
  Takes `n` as the number to find prime facorisation of.<br />
  Returns prime factorisation as `primefactorisation_t`.<br /><br />
`unsigned short __isprime(long long n)` - For internal use.<br /><br />
`void __getnextprimenum(long long *prime_num)` - For internal use.<br />

## Compiling:
Use compiler flag `-lm` while compiling. This library makes use of `math.h` library internally.

## Licensing:
This library comes under no license. You are free to use, modify and redistribute this library.
