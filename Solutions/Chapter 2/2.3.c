/* TODO:
 * 1) Make code cleaner
 * 2) delete global variable and define it in function
 * 3) rename variable and function if it needs
 * 4) make htoi return int (output) value and print result in main function
 * 5) read more about char ;))
*/

#include <stdio.h>

#define MAX_LENGTH 100

int length_of_string;

void htoi(char[]);
void calculate_length(const char[]);
char hex_char_to_int(char);
int ipow(int, int);

int main() {
    char string[MAX_LENGTH] = "0x1A3F";

    calculate_length(string);
    htoi(string);

    printf("\n");

    return 0;
}

void htoi(char s[]) {
    int output;
    int real_length_of_string;
    int digit;

    output = 0;
    real_length_of_string = length_of_string - 2;

    for (int i = 2; i < length_of_string; ++i) {
        digit = hex_char_to_int(s[i]);
        output += (int)(digit * ipow(16, (real_length_of_string - 1) - (i - 2)));
    }

    printf("%d", output);
}

void calculate_length(const char string[]) {
    for (length_of_string = 0; length_of_string < MAX_LENGTH && string[length_of_string] != '\0';
         ++length_of_string) {
    }
}

char hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    else {
        return -1;
    }
}

int ipow(int base, int exp) {
    int result;

    result = 1;

    while (exp--) {
        result *= base;
    }

    return result;
}