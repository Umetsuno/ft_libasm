#include <stdio.h>
#include <stdlib.h>

extern char* ft_strdup(const char*);

int main() {
    const char* original = "Hello, world!";
    char* duplicate = ft_strdup(original);

    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);

    free(duplicate);

    return 0;
}