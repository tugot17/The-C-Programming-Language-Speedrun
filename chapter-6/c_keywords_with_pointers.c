//gcc c_keywords_with_pointers.c getword.c

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getword.h"
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
