void escape(const char s[], char t[])
{
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        default:
            t[j++] = s[i];
            break;
        }
    }

    t[j] = '\0';
}

void unescape(const char s[], char t[])
{
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '\\':
            switch (s[++i])
            {
            case 't':
                t[j++] = '\t';
                break;
            case 'n':
                t[j++] = '\n';
                break;

            default:
                t[j++] = s[i];
                break;
            }
            break;

        default:
            t[j++] = s[i];
            break;
        }
    }

    t[j] = '\0';
}
