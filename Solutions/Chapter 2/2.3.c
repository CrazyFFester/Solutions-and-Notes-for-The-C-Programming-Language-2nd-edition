#include <stdio.h>

#define MAX_LENGTH 100

int htoi(char[]);
int calculate_length(const char[]);
char hex_char_to_int(char);
int int_pow(int, int);
int remove_id_chars(int);
int calculate_exp_for_hex_number(int, int);

int main() {
    char string[MAX_LENGTH] = "0x1A3F";

    printf("%d\n", htoi(string));  // Convert hexadecimal string to decimal and print result

    return 0;
}

int htoi(char s[]) {
    int output;
    int real_length_of_string;
    int length_of_string;
    int digit;
    int numeral_system;

    output = 0;

    // Calculate total length of the string
    length_of_string = calculate_length(s);

    // Adjust for "0x" prefix (subtract 2 characters)
    real_length_of_string = remove_id_chars(length_of_string);

    numeral_system = 16;

    // Start from index 2 to skip "0x" and process each hex digit
    for (int i = 2; i < length_of_string; ++i) {
        digit = hex_char_to_int(s[i]);

        // Multiply digit by the appropriate power of 16 based on its position
        output += digit * int_pow(numeral_system,
                                  calculate_exp_for_hex_number(real_length_of_string, i));
    }

    return output;
}

int calculate_length(const char string[]) {
    int length_of_string;

    // Manually compute string length up to MAX_LENGTH
    for (length_of_string = 0; length_of_string < MAX_LENGTH && string[length_of_string] != '\0';
         ++length_of_string) {
    }

    return length_of_string;
}

char hex_char_to_int(char c) {
    // Convert a hexadecimal character (0-9, A-F, a-f) to its integer value
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
        return -1;  // Invalid hex character
    }
}

int int_pow(int base, int exp) {
    int result = 1;

    // Simple integer exponentiation: base raised to exp
    while (exp--) {
        result *= base;
    }

    return result;
}

int remove_id_chars(int length_of_string) {
    // Remove length of "0x" prefix (2 characters)
    return length_of_string - 2;
}

int calculate_exp_for_hex_number(int real_length_of_string, int i) {
    // Calculate exponent for digit at position i (accounting for skipped "0x")
    return (real_length_of_string - 1) - (i - 2);
}
