#include <stdio.h>

int main() {
    int c;

    c = getchar();

    if (c == EOF) {
        printf("%d\n", c);
    }
}
