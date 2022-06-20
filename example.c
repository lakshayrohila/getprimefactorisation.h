/*
 * Example of using getprimefactorisation.h library in C. This program is comatible with C++.
 * When compiling, use compiler flag '-lm'. This library makes use of 'math.h' library internally.
*/

// include libraries
#include <stdio.h>
#include "getprimefactorisation.h"

int main() {
    long long input_n, i = 0;

    // get value of 'input_n' from input
    printf("Enter an integer to get its prime factorisation: ");
    scanf("%lld", &input_n);

    // get prime factorisation using function 'getprimefactorisation'
    primefactorisation_t primefactorisation = getprimefactorisation(input_n);

    // print prime factorisation
    printf("\nPrime factorisation of %lld:\n", input_n);

    while(i < primefactorisation.total) {
        printf("%lld ", primefactorisation.factorisation[i]);
        i++;
    }

    printf("\n");

    // free primefactorisation.factorisation. it is dynamically allocated
    free(primefactorisation.factorisation);

    return 0;
}
