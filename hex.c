// PID: 730761368
// I pledge the COMP211 honor code.

#include <stdio.h>


void printHex(unsigned char byte) {
    const char *hexDigits = "0123456789ABCDEF";

    putchar(hexDigits[(byte >> 4) & 0xF]);
    putchar(hexDigits[byte & 0xF]);
}

int main(void) {
    int c;
    int count = 0;

    while ((c = getchar()) != EOF) {
        unsigned char byte = (unsigned char)c;
        printHex(byte);
        count += 2;

        if (count >= 80) {
            putchar('\n');
            count = 0;
        }
    }

    if (count != 0) {
        putchar('\n');
    }

    return 0;
}
