#include <stdio.h>

/* Prints the binary presentation of an integer */
void bin(int n)
{
    int flag = 0;
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
        {
            printf("1");
            flag = 1;
        }
        else if (flag)
            printf("0");
    }
    printf("\n");
}

/* Gets next biggest integer with same amount of 1s in
 * binary representation */
int get_next(int n)
{
    int c, c0, c1, p;

    c = n;
    for (c0 = 0; !(c & 1) && c; c >>= 1, c0++)
        ;
    for (c1 = 0; c & 1; c >>= 1, c1++)
        ;
    // position of rightmost non-trailing zero
    p = c0 + c1;
    n |= (1 << p);            // Flip rightmost non-trailing zero
    n &= ~((1 << p) - 1);     // Clear all bits to the right of p
    n |= (1 << (c1 - 1)) - 1; // Insert (c1 - 1) ones on the right
    return n;
}

int main()
{
    bin(get_next(0b11011001111100));
    /* 11011010001111 */
    return 0;
}