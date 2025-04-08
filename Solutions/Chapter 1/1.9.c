#include <stdio.h>

int main() {
    int c;
    int last_char;

    last_char = EOF;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || last_char != ' ') {
            putchar(c);
        }

        last_char = c;
    }
}
