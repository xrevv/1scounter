#include "counter64.h"

// Count number of 1s in a 64 bit WORD. Will also work on smaller bit WORDs.
int counter64(int64_t x)
{
    int size = sizeof(x) * 8; // sizeof() returns number of bytes. Multiply by 8 for bits.
    int count = 0;            // var for storing number of 1s

    for (int i = 0; i < size; i++) // Loop through all the bits
    {
        if (x & 1)   // Check if the last bit is set to 1
            count++; // Increment count
        x >>= 1;     // Bit shift to the right and store the value
    }
    return count;
}