#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1000

int collecting_data(char lines_of_characters[], int current_char,
                    int size_of_real_array);
void divide_into_lines(char lines_of_characters[], int current_char,
                       int size_of_real_array);
void reverse(char s[], int size_of_s);

int main() {
    char lines_of_characters[MAX_CHAR] = {};
    int size_of_real_array;
    int current_char;

    current_char = 0;
    size_of_real_array = 0;

    size_of_real_array =
        collecting_data(lines_of_characters, current_char, size_of_real_array);
    divide_into_lines(lines_of_characters, current_char, size_of_real_array);

    return 0;
}

int collecting_data(char lines_of_characters[], int current_char,
                    int size_of_real_array) {
    int c;

    for (current_char = 0; (c = getchar()) != EOF; ++current_char) {
        lines_of_characters[current_char] = c;
        ++size_of_real_array;
    }

    return size_of_real_array;
}

void divide_into_lines(char lines_of_characters[], int current_char,
                       int size_of_real_array) {
    int start_of_line;
    int end_of_line;
    int current_line;
    char temp_line[MAX_CHAR] = {};
    int size_of_temp_array;

    start_of_line = 0;
    size_of_temp_array = 0;

    for (current_char = 0; current_char < size_of_real_array; ++current_char) {
        if (lines_of_characters[current_char] != '\n') {
            temp_line[current_char] = lines_of_characters[current_char];
            ++size_of_temp_array;
        } else {
            reverse(temp_line, size_of_real_array);
            memset(temp_line, 0, sizeof(temp_line));
        }
    }
}

void reverse(char s[], int size_of_s) {
    int current_line;

    current_line = 1;
    for (int current_char_in_line = size_of_s - 1; current_char_in_line >= 0;
         --current_char_in_line) {
        printf("%c", s[current_char_in_line]);
    }
    printf("\n");
}
