//Exercise 4.1
#include <stdio.h>
#include <string.h>


int strindex(char s[] , char t){
    for(int i =0; i < strlen(s); i++)
        if (s[i] == t)
            return i;

    return -1;
}

int main(int argc, char const *argv[])
{
    char str[] = "My name is Piotr";
    char letter = 'r';

    int index = strindex(str, letter);

    if (index == -1)
        printf("No character %c in your string \"%s\"\n", letter, str);
    else
        printf("Character \"%c\" at index %d in your string \"%s\"\n", letter, index, str);

    return 0;
}
