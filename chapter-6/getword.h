#ifndef GETWORD_H
#define GETWORD_H

#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100
#define BUFSIZE 100 // Buffer size for ungetch

// Function prototypes
int getch(void);
void ungetch(int c);
int getword(char *word, int lim);

#endif // GETWORD_H
