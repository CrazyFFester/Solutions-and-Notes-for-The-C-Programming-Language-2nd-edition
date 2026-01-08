#include <stdio.h>

#define MAX_LENGTH 100

static void expand(const char s1[], char s2[]);

static int same_class_range(char start, char end);
static int can_expand_at(const char s1[], int i);
static int append_range(char s2[], int *j, char start, char end);
static int append_char(char s2[], int *j, char c);

static int is_lower_pair(char start, char end);
static int is_upper_pair(char start, char end);
static int is_digit_pair(char start, char end);

int main(void)
{
    char s1[] = "-A-Z0-9";
    char s2[MAX_LENGTH];

    expand(s1, s2);

    for (int i = 0; s2[i] != '\0'; i++)
    {
        printf("%c", s2[i]);
    }

    return 0;
}

static void expand(const char s1[], char s2[])
{
    int j = 0;
    /* Invariant: s2[0..j-1] always contains a valid, already built prefix */

    for (int i = 0; s1[i] != '\0'; i++)
    {
        /* A hyphen is treated as a range operator only when it has
           valid, compatible characters on both sides */
        if (can_expand_at(s1, i))
        {
            char start = s1[i - 1];
            char end = s1[i + 1];

            /* The left boundary was already copied earlier,
               so start from start + 1 to avoid duplication */
            if (!append_range(s2, &j, start, end))
            {
                break;
            }

            /* Skip the right boundary in the input string,
               since it has already been appended */
            i++;
        }
        else
        {
            /* Any character that is not part of a valid range
               is copied literally */
            if (!append_char(s2, &j, s1[i]))
            {
                break;
            }
        }
    }

    /* Single null-termination point guarantees a valid C string
       regardless of how the loop exits */
    s2[j] = '\0';
}

static int same_class_range(char start, char end)
{
    /* Reverse ranges (e.g. z-a, 9-0) are intentionally rejected */
    if (start >= end)
    {
        return 0;
    }

    /* A range is valid only within the same character class */
    return is_lower_pair(start, end) || is_upper_pair(start, end) || is_digit_pair(start, end);
}

static int is_lower_pair(char start, char end) { return start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z'; }

static int is_upper_pair(char start, char end) { return start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z'; }

static int is_digit_pair(char start, char end) { return start >= '0' && start <= '9' && end >= '0' && end <= '9'; }

static int can_expand_at(const char s1[], int i)
{
    /* A range is possible only if:
       - the current character is '-'
       - there is a character on the left
       - there is a character on the right
       - both endpoints form a valid range */
    return s1[i] == '-' && i > 0 && s1[i + 1] != '\0' && same_class_range(s1[i - 1], s1[i + 1]);
}

static int append_range(char s2[], int *j, char start, char end)
{
    /* Expand the range strictly in ascending character order */
    for (char c = start + 1; c <= end; c++)
    {
        if (!append_char(s2, j, c))
        {
            return 0;
        }
    }
    return 1;
}

static int append_char(char s2[], int *j, char c)
{
    /* Always leave space for the terminating null character */
    if (*j >= MAX_LENGTH - 1)
    {
        return 0;
    }

    s2[(*j)++] = c;
    return 1;
}
