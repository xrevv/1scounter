#include "counter256.h"

// Count number of 1s in a 256 bit WORD
int counter256(mpz_t x)
{
    int count = 0; // var for storing number of 1s

    for (int i = 0; i < NUM_BITS; i++) // Loop through all the bits
    {
        count += mpz_tstbit(x, i); // Check if ith bit is set to 1
    }
    return count;
}