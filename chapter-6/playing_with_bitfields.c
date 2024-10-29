#include <stdio.h>

struct StatusFlags
{
    unsigned int is_visible : 1; // 1 bit
    unsigned int is_enabled : 1; // 1 bit
    unsigned int is_error : 1;   // 1 bit
    unsigned int reserved : 5;   // 5 bits for future use
};

int main()
{
    struct StatusFlags flags = {0};

    flags.is_visible = 1; // Set the visibility flag
    flags.is_enabled = 1; // Set the enabled flag

    printf("Visibility: %d\n", flags.is_visible);
    printf("Enabled: %d\n", flags.is_enabled);
    printf("Error: %d\n", flags.is_error);

    return 0;
}
