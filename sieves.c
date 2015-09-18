//@author Lucas Ljungberg <lucaslj@kth.se>
//@since 2015-09-18
//@version 2015-09-18

#include <stdio.h>
#include <stdlib.h>

int find_limit(int n);
void print_sieves(int n);
int COLUMNS = 6;

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
    int* primes = malloc(sizeof(int)*n);
    int limit = find_limit(n);

    // This algorithm starts at 2
    int i = 2;

    /**
    * Initializing list. 
    * Would've liked to skip this part, but had
    * issues with some pointervalues initializing as 0
    */
    while (i < n)
    {
        *(primes + i) = 1;
        i++;
    }

    // Starts the iteration to mark primes
    i = 2;
    while (i <= limit)
    {
        if (*(primes + i))
        {
            int j = i * 2;
            while (j <= n)
            {
                *(primes + j) = 0;
                j += i;
            }
        }
        i++;
    }

    //Prints the list
    int columns = 0;
    i = 2;
    while (i <= n)
    {
        if (*(primes + i))
        {
            printf("%10d", i);
            columns++;
            if (columns >= COLUMNS)
            {
                columns = 0;
                printf("\n");
            }
        }
        i++;
    }

    //Frees up the memory
    free(primes);
}



int main(int argc, char *argv[]){
    if(argc == 2)
        print_sieves(atoi(argv[1]));
    else
        printf("Please state an interger number.\n");
    printf("\n");
    return 0;
}