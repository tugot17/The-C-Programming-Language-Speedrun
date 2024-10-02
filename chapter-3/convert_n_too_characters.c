// Exercise 3.4
#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


void itoa(int n, char s[])
{
    int i, sign;
    unsigned int num;

    if (n == INT_MIN) {
        num = (unsigned int)INT_MAX + 1;
    } else {
        num = (n < 0) ? -n : n; 
    }

    i = 0;
    do{
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (n <0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main(int argc, char const *argv[])
{
    int n = -2147483648;
    char str[20];

    itoa(n, str);

    printf("Converted string: %s\n", str);
}
