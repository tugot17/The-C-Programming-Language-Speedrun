#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100 // Buffer size for ungetch
#define NKEYS (sizeof(keytab) / sizeof(struct key)) // Number of keywords

struct key {
    char *word;
    int count;
} keytab[] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue", 0 },
    { "default", 0 },
    { "unsigned", 0 },
    { "void", 0 },
    { "volatile", 0 },
    { "while", 0 }
};

char buf[BUFSIZE]; // Buffer for ungetch
int bufp = 0;      // Next free position in buf

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        *w = getch(); // Get the next character
        if (!isalnum(*w)) { // If not alphanumeric
            ungetch(*w); // Push it back
            break;
        }
    }
    
    *w = '\0'; // Null-terminate the string
    return word[0]; // Return the first character of the word
}

struct key *binsearch(char *word, struct key tab[], int n) {
    struct key *low = tab;
    struct key *high = tab + n -1;
    struct key *mid;

    int cond;


    while (low <= high) {
        mid = low + (high - low) / 2; 

        int cond = strcmp(word, mid->word);

        if (cond == 0)
            return mid; //we found the word
        else if (cond < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return NULL; // Not found
}

int main() {
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
        }
    }

    for(p = keytab; p < keytab + NKEYS; p++)
        if (p->count >0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}
