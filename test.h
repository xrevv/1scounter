#pragma once

// Standard libraries
#include <stdio.h>   //Printing to console
#include <stdint.h>  //Bool values
#include <stdbool.h> //64 bit WORD
#include <gmp.h>     //256+ bit WORD

// Custom libraries
#include "counter64.h"  //Counting 1s in 64 bit WORD
#include "counter256.h" //Counting 1s in 256 bit WORD

// Check if test64 works correctly
bool test64(int64_t start, int64_t end);

// Check if test256 works correctly
bool test256(int64_t start, int64_t end);