#include "libasm.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>

#define BUFFER_SIZE 512

void check_strlen(char *input_str) {
    dprintf(1, "Checking ft_strlen with string: %s\n", input_str);
    size_t expected_len = strlen(input_str);
    size_t obtained_len = ft_strlen(input_str);
    dprintf(1, "Expected length: %zu, Obtained: %zu\n", expected_len, obtained_len);
}

void check_strcpy(char *input_str) {
    dprintf(1, "Checking ft_strcpy with string: %s\n", input_str);
    char target1[BUFFER_SIZE] = {0};
    char target2[BUFFER_SIZE] = {0};
    char *expected_res = strcpy(target1, input_str);
    char *obtained_res = ft_strcpy(target2, input_str);
    dprintf(1, "Expected string: %s, Obtained: %s\n", expected_res, obtained_res);
}

void check_strcmp(char *input_str1, char *input_str2) {
    dprintf(1, "Checking ft_strcmp with strings: %s and %s\n", input_str1, input_str2);
    int expected_res = strcmp(input_str1, input_str2);
    int obtained_res = ft_strcmp(input_str1, input_str2);
    dprintf(1, "Expected result: %d, Obtained: %d\n", expected_res, obtained_res);
}

void check_strdup(char *input_str) {
    dprintf(1, "Checking ft_strdup with string: %s\n", input_str);
    char *expected_res = strdup(input_str);
    char *obtained_res = ft_strdup(input_str);
    dprintf(1, "Expected string: %s, Obtained: %s\n", expected_res, obtained_res);
    free(expected_res);
    free(obtained_res);
}

void check_write(int fd1, int fd2, char *str, int len) {
    dprintf(1, "Checking ft_write with string: %s and length: %d\n", str, len);
    char buffer1[BUFFER_SIZE] = {0};
    char buffer2[BUFFER_SIZE] = {0};
    ssize_t expected_res = write(fd1, str, len);
    ssize_t obtained_res = ft_write(fd2, str, len);
    dprintf(1, "Expected write size: %zd, Obtained: %zd\n", expected_res, obtained_res);
}

void check_valid_read(int fd1, int read_size) {
    dprintf(1, "Checking ft_read with file descriptor: %d and read size: %d\n", fd1, read_size);
    char buffer1[BUFFER_SIZE] = {0};
    char buffer2[BUFFER_SIZE] = {0};

    fd1 = open("mock-write.txt", O_RDONLY);
    ssize_t expected_res = read(fd1, buffer1, read_size);
    close(fd1);
    fd1 = open("mock-write.txt", O_RDONLY);
    ssize_t obtained_res = ft_read(fd1, buffer2, read_size);
    dprintf(1, "Expected read size: %zd, Obtained: %zd\n", expected_res, obtained_res);
}

void check_read(int fd1, int fd2, int read_size) {
    dprintf(1, "Checking ft_read with file descriptor: %d and read size: %d\n", fd1, read_size);
    char buffer1[BUFFER_SIZE] = {0};
    char buffer2[BUFFER_SIZE] = {0};
    ssize_t expected_res = read(fd1, buffer1, read_size);
    ssize_t obtained_res = ft_read(fd2, buffer2, read_size);
    dprintf(1, "Expected read size: %zd, Obtained: %zd\n", expected_res, obtained_res);
}


int main(void) {
    char lengthy_string[] = "This is a veeery lengthy string used for testing. It contains multiple sentences and is long enough to test the functions.";
    ssize_t result;
    result = 0;
	char char_read[21];

    dprintf(1, "--------------------------\n");
    dprintf(1, "---- Testing ft_write ----\n");
    dprintf(1, "--------------------------\n");
    dprintf(1, "\n");
    int file_descriptor1 = open("mock-write.txt", O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH);
    int file_descriptor2 = open("mock-ftwrite.txt", O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH);
    check_write(file_descriptor1, file_descriptor2, "Hello I am a humongus trout", strlen("Hello I am a humongus trout"));
    check_write(file_descriptor1, file_descriptor2, "", strlen(""));
    check_write(file_descriptor1, file_descriptor2, lengthy_string, strlen(lengthy_string));
    check_write(-1, -1, lengthy_string, strlen(lengthy_string));
	close(file_descriptor1);
    close(file_descriptor2);

    dprintf(1, "\n");
    dprintf(1, "-------------------------\n");
    dprintf(1, "---- Testing ft_read ----\n");
    dprintf(1, "-------------------------\n");
    dprintf(1, "\n");


    dprintf(1, "---- functional file descriptor ----\n");
    check_valid_read(file_descriptor1, 0);
    check_valid_read(file_descriptor1, 1);
    check_valid_read(file_descriptor1, 5);
    dprintf(1, "\n");
    
    dprintf(1, "---- non-functional file descriptor ----\n");
    file_descriptor1 = open("", O_RDONLY);
    file_descriptor2 = open("", O_RDONLY);
    check_read(file_descriptor1, file_descriptor2, BUFFER_SIZE);
    check_read(file_descriptor1, file_descriptor2, 0);
    check_read(file_descriptor1, file_descriptor2, 1);
    check_read(file_descriptor1, file_descriptor2, 5);

    dprintf(1, "\n");
    dprintf(1, "---------------------------\n");
    dprintf(1, "---- Testing ft_strlen ----\n");
    dprintf(1, "---------------------------\n");
    check_strlen("");
    check_strlen("Hello, world!");
    check_strlen(lengthy_string);
    dprintf(1, "\n");

    dprintf(1, "---------------------------\n");
    dprintf(1, "---- Testing ft_strcpy ----\n");
    dprintf(1, "---------------------------\n");
    dprintf(1, "\n");
    check_strcpy("");
    check_strcpy("Test string");
    check_strcpy(lengthy_string);

    dprintf(1, "\n");
    dprintf(1, "---------------------------\n");
    dprintf(1, "---- Testing ft_strcmp ----\n");
    dprintf(1, "---------------------------\n");
    dprintf(1, "\n");
    check_strcmp("", "");
    check_strcmp("Hello", "Hello");
    check_strcmp(lengthy_string, lengthy_string);
    check_strcmp(" ", "");
    check_strcmp("Helloo", "Hello");
    check_strcmp("", " ");
    check_strcmp("Hello", "Helloo");

    dprintf(1, "\n");
    dprintf(1, "---------------------------\n");
    dprintf(1, "---- Testing ft_strdup ----\n");
    dprintf(1, "---------------------------\n");
    dprintf(1, "\n");
    check_strdup("");
    check_strdup("Test string");
    check_strdup(lengthy_string);


    return 0;
}