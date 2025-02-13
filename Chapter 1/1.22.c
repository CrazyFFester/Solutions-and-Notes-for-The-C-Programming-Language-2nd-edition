#include <stdbool.h>
#include <stdio.h>

#define MAX_CHAR 1000
#define MAX_LINE 50

char lines_of_chars[MAX_CHAR];
int current_char;
int real_size_of_array;
int current_line;

void collect_data(void);
void divide_into_lines(void);
void display_line(int start_of_line, int end_of_line);
bool is_long_line(int current_char_in_line, int start_of_sub_line);

int main() {
    collect_data();
    divide_into_lines();

    printf('\n');

    return 0;
}

void collect_data(void) {
    int c;
    extern char lines_of_chars[];
    extern int current_char;
    extern int real_size_of_array;

    for (current_char = 0; (c = getchar()) != EOF; ++current_char) {
        lines_of_chars[current_char] = c;
        ++real_size_of_array;
    }
}

void divide_into_lines(void) {
    int start_of_line;
    int end_of_line;
    extern int current_line;
    extern int current_char;
    extern int real_size_of_array;
    extern char lines_of_chars[];

    start_of_line = 0;
    current_line = 1;

    for (current_char = 0; current_char < real_size_of_array; ++current_char) {
        if (lines_of_chars[current_char] == '\n') {
            end_of_line = current_char;

            display_line(start_of_line, end_of_line);

            current_line++;
            start_of_line = end_of_line + 1;
        }
    }
}

void display_line(int start_of_line, int end_of_line) {
    extern char lines_of_chars[];
    extern int current_char;
    extern int real_size_of_array;
    extern int current_line;
    int start_of_sub_line;

    start_of_sub_line = start_of_line;

    printf("%d) ", current_line);

    for (int current_char_in_line = start_of_line;
         current_char_in_line < end_of_line; ++current_char_in_line) {
        if (is_long_line(current_char_in_line, start_of_sub_line)) {
            current_line++;

            printf("\n");
            printf("%d) ", current_line);

            start_of_sub_line = current_char_in_line;
        }

        printf("%c", lines_of_chars[current_char_in_line]);
    }

    printf("\n");
}

bool is_long_line(int current_char_in_line, int start_of_sub_line) {
    return (current_char_in_line - start_of_sub_line + 1) > MAX_LINE;
}
