#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 1000

char lines_of_chars[MAX_CHAR];
int current_char;
int real_size_of_lines;
char paired_symbols[MAX_CHAR];
int real_size_of_paired_symbols = 0;

void collect_data(void);
void divide_into_lines(void);
void delete_balanced_paired_symbols(int index_of_open_symbol, int index_of_close_symbol);
bool are_paired_symbol(void);
void check_are_paired_symbols_balanced(void);
bool is_paired_symbol_balanced(char open_symbol, char close_symbol, int current_paired_symbol);
bool check_order_of_paired_symbols(int index_of_close_symbol, char open_symbol, bool is_open_symbol_before_close);
bool is_unopened_pair(char close_symbol);
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

    for (current_char = 0; current_char < real_size_of_lines; ++current_char)
    {
        if (are_paired_symbol() || current_char == real_size_of_lines - 1)
        {
            check_are_paired_symbols_balanced();
        }


        printf("%c", lines_of_chars[current_char]);
    }
}

void delete_balanced_paired_symbols(int index_of_open_symbol, int index_of_close_symbol)
{
    extern int real_size_of_paired_symbols;
    extern char paired_symbols[];
    int shift;
    int i;

    // printf("\nIndex of open symbol - %d\n", index_of_open_symbol);
    // printf("\nIndex of close symbol - %d\n", index_of_close_symbol);

    for (i = index_of_open_symbol; i < real_size_of_paired_symbols - 1; i++) {
        paired_symbols[i] = paired_symbols[i + 1];
    }

    --index_of_close_symbol;

    for (i = index_of_close_symbol; i < real_size_of_paired_symbols - 1; i++) {
        paired_symbols[i] = paired_symbols[i + 1];
    }
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
    int last_index;
    int current_paired_symbol;
    bool is_open_symbol_before_close;
    int index_of_close_symbol;
    int index_of_open_symbol;

    is_open_symbol_before_close = false;

    ++real_size_of_paired_symbols;
    last_index = real_size_of_paired_symbols - 1;
    paired_symbols[last_index] = lines_of_chars[current_char];

    for (current_paired_symbol = 0; current_paired_symbol < real_size_of_paired_symbols; ++current_paired_symbol)
    {
        if (is_paired_symbol_balanced('(', ')', current_paired_symbol))
        {
            index_of_close_symbol = last_index;
            index_of_open_symbol = current_paired_symbol;
            delete_balanced_paired_symbols(index_of_open_symbol, index_of_close_symbol);
            is_open_symbol_before_close = true;

            break;
        }

        else if (is_paired_symbol_balanced('{', '}', current_paired_symbol))
        {
            index_of_close_symbol = last_index;
            index_of_open_symbol = current_paired_symbol;
            delete_balanced_paired_symbols(index_of_open_symbol, index_of_close_symbol);
            is_open_symbol_before_close = true;

            break;

        }

        else if (is_paired_symbol_balanced('[', ']', current_paired_symbol))
        {
            index_of_close_symbol = last_index;
            index_of_open_symbol = current_paired_symbol;
            delete_balanced_paired_symbols(index_of_open_symbol, index_of_close_symbol);
            is_open_symbol_before_close = true;

            break;

        }

        else if (is_unopened_pair(')'))
        {
            printf("\n There is not opened parenthesis");
            exit(1);
        }

        else if (is_unopened_pair('}'))
        {
            printf("\n There is not opened brackets");
            exit(1);
        }

        else if (is_unopened_pair(']'))
        {
            printf("\n There is not opened braces");
        }

        else if (current_char == real_size_of_lines - 1)
        {
            if (is_unclosed_pair('('))
            {
                printf("\nThere is not closed parenthesis\n");
                exit(1);
            }
            else if (is_unclosed_pair('{'))
            {
                printf("\nThere is not closed brackets\n");
                exit(1);
            }
            else if (is_unclosed_pair('['))
            {
                printf("\nThere is not closed braces\n");
                exit(1);
            }
        }
        // TODO: Добавить ", ' знаки
    }
}

bool is_unclosed_pair(char open_symbol)
{
    extern char paired_symbols[];

    return paired_symbols[0] == open_symbol;
}

bool is_unopened_pair(char close_symbol)
{
    extern char lines_of_chars[];
    extern int current_char;

    return lines_of_chars[current_char] == close_symbol;
}

bool is_paired_symbol_balanced(char open_symbol, char close_symbol, int current_paired_symbol)
{
    extern char lines_of_chars[];
    extern int current_char;
    extern char paired_symbols[];

    return lines_of_chars[current_char] == close_symbol && paired_symbols[current_paired_symbol] == open_symbol;
}

bool check_order_of_paired_symbols(int index_of_close_symbol, char open_symbol, bool is_open_symbol_before_close)
{
    int current_index_before_close_symbol;
    extern char paired_symbols[];
    int index_of_open_symbol;

    for (current_index_before_close_symbol = 0; current_index_before_close_symbol < index_of_close_symbol;
        ++current_index_before_close_symbol)
    {
        if (paired_symbols[current_index_before_close_symbol] == open_symbol)
        {
            index_of_open_symbol = current_index_before_close_symbol;
            is_open_symbol_before_close = true;
            delete_balanced_paired_symbols(index_of_open_symbol, index_of_close_symbol);
        }
    }

    return is_open_symbol_before_close;
}