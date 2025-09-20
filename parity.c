// PID: 730761368
// I pledge the COMP211 honor code.

#include <stdio.h>

#define PARITY_BIT 1

int countOnes(unsigned char x) {
    int count = 0;
    while (x) {
        if ((x & PARITY_BIT) == PARITY_BIT){
            count += PARITY_BIT;
        }

        x >>= PARITY_BIT;
    }
    return count;
}

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        unsigned char byte = (unsigned char)c;

        int ones = countOnes(byte);

        if (ones % 2 != 0) {
            putchar((byte << PARITY_BIT) | PARITY_BIT);
        }
        else {
            putchar((byte << PARITY_BIT) | 0);
        }
    }

    putchar('\n');
    return 0;
}