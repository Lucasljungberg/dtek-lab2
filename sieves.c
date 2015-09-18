//Author: Lucas Ljungberg <lucaslj@kth.se>

#include <stdio.h>

int find_limit(int n);
void print_sieves(int n);

/**
 * Uses Newton Raphson's method to find a reasonable limit for a number n.
 * This finds a reasonably good approximation of a square root.
 *
 * @author Peter Jonsson
 * @param n Number to get the limit (square root of) of.
 * @return Approximated square root of n plus 1 for integer rounding.
 */
int find_limit(int n) {
    double x = n / 2;
    double dx = 1;
    int i = 0;

    while (dx > 1 && i < 100) {
        dx = (x * x - n) / (2 * x);
        x = x - dx;
        i++;
    }

    return (int) x + 1;
}

/**
 * Uses the Sieve of Eratosthenes algorithm to find and print
 * the primes up to (including) the given number
 *
 * @author Lucas Ljungberg <lucaslj@kth.se>
 * @param n The upper limit of primes to be found
*/
void print_sieves(int n)
{
    int* primes = malloc(sizeof(int)*n;
    int limit = find_limit(n);




    free(primes);
}



int main(int argc, char *argv[]){
    if(argc == 2)
        print_primes(atoi(argv[1]));
    else
        printf("Please state an interger number.\n");
    return 0;
}