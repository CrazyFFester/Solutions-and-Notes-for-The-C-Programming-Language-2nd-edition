#include <stdio.h>

#define IN 1   // внутри слова
#define OUT 0  // вне слова

int main() {
    int c;
    int state;
    int word_count = 0;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;  // Выходим из слова
        } else if (state == OUT) {
            state = IN;    // Начало нового слова
            ++word_count;  // Увеличиваем счётчик слов
        }
    }

    printf("Word count: %d\n", word_count);
}
