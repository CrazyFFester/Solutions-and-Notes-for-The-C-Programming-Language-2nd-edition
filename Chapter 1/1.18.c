#include <stdio.h>

#define MAX_CHAR 1000

void collecting_data(int current_char, char lines_of_characters[]);
void divide_into_lines(int current_char, char lines_of_characters[]);
void display_lines(char lines_of_characters[], int current_line,
                   int start_of_line, int end_of_line);
void remove_by_index(char arr[], int index);
int skip_blank_lines(int current_char);
int remove_trailing_blanks(char lines_of_characters[], int current_char);

int main() {
    int current_char;
    char lines_of_characters[MAX_CHAR] = {};

    current_char = 0;

    collecting_data(current_char, lines_of_characters);
    divide_into_lines(current_char, lines_of_characters);

    return 0;
}

void collecting_data(int current_char, char lines_of_characters[]) {
    int c;

    for (current_char = 0; (c = getchar()) != EOF; ++current_char) {
        lines_of_characters[current_char] = c;
    }
}

void divide_into_lines(int current_char, char lines_of_characters[]) {
    int start_of_line;
    int end_of_line;
    int current_line;

    start_of_line = 0;
    current_line = 1;

    for (current_char = 0; current_char < MAX_CHAR; ++current_char) {
        if (current_char != 0 &&
            lines_of_characters[current_char - 1] == '\n' &&
            lines_of_characters[current_char] == '\n') {
            start_of_line = skip_blank_lines(current_char);
            continue;
        }

        current_char =
            remove_trailing_blanks(lines_of_characters, current_char);

        if (lines_of_characters[current_char] == '\n') {
            end_of_line = current_char;
            display_lines(lines_of_characters, current_line, start_of_line,
                          end_of_line);

            ++current_line;
            start_of_line = end_of_line + 1;
        }
    }
}

void display_lines(char lines_of_characters[], int current_line,
                   int start_of_line, int end_of_line) {
    printf("%d) ", current_line);

    for (int current_char_in_line = start_of_line;
         current_char_in_line <= end_of_line; ++current_char_in_line) {
        printf("%c", lines_of_characters[current_char_in_line]);
    }
}

void remove_by_index(char arr[], int index) {
    for (int i = index; i < MAX_CHAR - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int skip_blank_lines(int current_char) { return current_char + 1; }

int remove_trailing_blanks(char lines_of_characters[], int current_char) {
    if (lines_of_characters[current_char] == '\t' ||
        lines_of_characters[current_char] == '\v' ||
        lines_of_characters[current_char] == '\f' ||
        lines_of_characters[current_char] == '\r') {
        remove_by_index(lines_of_characters, current_char);
        if (lines_of_characters[current_char] == '\t') {
            return current_char - 1;
        }
    }

    return current_char;
}
