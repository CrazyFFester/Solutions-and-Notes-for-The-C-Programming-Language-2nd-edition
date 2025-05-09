#include <stdio.h>

#define MAX_LENGTH 100

// Returns the index of the first character in s1 that matches any character in s2.
// Returns -1 if there is no such character.
int any(const char[], const char[]);

int main() {
    const char s1[MAX_LENGTH] = "12345";
    const char s2[MAX_LENGTH] = "34567";

    // Test the any() function and print the result.
    // Expected output: 2, since '3' is the first common character at index 2 in s1.
    printf("%d position\n", any(s1, s2));

    return 0;
}

int any(const char s1[], const char s2[]) {
    // Iterate over each character in s1
    for (int i = 0; s1[i] != '\0'; ++i) {
        // For each character in s1, scan all of s2
        for (int j = 0; s2[j] != '\0' ; ++j) {
            // If current character from s1 is found in s2, return its index immediately
            // This ensures we return the *first* such position, as required by the task
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    // If loop completes without finding any match, return -1
    // This signals that no characters in s1 appear in s2
    return -1;
}