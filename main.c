// Standard libraries
#include <stdio.h>   //Printing to console
#include <stdbool.h> //Bool values
#include <stdint.h>  //64 bit WORD
#include <gmp.h>     //256+ bit WORD

// Custom libraries
#include "counter64.h"  //Counting 1s in 64 bit WORD
#include "counter256.h" //Counting 1s in 256 bit WORD
#include "test.h"       //Testing functions

#define NUM_TESTS 10000000 // Offset for tests

int main()
{
    bool pass64 = true;  // Test result for 64 bit WORD
    bool pass256 = true; // Test result for 256 bit WORD

    // Testing all 64 bit WORDs would take too much time
    if (!test64(INT16_MIN, INT16_MAX)) // Testing counter64 from INT16_MIN to INT16_MAX
        pass64 = false;

    if (!test64(INT64_MIN, INT64_MIN + NUM_TESTS)) // Testing counter64 from INT64_MIN to INT64_MIN + NUM_TESTS
        pass64 = false;

    if (!test64(INT64_MAX - NUM_TESTS, INT64_MAX)) // Testing counter64 from INT64_MAX - NUM_TESTS to INT64_MAX
        pass64 = false;

    // Print test results for counter64
    printf("RESULTS 64                                                    ");
    pass64 ? printf("[\033[1;32m PASS \033[0m]\n") : printf("[\033[1;31m FAIL \033[0m]\n");

    // Testing all 256 bit WORDs would take too much time
    if (!test256(INT16_MIN, INT16_MAX)) // Testing counter256 from INT16_MIN to INT16_MAX
        pass256 = false;

    if (!test256(INT64_MIN, INT64_MIN + NUM_TESTS)) // Testing counter256 from INT64_MIN to INT64_MIN + NUM_TESTS
        pass256 = false;

    if (!test256(INT64_MAX - NUM_TESTS, INT64_MAX)) // Testing counter256 from INT64_MAX - NUM_TESTS to INT64_MAX
        pass256 = false;

    // Print test results for counter256
    printf("RESULTS 256                                                   ");
    pass256 ? printf("[\033[1;32m PASS \033[0m]\n") : printf("[\033[1;31m FAIL \033[0m]\n");

    // Print overall test results
    printf("RESULTS                                                       ");
    pass64 &&pass256 ? printf("[\033[1;32m PASS \033[0m]\n") : printf("[\033[1;31m FAIL \033[0m]\n");

    return 0;
}