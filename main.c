#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

extern void ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *string1, const char *string2);

int main() {
    /* Set test file */
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char output[64];
    sprintf(output, "test-%d-%02d-%02d-%02d-%02d-%02d.txt", 
          tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, 
          tm->tm_hour, tm->tm_min, tm->tm_sec);

    /* ft_strlen 64 bits Intel */
    int fd = open(output, O_WRONLY|O_CREAT|O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
  }

    int errors = 0;

    char str1[] = "";
    size_t len1 = strlen(str1);
    if (len1 != 0) {
        dprintf(fd, "Test 1 failed: '%s' -> %zu\n", str1, len1);
        errors++;
    } else {
        dprintf(fd, "Test 1 passed: '%s' -> %zu\n", str1, len1);
    }

    char str2[] = "Hello, world!";
    size_t len2 = strlen(str2);
    if (len2 != 13) {
        dprintf(fd, "Test 2 failed: '%s' -> %zu\n", str2, len2);
        errors++;
    } else {
        dprintf(fd, "Test 2 passed: '%s' -> %zu\n", str2, len2);
    }

    char str3[] = "1234567890";
    size_t len3 = strlen(str3);
    if (len3 != 10) {
        dprintf(fd, "Test 3 failed: '%s' -> %zu\n", str3, len3);
        errors++;
    } else {
        dprintf(fd, "Test 3 passed: '%s' -> %zu\n", str3, len3);
    }

    char str4[] = "abcdefghijklmnopqrstuvwxyz";
    size_t len4 = strlen(str4);
    if (len4 != 26) {
        dprintf(fd, "Test 4 failed: '%s' -> %zu\n", str4, len4);
        errors++;
    } else {
        dprintf(fd, "Test 4 passed: '%s' -> %zu\n", str4, len4);
    }

    char str5[] = "The quick brown fox jumps over the lazy dog";
    size_t len5 = strlen(str5);
    if (len5 != 43) {
        dprintf(fd, "Test 5 failed: '%s' -> %zu\n", str5, len5);
        errors++;
    } else {
        dprintf(fd, "Test 5 passed: '%s' -> %zu\n", str5, len5);
    }

    if (errors > 0) {
        dprintf(fd, "%d errors detected\n", errors);
    } else {
        dprintf(fd, "All tests passed\n");
    }

    close(fd);

    /* ft_strcpy 64 bits Intel */
    char src[] = "Hello, world!";
    char dest[13];

    strcpy(dest, src);

    int fd = open("output.txt", O_WRONLY|O_CREAT|O_APPEND, 0666);
    dprintf(fd, "Source string: %s\n", src);
    dprintf(fd, "Destination string: %s\n", dest);
    close(fd);

    /* strcpy 64 bits Intel */
    const char *s1 = "hello";
    const char *s2 = "world";
    int result = strcmp(s1, s2);
    int fd = open("output.txt", O_WRONLY|O_CREAT|O_APPEND, 0666);
    dprintf("strcmp(\"%s\", \"%s\") = %d\n", s1, s2, result);
    close(fd);
    return 0;
}
