// PID: 730761368
// I pledge the COMP211 honor code.

#include <stdio.h>

int countOnes(unsigned char x) {
    int count = 0;
    while (x) {
        if ((x & 1) == 1){
            count += 1;
        }

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
            putchar((byte << 1) | 1);
        }
        else {
            putchar((byte << 1) | 0);
        }
    }

    putchar('\n');
    return 0;
}