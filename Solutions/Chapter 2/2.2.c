#include <stdio.h>

int main()
{
    int i;
    char c;
    const int lim = 10;
    char s[lim];

    for (i = 0; (i < lim-1) + ((c = getchar()) != '\n') + (c != EOF) == 3; ++i)
    {
        s[i] = c;
    }

    s[i] = '\0';

    printf("%s\n",s);
}