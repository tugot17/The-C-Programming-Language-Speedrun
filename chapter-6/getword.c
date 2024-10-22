#include "getword.h"

static char buf[BUFSIZE]; // Buffer for ungetch
static int bufp = 0;      // Next free position in buf

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
