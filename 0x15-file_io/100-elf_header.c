#include "main.h"

/**
 * read_elf_header - Reads the ELF header from a file.
 *
 * @filename: The name of the ELF file.
 * @elf_header: Pointer to the Elf64_Ehdr structure to store the header.
 *
 * Return: (0) on success, (-1) on failure.
 */

int read_elf_header(const char *filename, Elf64_Ehdr *elf_header)
{
	int fd, read_count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		return (-1);
	}

	read_count = read(fd, elf_header, sizeof(Elf64_Ehdr));
	close(fd);

	if (read_count == -1 || read_count != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		return (-1);
	}

	return (0);
}

/**
 * print_elf_magic - Prints the magic number of the ELF header.
 *
 * @magic: The magic number array from the ELF header.
 */

void print_elf_magic(const unsigned char *magic)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; ++i)
		printf("%02x ", magic[i]);
	printf("\n");
}

/**
 * print_elf_class - Prints the class (32-bit or 64-bit) of the ELF file.
 *
 * @elf_class: The ELF class identifier.
 */

void print_elf_class(uint8_t elf_class)
{
	printf("  Class:                             %s\n",
			(elf_class == ELFCLASS32) ? "ELF32" :
			(elf_class == ELFCLASS64) ? "ELF64" : "Unknown");
}

/**
 * print_elf_data - Prints the endianness of the ELF file.
 *
 * @elf_data: The ELF data identifier.
 */

void print_elf_data(uint8_t elf_data)
{
	printf("  Data:                              %s\n",
			(elf_data == ELFDATA2LSB) ? "2's complement, little endian" :
			(elf_data == ELFDATA2MSB) ? "2's complement, big endian" : "Unknown");
}

/**
 * print_elf_version - Prints the ELF version.
 *
 * @elf_version: The ELF version identifier.
 */

void print_elf_version(uint8_t elf_version)
{
	printf("  Version:                           %d (current)\n", elf_version);
}

/**
 * print_elf_info - Prints various information from the ELF header.
 *
 * @elf_header: Pointer to the Elf64_Ehdr structure containing the header.
 */

void print_elf_info(const Elf64_Ehdr *elf_header)
{
	print_elf_magic(elf_header->e_ident);
	print_elf_class(elf_header->e_ident[EI_CLASS]);
	print_elf_data(elf_header->e_ident[EI_DATA]);
	print_elf_version(elf_header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			get_osabi_name(elf_header->e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n",
			elf_header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			get_type_name(elf_header->e_type));
	printf("  Entry point address:               %#lx\n",
			(unsigned long)elf_header->e_entry);
}

/**
 * main - Entry point of the program.
 *
 * @argc: Argument count.
 * @argv: Array of argument tokens.
 *
 * Return: (0) on success, (98) on failure.
 */

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	if (read_elf_header(argv[1], &elf_header) != 0)
		return (98);

	print_elf_info(&elf_header);

	return (0);
}

