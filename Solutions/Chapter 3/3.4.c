#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

static void itoa(int n, char s[]);
static void reverse(char s[]);

int main(void)
{
    char s[MAX_LENGTH];
    int n = 52;

    itoa(n, s);

    printf("%s\n", s);

    return 0;
}

static void itoa(int n, char s[])
{
    int i = 0;
    int sign = n;

    // Keep n negative to avoid overflow when n == INT_MIN.
    // In two's complement, |INT_MIN| cannot be represented as a positive int.
    if (n > 0)
    {
        n = -n;
    }

    do
    {
        // Extract digits from the right. For negative n, (n % 10) is negative,
        // so we negate it to get a value in the range 0..9.
        int digit = -(n % 10);

        s[i++] = (char)('0' + digit);
        n /= 10;
    } while (n < 0);

    // Append the sign after processing all digits.
    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    // Digits are generated in reverse order, so reverse the string in place.
    reverse(s);
}

static void reverse(char s[])
{
    size_t left = 0;
    size_t right = strlen(s);

    // If the string is empty, there is nothing to reverse.
    if (right == 0)
    {
        return;
    }
    right--; // Point to the last character, not the null terminator.

    while (left < right)
    {
        // Swap characters from both ends, moving towards the center.
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}
