#include "rand.h"

static unsigned long int next = 1;

int rand(void)
{
        next = next * 1103515245UL + 12345;
        return (unsigned int)(next/65536) % (RAND_MAX + 1U);
}

void srand(unsigned int seed)
{
        next = seed;
}
