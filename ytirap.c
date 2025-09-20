// PID: 730761368
// I pledge the COMP211 honor code.

#include <stdio.h>
#include <stdlib.h>

#define PARITY_BIT 1

int cal_count(unsigned char x){
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

        if (cal_count(byte) % 2 != 0) {
            printf("\nCorruption detected!\n");
            return EXIT_FAILURE;
        }

        putchar(byte >> PARITY_BIT);
    }

    putchar('\n');
    return EXIT_SUCCESS;
}