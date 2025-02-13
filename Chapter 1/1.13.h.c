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

    currentWord = -1;
    state = OUT;

    int lenghtsOfWords[MAX_WORD_LENGHT];

    for (i = 0; i <= MAX_WORD_LENGHT; ++i) {
        lenghtsOfWords[i] = 0;
    }
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

    printf("Horizontal Histogram\n\n");

    for (i = 0; i < numberOfWords; i++) {
        printf("%d: ", i + 1);

        for (j = 0; j < lenghtsOfWords[i]; ++j) {
            printf("#");
        }

        printf("\n");
    }
}
