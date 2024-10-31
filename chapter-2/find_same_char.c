#include <stdio.h>
#include <stdbool.h>

#define ASCII_SIZE 256

int any(const char *s1, const char *s2) {
    bool char_set[ASCII_SIZE] = {false};
    
    // Mark all characters from s2 in our lookup table
    for (int i = 0; s2[i] != '\0'; i++) {
        char_set[(unsigned char)s2[i]] = true;
    }
    
    // Check each character of s1 against our lookup table
    for (int i = 0; s1[i] != '\0'; i++) {
        if (char_set[(unsigned char)s1[i]]) {
            return i;  // Found a match, return the index
        }
    }
    
    return -1;  // No match found
}

int main() {
    const char *s1 = "hello world";
    const char *s2 = "aeiou";
    int result = any(s1, s2);
    
    if (result != -1) {
        printf("First match found at index %d\n", result);
    } else {
        printf("No match found\n");
    }
    
    return 0;
}