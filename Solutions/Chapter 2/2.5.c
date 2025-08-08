#include <stdio.h>

#define MAX_LENGTH 100

// Return index of first char from s1 found in s2, or -1.
int any(const char[], const char[]);

int main()
{
    const char s1[MAX_LENGTH] = "12345";
    const char s2[MAX_LENGTH] = "34567";

    // Should print 2 (0-based index).
    printf("%d position\n", any(s1, s2));

    return 0;
}

int any(const char s1[], const char s2[])
{
    for (int i = 0; s1[i] != '\0'; ++i)
    {
        for (int j = 0; s2[j] != '\0'; ++j)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    // No common character
    return -1;
}
