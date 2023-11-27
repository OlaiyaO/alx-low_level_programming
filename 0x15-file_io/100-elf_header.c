#include "main.h"

/**
 * error_exit - Print error message and exit with status code 98.
 * @msg: Error message to print.
 */

void error_exit(const char *msg)
{
	dprintf(2, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Print information from the ELF header.
 * @header: Pointer to the ELF header structure.
 */

void print_elf_header(Elf64_Ehdr *header)
{
	int i;
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
		printf("%02x%c", header->e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');
	printf("  Class:                             %s\n",
			(header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
			(header->e_ident[EI_DATA] == ELFDATA2LSB)
			? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %u (current)\n",
			header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			get_osabi_name(header->e_ident[EI_OSABI]));
	printf("  ABI Version:                       %u\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			get_type_name(header->e_type));
	printf("  Entry point address:               %#lx\n",
			(unsigned long)header->e_entry);
}

/**
 * get_osabi_name - Get the string representation of the OS/ABI.
 * @osabi: OS/ABI value from the ELF header.
 * Return: String representation of the OS/ABI.
 */

const char *get_osabi_name(unsigned char osabi)
{
	switch (osabi)
	{
		case ELFOSABI_SYSV:
			return ("UNIX - System V");
		case ELFOSABI_HPUX:
			return ("UNIX - HP-UX");
		case ELFOSABI_NETBSD:
			return ("UNIX - NetBSD");
		case ELFOSABI_LINUX:
			return ("UNIX - Linux");
		case ELFOSABI_SOLARIS:
			return ("UNIX - Solaris");
		case ELFOSABI_AIX:
			return ("UNIX - AIX");
		case ELFOSABI_IRIX:
			return ("UNIX - IRIX");
		case ELFOSABI_FREEBSD:
			return ("UNIX - FreeBSD");
		case ELFOSABI_TRU64:
			return ("UNIX - TRU64");
		case ELFOSABI_MODESTO:
			return ("Novell - Modesto");
		case ELFOSABI_OPENBSD:
			return ("UNIX - OpenBSD");
		case ELFOSABI_STANDALONE:
			return ("Standalone App");
		default:
			return ("<unknown>");
	}
}

/**
 * get_type_name - Get the string representation of the ELF type.
 * @type: ELF type value from the ELF header.
 * Return: String representation of the ELF type.
 */

const char *get_type_name(uint16_t type)
{
	switch (type)
	{
		case ET_NONE:
			return ("NONE (Unknown type)");
		case ET_REL:
			return ("REL (Relocatable file)");
		case ET_EXEC:
			return ("EXEC (Executable file)");
		case ET_DYN:
			return ("DYN (Shared object file)");
		case ET_CORE:
			return ("CORE (Core file)");
		default:
			return ("<unknown>");
	}
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, 98 on error.
 */

int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Unable to open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		close(fd);
		error_exit("Error: Unable to read ELF header");
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		error_exit("Error: Not an ELF file");
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}
