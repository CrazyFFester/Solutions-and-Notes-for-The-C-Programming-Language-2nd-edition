#include <stdbool.h>
#include <stdio.h>

#define MAX_CHAR 1000
#define LENGHT_VALID_LINE 80

void collecting_data(char lines_characters[], int current_char);
void division_into_lines(int current_char, char lines_characters[]);
void display_line(int current_line, int line_lenght, int start_of_line,
                  int end_of_line, char lines_characters[]);
int skip_newline_character(int current_char);
bool is_valid_line(int line_lenght);
bool is_newline_character(char current_char);

int main() {
    int current_char;
    char lines_characters[MAX_CHAR] = {};

    collecting_data(lines_characters, current_char);

    division_into_lines(current_char, lines_characters);
}

void collecting_data(char lines_characters[], int current_char) {
    int c;

    for (current_char = 0; (c = getchar()) != EOF; ++current_char) {
        lines_characters[current_char] = c;
    }
}

void division_into_lines(int current_char, char lines_characters[]) {
    int start_of_line;
    int current_line;
    int line_lenght;
    int end_of_line;

    current_line = 0;
    start_of_line = 0;

    for (current_char = 0; current_char < MAX_CHAR; ++current_char) {
        if (is_newline_character(lines_characters[current_char])) {
            end_of_line = current_char;
            line_lenght = end_of_line - start_of_line;

            if (is_valid_line(line_lenght)) {
                display_line(current_line, line_lenght, start_of_line,
                             end_of_line, lines_characters);
            }

            ++current_line;
            start_of_line = skip_newline_character(current_char);
        }
    }
}

void display_line(int current_line, int line_lenght, int start_of_line,
                  int end_of_line, char lines_characters[]) {
    printf("%d) %d chracters - ", current_line + 1, line_lenght);

    for (int current_char_in_line = start_of_line;
         current_char_in_line <= end_of_line; ++current_char_in_line) {
        printf("%c", lines_characters[current_char_in_line]);
    }

    printf("\n");
}

int skip_newline_character(int current_char) { return current_char + 1; }

bool is_valid_line(int line_lenght) { return line_lenght > LENGHT_VALID_LINE; }

bool is_newline_character(char current_char) { return (current_char == '\n'); }
