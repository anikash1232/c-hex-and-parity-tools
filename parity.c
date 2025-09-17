// PID: 730761368
// I pledge the COMP211 honor code.

#include <stdio.h>

int countOnes(unsigned char x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        unsigned char byte = (unsigned char)c;

        unsigned char shifted = byte << 1;

        int ones = countOnes(byte);

        if (ones % 2 != 0) {
            shifted |= 1;
        }

        putchar(shifted);
    }

    putchar('\n');
    return 0;
}