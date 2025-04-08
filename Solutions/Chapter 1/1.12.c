#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c;
    int state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            state = OUT;
            putchar('\n');
        } else if (state == IN) {
            putchar(c);
        } else if (state == OUT) {
            state = IN;
            putchar(c);
        }
    }
}
