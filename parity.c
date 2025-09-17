// PID: 123456789
// I pledge the COMP211 honor code.

#include <stdio.h>

// Count 1-bits
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

        // Shift right by 1 to leave space for parity in LSB
        unsigned char shifted = byte << 1;

        // Count ones in the top 7 bits (original ASCII)
        int ones = countOnes(byte);

        // Set LSB to enforce even parity
        if (ones % 2 != 0) {
            shifted |= 1; // set LSB
        }

        putchar(shifted);
    }

    // End with newline
    putchar('\n');
    return 0;
}