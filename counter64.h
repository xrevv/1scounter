#pragma once

#include <stdint.h> //64 bit WORD

// Count number of 1s in a 64 bit WORD. Will also work on smaller bit WORDs.
int counter64(int64_t x);