#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

static void itob(int n, char s[], int b);
static char digit_to_char(int digit);
static void reverse(char s[]);

int main(void)
{
    char s[MAX_LENGTH];
    int n = 255;
    int b = 2;

    itob(n, s, b);

    printf("%s\n", s);
    printf("%d\n", (255 % 16));

    return 0;
}

static void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = n;

    // Validate the base: this implementation supports bases from 2 to 36,
    // using digits 0–9 and letters a–z.
    if (b < 2 || b > 36)
    {
        s[0] = '\0';
        return;
    }

    // Keep n negative to safely handle INT_MIN.
    // Negating INT_MIN would overflow, so we work with negative values only.
    if (n > 0)
    {
        n = -n;
    }

    do
    {
        // Extract the least significant digit in the given base.
        // For negative n, (n % b) is negative, so we negate it to get 0..(b-1).
        int digit = -(n % b);

        // Convert the numeric digit to its character representation.
        s[i++] = digit_to_char(digit);

        // Remove the processed digit.
        n /= b;
    } while (n < 0);

    // Append the minus sign after processing all digits.
    if (sign < 0)
    {
        s[i++] = '-';
    }

    s[i] = '\0';

    // Digits were generated in reverse order, so reverse the string in place.
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

    // Point to the last character, not the null terminator.
    right--;

    while (left < right)
    {
        // Swap characters from both ends, moving towards the center.
        char tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
}

static char digit_to_char(int digit)
{
    // Map numeric digits to characters:
    // 0–9  -> '0'–'9'
    // 10–35 -> 'a'–'z'
    return (digit < 10) ? (char)('0' + digit) : (char)('a' + (digit - 10));
}
