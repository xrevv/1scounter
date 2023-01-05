#include "test.h"

bool test64(int64_t start, int64_t end)
{
    bool pass = true;                     // Test result
    for (int64_t i = start; i < end; i++) // Loop through all given WORDs
    {
        if (!(counter64(i) == __builtin_popcountll(i))) // Test if counter64 gives the same result as a builtin function
        {
            pass = false;
            break;
        }
    }

    // Print test results
    printf("TESTING FROM %20ld TO %20ld     ", start, end);
    pass ? printf("[\033[1;32m PASS \033[0m]\n") : printf("[\033[1;31m FAIL \033[0m]\n");

    return pass;
}

bool test256(int64_t start, int64_t end)
{
    bool pass = true; // Test result

    mpz_t x;                // Declare var x for testing
    mpz_init2(x, NUM_BITS); // Set number of bits

    mpz_t minus;                // Declare var minus for testing in case x<0
    mpz_init2(minus, NUM_BITS); // Set number of bits
    mpz_set_si(minus, -1);      // Set var minus to -1

    for (int64_t i = start; i < end; i++) // Loop through all given WORDs
    {
        mpz_clear(x);           // Clear var x
        mpz_init2(x, NUM_BITS); // Set number of bits
        mpz_set_si(x, i);       // Set var x to i

        if (mpz_sgn(x) >= 0) // Check sign of x
        {
            if (!(counter256(x) == mpz_popcount(x))) // Test if counter256 gives the same result as a builtin function
            {
                pass = false;
                break;
            }
        }
        else
        {
            if (!(counter256(x) == NUM_BITS - mpz_hamdist(x, minus))) // Test if counter256 gives the same result as a builtin function
            {
                pass = false;
                break;
            }
        }
    }

    // Print test results
    printf("TESTING FROM %20ld TO %20ld     ", start, end);
    pass ? printf("[\033[1;32m PASS \033[0m]\n") : printf("[\033[1;31m FAIL \033[0m]\n");

    return pass;
}