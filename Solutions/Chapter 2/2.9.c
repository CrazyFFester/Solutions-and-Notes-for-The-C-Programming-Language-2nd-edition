#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    printf("%d\n", bitcount(9)); // 1010

    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1)) // 1000
    {
        b++;
    }
    return b;
}
