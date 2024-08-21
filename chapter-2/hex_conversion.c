#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(const char *s){
    int result = 0;
    int i = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i=2; 
    
    while (s[i] != '\0')
    {
        result *= 16;

        if (isdigit(s[i]))
            result += s[i] - '0';

        else if (s[i] >= 'a' && s[i] <= 'f'){
            result += s[i] - 'a' + 10;
        }

        else if (s[i] >= 'A' && s[i] <= 'F'){
            result += s[i] - 'A' + 10;
        }

        else
            return -1;

        i++;
    }
    return result;    
}

int main(int argc, char const *argv[])
{
    const char *test_cases[] = {"0x1A", "0X1a", "FF", "100", "abc", "0x1G"};
    int num_tests = sizeof(test_cases)/sizeof(test_cases[0]);

    for (int i=0; i < num_tests; ++i){
        int result = htoi(test_cases[i]);

        if (result != -1)
            printf("%s -> %d\n", test_cases[0], result);
        else
            printf("%s -> Error: Invalid hexadecimal string\n", test_cases[i]);
    }

    return 0;
}
