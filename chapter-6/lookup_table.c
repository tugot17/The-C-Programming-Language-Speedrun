// Chapter 6.6

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 + hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    // not found case
    if ((np = lookup(name)) == NULL)
    {
        np = malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *)np->defn);

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    return np;
}

void display_table()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        struct nlist *np = hashtab[i];
        while (np != NULL)
        {
            printf("[%d] Key: %s, Value: %s\n", i, np->name, np->defn);
            np = np->next;
        }
    }
}

void undef(char *name)
{
    struct nlist *current;
    struct nlist *previous = NULL;
    unsigned hashval = hash(name);

    for (current = hashtab[hashval]; current != NULL; previous = current, current = current->next)
    {
        if (strcmp(name, current->name) == 0)
        {
            if (previous == NULL)
            {
                hashtab[hashval] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current->name);
            free(current->defn);
            free(current);
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    install("foo_one", "bar_one");
    install("foo_two", "bar_two");

    printf("Before undef:\n");
    display_table(); // Display all entries

    undef("foo_one"); // Remove "foo_one"
    printf("After undef foo_one:\n");
    display_table(); // Check if "foo_one" has been removed

    undef("foo_two"); // Remove "foo_two"
    printf("After undef foo_two:\n");
    display_table(); // Check if "foo_two" has been removed

    undef("nonexistent_key"); // Test removing a non-existent key
    printf("After undef nonexistent_key:\n");
    display_table(); // No change should occur

    return 0;
}
