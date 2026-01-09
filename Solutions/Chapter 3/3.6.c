#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

static void itoa(int n, char s[], int width);
static void reverse(char s[]);

int main(void)
{
    char s[MAX_LENGTH];
    int n = 52;
    int width = 3;

    itoa(n, s, width);

    printf("%s\n", s);

    return 0;
}

static void itoa(int n, char s[], int width)
{
    int i = 0;
    int sign = n;

    // Work with a negative value to safely handle INT_MIN.
    // Negating INT_MIN would overflow, so we keep n negative
    // and extract digits from it directly.
    if (n > 0)
    {
        n = -n;
    }

    do
    {
        // Extract the least significant digit.
        // For negative n, (n % 10) is negative, so we negate it
        // to obtain a digit in the range 0..9.
        int digit = -(n % 10);

        s[i++] = (char)('0' + digit);

        // Remove the processed digit.
        n /= 10;
    } while (n < 0);

    // Append the minus sign after all digits are processed.
    if (sign < 0)
    {
        s[i++] = '-';
    }

    // Pad with leading blanks until the minimum field width is reached.
    // Padding is added before reversing, so blanks end up on the left.
    while (i < width)
    {
        s[i++] = ' ';
    }

    s[i] = '\0';

    // Digits and padding were generated in reverse order,
    // so reverse the string to obtain the final result.
    reverse(s);
}

static void reverse(char s[])
{
    size_t left = 0;
    size_t right = strlen(s);

    // An empty string needs no reversal.
    if (right == 0)
    {
        return;
    }

    // Move right to the last character, not the null terminator.
    right--;

    while (left < right)
    {
        // Swap characters from both ends and move towards the center.
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}
