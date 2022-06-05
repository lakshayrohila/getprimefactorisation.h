/*
 * C/C++ library to get prime factorisation of a number. This library comes under no license.
 * You are free to use, modify and redistribute this library. Read 'README.md' for documentation.
*/

#ifndef _INC_GETPRIMEFACTORISATION
#define _INC_GETPRIMEFACTORISATION

#include <math.h>
#include <stdlib.h>

typedef struct {
    long long total, *factorisation;
} primefactorisation_t;

unsigned short __isprime(long long n) {
    if(!(n%2)) {
        return 0;
    }

    long j = 3;
    long long k = (long long)sqrt(n);

    while(j <= k) {
    	if(!(n%j)) {
	        return 0;
	    }

	    j += 2;
    }

    return 1;
}

void __getnextprimenum(long long *prime_num) {
    if(((*prime_num)+1) == 2) {
        *prime_num = 2;
        return;
    }

    long long i = (*prime_num)-(!((*prime_num)%2))+2;

    while(1) {
        if(__isprime(i)) {
            *prime_num = i;
            return;
        }

        i+=2;
    }
}

primefactorisation_t getprimefactorisation(long long n) {
    long long *factorisation = malloc(sizeof(long long)), prime_num = 2, i = 0;
    primefactorisation_t factstruct;

    if(n == 0) {
        factstruct.factorisation = NULL;
        factstruct.total = 0;

        return factstruct;
    } else if(n == 1) {
        *factorisation = 1;
        factstruct.factorisation = factorisation;
        factstruct.total = 1;

	    return factstruct;
    } else if(n < 0) {
        n *= -1;
        *factorisation = -1;
        i++;
    }

    if(n == -1) {
	    factstruct.total = 1;
        factstruct.factorisation = factorisation;
        return factstruct;
    }

    while(n > 1) {
	    if(!__isprime(n)) {
            while((n%prime_num) != 0) {
                __getnextprimenum(&prime_num);
	        }
	    } else {
	        prime_num = n;
        }

        factorisation = realloc(factorisation, (i+1)*sizeof(long long));
        *(factorisation+i) = prime_num;
	    n /= prime_num;

        i++;
    }

    factstruct.factorisation = factorisation;
    factstruct.total = i;

    return factstruct;
}
#endif
