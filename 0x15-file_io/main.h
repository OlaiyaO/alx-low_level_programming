#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>
#include <stdint.h>

ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);

int append_text_to_file(const char *filename, char *text_content);

char *allocate_buffer(size_t size);

void free_buffer(char *buffer);

int write_to_stdout(char *buffer, size_t size);

void close_file(int fd);

const char *get_type_name(uint16_t type);

const char *get_osabi_name(unsigned char osabi);

void print_elf_header(Elf64_Ehdr *header);

void error_exit(const char *msg);

int check_arguments(int ac, char **av);

int open_source_file(const char *filename);

int open_destination_file(const char *filename);

int copy_file_contents(int fd_from, int fd_to);
#endif /* MAIN_H */
