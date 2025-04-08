#include <stdio.h>

#define MAX_WORD_LENGHT 20
#define IN 1
#define OUT 0

int main() {
    int numberOfWords;
    int state;
    int c;
    int j;
    int i;
    int currentWord;
    int lenghtsOfWords[MAX_WORD_LENGHT + 1] = {0};
    int row;
    int maxLenght;

    currentWord = -1;
    state = OUT;

    printf("Enter Words: ");
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++currentWord;
            ++lenghtsOfWords[currentWord];
        } else if (state == IN) {
            ++lenghtsOfWords[currentWord];
        }
    }

    numberOfWords = currentWord + 1;

    for (i = 0; i <= MAX_WORD_LENGHT; ++i) {
        if (lenghtsOfWords[i] > maxLenght) {
            maxLenght = lenghtsOfWords[i];
        }
    }

    printf("\nVertical Histogram\n\n");

    for (row = maxLenght; row > 0; --row) {
        for (i = 0; i <= MAX_WORD_LENGHT; ++i) {
            if (lenghtsOfWords[i] >= row) {
                printf(" #  ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }

    for (i = 1; i <= MAX_WORD_LENGHT; ++i) {
        printf("--- ");
    }
    printf("\n");

    for (i = 0; i < numberOfWords; ++i) {
        printf("%2d  ", i + 1);
    }
    printf("\n");
}
