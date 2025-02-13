#include <stdio.h>

int main() {
    int c;

    c = getchar();

    if (c == EOF) {
        printf("EOF is detected\n");
    }

    printf("%d\n", c != EOF);
}
