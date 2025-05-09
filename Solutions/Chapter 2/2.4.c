#include <stdio.h>

#define MAX_LENGTH 100

// Removes from s1 all characters that appear in s2
void squeeze(char[], char[]);

// Deletes character at position i in string s
void delete_char(char[], int);

int main() {
    char s1[MAX_LENGTH] = "1423";
    char s2[MAX_LENGTH] = "345";

    // Show initial state of both strings
    printf("Before:\n");
    printf("  S1: %s\n", s1);
    printf("  S2: %s\n", s2);

    // Perform character filtering
    squeeze(s1, s2);

    // Show final state of strings
    printf("\nAfter squeeze(S1, S2):\n");
    printf("  S1: %s\n", s1); // s1 is now cleaned of characters from s2
    printf("  S2: %s\n", s2); // s2 remains unchanged

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j;

    // Outer loop over each character in s2
    for (i = 0; s2[i] != '\0'; ++i) {
        // Inner loop over s1 — we search for any match with s2[i]
        for (j = 0; s1[j] != '\0'; ++j) {
            if (s1[j] == s2[i]) {
                // If match found, delete the character from s1
                delete_char(s1, j);
                // After deletion, the string is shifted left,
                // so we must re-check the new character at index j
                j--;
            }
        }
    }
}

void delete_char(char s[], int i) {
    // Shift every character after index i one position to the left
    // This overwrites the character at index i
    for (; s[i] != '\0'; ++i) {
        s[i] = s[i + 1];
    }

    // '\0' is also copied implicitly — ensures proper string termination
}
