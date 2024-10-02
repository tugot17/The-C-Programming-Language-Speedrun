#include <stdio.h>
#include <string.h>

void trim(char s[]){
    int n;

    for (n = strlen(s)-1; n >=0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;

        s[n] = '\0';
}

int main(int argc, char const *argv[])
{
    char str[] = "wsdsdn  dsdsdkk  dsdsds  ";
    trim(str);

    printf("Trimmed string: %s xxx\n", str);

    return 0;
}
