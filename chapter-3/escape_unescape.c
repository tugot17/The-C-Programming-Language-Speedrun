#include <stdio.h>

void escape(char s[], const char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], const char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main()
{
    char t[] = "Hello\tWorld\nHow are you?";
    char s[100];
    
    escape(s, t);
    printf("Original: %s\n", t);
    printf("Escaped: %s\n", s);
    
    char u[100];
    unescape(u, s);
    printf("Unescaped: %s\n", u);
    
    return 0;
}