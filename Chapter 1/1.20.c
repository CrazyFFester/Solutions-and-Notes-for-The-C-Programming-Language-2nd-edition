#include <stdio.h>

#define MAX_CHAR 1000
#define SPACE ' '
#define SPACES_IN_TAB 4
#define NEW_LINE '\n'
#define TAB '\t'

int current_char;
char lines_of_characters[MAX_CHAR] = {};
int real_size_loc;

void collect_data(void);
void divide_into_lines(void);
void insert_item(char symbol, int count);
void display_lines(int current_line, int start_of_line, int end_of_line);
void check_for_tabs(void);
int number_chars_after_tab(int original_current_char);
void save_chars_after_tab(char temp_array[], int i, int original_current_char);
void return_saved_chars(int i, char temp_array[]);

int main() {
    collect_data();
    divide_into_lines();
}

void collect_data(void) {
    extern int current_char;
    extern char lines_of_characters[];
    int c;

    c = 0;

    for (current_char = 0; (c = getchar()) != EOF; ++current_char) {
        lines_of_characters[current_char] = c;
        ++real_size_loc;
    }

    printf("\n");
}

void divide_into_lines(void) {
    int start_of_line;
    int end_of_line;
    extern int current_char;
    extern char lines_of_characters[];
    int current_line;

    start_of_line = 0;
    current_line = 1;

    for (current_char = 0; current_char < real_size_loc; ++current_char) {
        check_for_tabs();

        if (lines_of_characters[current_char] == NEW_LINE) {
            end_of_line = current_char;

            display_lines(current_line, start_of_line, end_of_line);

            ++current_line;
            start_of_line = end_of_line + 1;
        }
    }
}

void insert_item(char symbol, int count) {
    extern int current_char;
    extern char lines_of_characters[];
    char temp_array[MAX_CHAR] = {};
    int original_current_char;
    int i;

    original_current_char = current_char;
    i = 0;

    save_chars_after_tab(temp_array, i, original_current_char);

    for (; current_char < (original_current_char + count); ++current_char) {
        lines_of_characters[current_char] = symbol;
        ++real_size_loc;
    }

    return_saved_chars(i, temp_array);

    current_char = original_current_char + (count - 1);
}

void display_lines(int current_line, int start_of_line, int end_of_line) {
    extern char lines_of_characters[];

    printf("%d) ", current_line);

    for (int current_char_in_line = start_of_line;
         current_char_in_line <= end_of_line; ++current_char_in_line) {
        printf("%c", lines_of_characters[current_char_in_line]);
    }
}

void check_for_tabs(void) {
    extern int current_char;
    extern char lines_of_characters[];

    if (lines_of_characters[current_char] == TAB) {
        insert_item(SPACE, SPACES_IN_TAB);
    }
}

int number_chars_after_tab(int original_current_char) {
    extern int real_size_loc;

    return real_size_loc - original_current_char;
}

void save_chars_after_tab(char temp_array[], int i, int original_current_char) {
    extern int current_char;
    extern char lines_of_characters[];

    for (i = 0; i < number_chars_after_tab(original_current_char);
         ++i, ++current_char) {
        temp_array[i] = lines_of_characters[current_char + 1];
    }

    current_char = original_current_char;
}

void return_saved_chars(int i, char temp_array[]) {
    extern int current_char;
    extern int real_size_loc;
    extern char lines_of_characters[];

    for (i = 0; current_char < real_size_loc - 1; ++i, ++current_char) {
        lines_of_characters[current_char] = temp_array[i];
    }
}
