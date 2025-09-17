// PID: 730761368
// I pledge the COMP211 honor code.

#include <stdio.h>
#include <stdlib.h>

int hexCharToVal(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}

int main(void) {
    int c;
    int highNibble = -1;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            continue;
        }

        int val = hexCharToVal((char)c);
        if (val == -1) {
            continue;
        }

        if (highNibble == -1) {
        
            highNibble = val;
        } else {

            int byte = (highNibble << 4) | val;
            putchar(byte);
            fflush(stdout);
            highNibble = -1;
        }
    }

    return EXIT_SUCCESS;
}