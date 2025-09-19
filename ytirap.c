// PID: 730761368
// I pledge the COMP211 honor code.

#include <stdio.h>
#include <stdlib.h>

int cal_count(unsigned char x){
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

        if (cal_count(byte) % 2 != 0) {
            printf("Corruption detected!\n");
            return EXIT_FAILURE;
        }

        putchar(byte >> 1);
    }

    putchar('\n');
    return EXIT_SUCCESS;
}