#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 1000

char lines_of_chars[MAX_CHAR];
int current_char;
int real_size_of_lines;
char paired_symbols[MAX_CHAR];
int real_size_of_paired_symbols = 0;
int current_paired_symbol;
int index_of_close_symbol;
int index_of_open_symbol;
int last_index;

void collect_data(void);
void divide_into_lines(void);
bool are_paired_symbol(void);
void check_are_paired_symbols_balanced(void);
void find_pair_for_balanced_symbol(void);
bool is_paired_symbol_balanced(char open_symbol, char close_symbol);
void delete_balanced_paired_symbols(void);
bool is_unopened_pair(char close_symbol);
void check_unclosed_symbols(void);
bool is_unclosed_pair(char open_symbol);

int main(void)
{
    collect_data();
    divide_into_lines();

    return 0;
}

void collect_data(void)
{
    extern int current_char;
    extern int real_size_of_lines;
    extern char lines_of_chars[];
    int c;

    for (current_char = 0; (c = getchar()) != EOF && real_size_of_lines < MAX_CHAR; ++current_char)
    {
        lines_of_chars[current_char] = c;
        ++real_size_of_lines;
    }

    printf("\n");
}

void divide_into_lines(void)
{
    extern int current_char;
    extern int real_size_of_lines;
    extern char lines_of_chars[];

    for (current_char = 0; current_char < real_size_of_lines - 1; ++current_char)
    {
        if (are_paired_symbol())
        {
            check_are_paired_symbols_balanced();
        }

        printf("%c", lines_of_chars[current_char]);
    }

    check_unclosed_symbols();
}

bool are_paired_symbol(void)
{
    extern char lines_of_chars[];
    extern int current_char;

    return lines_of_chars[current_char] == '(' || lines_of_chars[current_char] == ')' ||
            lines_of_chars[current_char] == '"' || lines_of_chars[current_char] == '{' ||
            lines_of_chars[current_char] == '}' || lines_of_chars[current_char] == '[' ||
            lines_of_chars[current_char] == ']' || lines_of_chars[current_char] == '\'';
}

void check_are_paired_symbols_balanced(void)
{
    extern char paired_symbols[];
    extern int real_size_of_paired_symbols;
    extern char lines_of_chars[];
    extern int current_char;

    ++real_size_of_paired_symbols;
    last_index = real_size_of_paired_symbols - 1;
    paired_symbols[last_index] = lines_of_chars[current_char];

    find_pair_for_balanced_symbol();

    // TODO: Засунуть код ниже в функцию
    if (is_unopened_pair(')'))
    {
        printf("%c", lines_of_chars[current_char]);
        printf("\n There is not opened parenthesis");
        exit(1);
    }

    else if (is_unopened_pair('}'))
    {
        printf("%c", lines_of_chars[current_char]);
        printf("\n There is not opened brackets");
        exit(1);
    }

    else if (is_unopened_pair(']'))
    {
        printf("%c", lines_of_chars[current_char]);
        printf("\n There is not opened braces");
        exit(1);
    }
}

void find_pair_for_balanced_symbol(void)
{
    extern int current_paired_symbol;
    extern int real_size_of_paired_symbols;
    extern int index_of_close_symbol;
    extern int index_of_open_symbol;
    extern int last_index;

    // TODO: Добавить ", ' знаки
    for (current_paired_symbol = 0; current_paired_symbol < real_size_of_paired_symbols; ++current_paired_symbol)
    {
        if (is_paired_symbol_balanced('(', ')'))
        {
            index_of_close_symbol = last_index;
            index_of_open_symbol = current_paired_symbol;
            delete_balanced_paired_symbols();

            return;
        }

        else if (is_paired_symbol_balanced('{', '}'))
        {
            index_of_close_symbol = last_index;
            index_of_open_symbol = current_paired_symbol;
            delete_balanced_paired_symbols();

            return;
        }

        else if (is_paired_symbol_balanced('[', ']'))
        {
            index_of_close_symbol = last_index;
            index_of_open_symbol = current_paired_symbol;
            delete_balanced_paired_symbols();

            return;
        }
    }
}

bool is_paired_symbol_balanced(char open_symbol, char close_symbol)
{
    extern char lines_of_chars[];
    extern int current_char;
    extern char paired_symbols[];

    return lines_of_chars[current_char] == close_symbol && paired_symbols[current_paired_symbol] == open_symbol;
}

void delete_balanced_paired_symbols(void)
{
    extern int real_size_of_paired_symbols;
    extern char paired_symbols[];
    int shift;
    int i;


    for (i = index_of_open_symbol; i < real_size_of_paired_symbols; i++) {
        paired_symbols[i] = paired_symbols[i + 1];
    }

    --real_size_of_paired_symbols;
    --index_of_close_symbol;

    for (i = index_of_close_symbol; i < real_size_of_paired_symbols; i++) {
        paired_symbols[i] = paired_symbols[i + 1];
    }

    --real_size_of_paired_symbols;
}

bool is_unopened_pair(char close_symbol)
{
    extern char lines_of_chars[];
    extern int current_char;

    return lines_of_chars[current_char] == close_symbol;
}

void check_unclosed_symbols(void)
{
    if (is_unclosed_pair('('))
    {
        printf("\nThere is not closed parenthesis\n");
    }

    else if (is_unclosed_pair('{'))
    {
        printf("\nThere is not closed brackets\n");
    }

    else if (is_unclosed_pair('['))
    {
        printf("\nThere is not closed braces\n");
    }
}

bool is_unclosed_pair(char open_symbol)
{
    extern char paired_symbols[];

    return paired_symbols[0] == open_symbol;
}