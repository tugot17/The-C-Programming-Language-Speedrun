#include <stdio.h>
#define MAXLINE 100

int get_line();
void copy();

int max;
char line[MAXLINE];
char longest[MAXLINE];

int main(int argc, char const *argv[])
{
    int len;
    // extern int max;
    // extern char longest[];    

    max = 0;

    while ((len = get_line()) > 0)
    {
        if (len > max){
            max = len;
            copy();
        }
    }

    if (max > 0)
        printf("Longest: %s", longest);

    return 0;
}

int get_line(){
    int c, i;
    // extern char line[];

    for (i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        line[i] = c;

    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0'; //we put null character at the end of the line
    return i;
}

void copy(){
    int i;
    // extern char line[], longest[];

    i = 0;

    while((longest[i] = line[i]) != '\0')
        ++i;
}