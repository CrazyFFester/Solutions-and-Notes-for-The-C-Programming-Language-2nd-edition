#include <stdio.h>

#define ASCII_COUNT 128  // Количество возможных ASCII-символов

int main() {
    int c;
    int i;
    int char_count[ASCII_COUNT] = {0};  // Массив для подсчёта символов

    // Считать символы и обновить счётчики
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < ASCII_COUNT) {
            ++char_count[c];
        }
    }

    // Печать гистограммы
    printf("Horizontal Histogram of Character Frequencies:\n");
    for (i = 0; i < ASCII_COUNT; ++i) {
        if (char_count[i] >
            0) {  // Печатаем только символы, которые встречались
            printf("%c (%d): ", i, i);
            for (int j = 0; j < char_count[i]; ++j) {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}
