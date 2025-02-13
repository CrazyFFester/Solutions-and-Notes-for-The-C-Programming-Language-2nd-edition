#include <stdio.h>

int main() {
    int bl;
    int tb;
    int nl;

    int c;

    bl = 0;
    tb = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++bl;
        } else if (c == '\t') {
            ++tb;
        } else if (c == '\n') {
            ++nl;
        }
    }

    printf("\n");
    printf("\n");
    printf("Blanks: %d\n", bl);
    printf("Tabs: %d\n", tb);
    printf("Newlines: %d\n", nl);
}
