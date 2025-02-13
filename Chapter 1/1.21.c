#include <stdbool.h>
#include <stdio.h>

#define MAX_CHAR 1000

int current_char;
char lines_of_chars[MAX_CHAR];
int real_size_of_array;

void collect_data(void);
void divide_into_lines(void);
void replace_blank_line_with_tabs(void);
void display_line(int start_of_line, int current_line, int end_of_line);
bool is_not_last_char(void);
bool is_blank_line(void);

int main() {
    collect_data();
    divide_into_lines();

    return 0;
}

void collect_data(void) {
    int c;
    extern int current_char;
    extern char lines_of_chars[];
    extern int real_size_of_array;

    for (current_char = 0; (c = getchar()) != EOF; ++current_char) {
        lines_of_chars[current_char] = c;
        ++real_size_of_array;
    }

    printf("\n");
}

void divide_into_lines(void) {
    extern int real_size_of_array;
    extern char lines_of_chars[];
    extern int current_char;
    int start_of_line;
    int end_of_lines;
    int current_line;

    start_of_line = 0;
    current_line = 1;

    for (current_char = 0; current_char < real_size_of_array; ++current_char) {
        replace_blank_line_with_tabs();

        if (lines_of_chars[current_char] == '\n') {
            end_of_lines = current_char;

            display_line(start_of_line, current_line, end_of_lines);

            start_of_line = end_of_lines + 1;
            ++current_line;
        }
    }

    printf("\n");
}

void replace_blank_line_with_tabs(void) {
    extern int current_char;
    extern char lines_of_chars[];
    extern int real_size_of_array;

    if (is_not_last_char() && is_blank_line()) {
        lines_of_chars[current_char] = '\t';
    }
}

void display_line(int start_of_line, int current_line, int end_of_line) {
    extern int real_size_of_array;

    printf("%d) ");

    for (int current_char_in_line = start_of_line;
         current_char_in_line < end_of_line; ++current_char_in_line) {
        printf("%c", lines_of_chars[current_char_in_line]);
    }

    printf("\n");
}

bool is_not_last_char(void) {
    extern int current_char;
    extern int real_size_of_array;

    return current_char != real_size_of_array - 1;
}

bool is_blank_line(void) {
    extern char lines_of_chars[];
    extern int current_char;

    return lines_of_chars[current_char] == '\n' &&
           lines_of_chars[current_char + 1] == '\n';
}
