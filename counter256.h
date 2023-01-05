#pragma once

#include <gmp.h> //256+ bit WORD

#define NUM_BITS 256 // Number of bits. GMP can work with arbitrary precision

// Count number of 1s in a 256 bit WORD
int counter256(mpz_t x);