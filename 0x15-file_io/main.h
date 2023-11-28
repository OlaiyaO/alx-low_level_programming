#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <elf.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

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

void errexit(const char *str, const char *file, int code);

void copy_file(const char *src_file, const char *dest_file);

int *open_files(const char *src_file, const char *dest_file);

void close_files(int *fds);

void checkElfMagicAndExitOnError(unsigned char *ident);

void displayMagicNumbers(unsigned char *ident);

void outputClassInfo(unsigned char *ident);

void showDataEncoding(unsigned char *ident);

void printVersionDetails(unsigned char *ident);

void showOsAbiInfo(unsigned char *ident);

void showAbiVersion(unsigned char *ident);

void printFileType(unsigned int type, unsigned char *ident);

void revealEntryPoint(unsigned long int entry, unsigned char *ident);

void closeFileDescriptor(int fd);

#endif /* MAIN_H */
