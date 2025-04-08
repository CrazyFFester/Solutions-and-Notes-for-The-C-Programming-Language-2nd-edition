#include <stdio.h>

#define MAX_CHAR 10000

int current_char;               // dsfsdafdsafsdafsdfsdfdsfdsfdsfdsafdsafdsfdsfd
char lines_of_chars[MAX_CHAR];  // sdfsdfdsfsdf
int real_size_of_array;

void collect_data(void);
void remove_comments(void);
void skip_comments(void);
void display_lines(char lines_without_comments[],
                   int current_char_of_lines_without_comments,
                   int real_size_of_lines_without_comments);

int main() {
    collect_data();
    remove_comments();

    printf("\n");

    return 0;
}

void collect_data(void) {
    int c;
    extern int current_char;
    extern char lines_of_chars[];
    extern int real_size_of_array;

    for (current_char = 0;
         (c = getchar()) != EOF && real_size_of_array < MAX_CHAR;
         ++current_char) {
        lines_of_chars[current_char] = c;
        ++real_size_of_array;
    }

    printf("\n");
}

void remove_comments(void) {
    extern char lines_of_chars[];
    extern int current_char;
    extern int real_size_of_array;
    char lines_without_comments[MAX_CHAR];
    int current_char_of_lines_without_comments;
    int real_size_of_lines_without_comments;

    current_char_of_lines_without_comments = 0;
    real_size_of_lines_without_comments = 0;

    for (current_char = 0; current_char < real_size_of_array - 1;
         ++current_char, ++current_char_of_lines_without_comments) {
        skip_comments();

        lines_without_comments[current_char_of_lines_without_comments] =
            lines_of_chars[current_char];
        ++real_size_of_lines_without_comments;
    }

    display_lines(lines_without_comments,
                  current_char_of_lines_without_comments,
                  real_size_of_lines_without_comments);
}

void skip_comments(void) {
    extern int current_char;
    extern int real_size_of_array;
    extern char lines_of_chars[];

    if (current_char != real_size_of_array - 1 &&
        lines_of_chars[current_char] == '/' &&
        lines_of_chars[current_char + 1] == '/') {
        for (; lines_of_chars[current_char] != '\n' &&
               current_char != real_size_of_array - 1;
             ++current_char) {
        }
    }
}

void display_lines(char lines_without_comments[],
                   int current_char_of_lines_without_comments,
                   int real_size_of_lines_without_comments) {
    for (current_char_of_lines_without_comments = 0;
         current_char_of_lines_without_comments <
         real_size_of_lines_without_comments;
         ++current_char_of_lines_without_comments) {
        printf("%c",
               lines_without_comments[current_char_of_lines_without_comments]);
    }
}
