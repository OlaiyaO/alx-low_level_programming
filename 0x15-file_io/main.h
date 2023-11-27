#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);

int append_text_to_file(const char *filename, char *text_content);

char *allocate_buffer(size_t size);

void free_buffer(char *buffer);

int write_to_stdout(char *buffer, size_t size);

void close_file(int fd);

#endif /* MAIN_H */
