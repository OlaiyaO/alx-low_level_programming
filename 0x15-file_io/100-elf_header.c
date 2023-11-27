#include "main.h"

/*
 * File: 100-elf_header_modified.c
 * Auth: Oniya Olaiya
 * Desc: A program to display information from the ELF header at
 *	the start of an ELF file.
 */

/**
 * checkElfMagicAndExitOnError - Checks if a file is an ELF file.
 *	Exits with code 98 if not.
 * @ident: A pointer to an array containing the ELF magic numbers.
 *
 * If the file is not an ELF file, it prints an error message and
 *	exits with code 98.
 */

void checkElfMagicAndExitOnError(unsigned char *ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (ident[index] != 127 &&
				ident[index] != 'E' &&
				ident[index] != 'L' &&
				ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * displayMagicNumbers - Prints the magic numbers of an ELF header.
 * @ident: A pointer to an array containing the ELF magic numbers.
 *
 * Magic numbers are separated by spaces.
 */

void displayMagicNumbers(unsigned char *ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * outputClassInfo - Prints the class of an ELF header.
 * @ident: A pointer to an array containing the ELF class.
 *
 * Prints the class of the ELF header, such as ELF32 or ELF64.
 */

void outputClassInfo(unsigned char *ident)
{
	printf("  Class:                             ");

	switch (ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * showDataEncoding - Prints the data encoding of an ELF header.
 * @ident: A pointer to an array containing the ELF class.
 *
 * Prints the data encoding of the ELF header, such as 2's
 *	complement, little endian.
 */

void showDataEncoding(unsigned char *ident)
{
	printf("  Data:                              ");

	switch (ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * printVersionDetails - Prints the version of an ELF header.
 * @ident: A pointer to an array containing the ELF version.
 *
 * Prints the version of the ELF header, including whether it is the
 *	current version.
 */

void printVersionDetails(unsigned char *ident)
{
	printf("  Version:                           %d", ident[EI_VERSION]);

	switch (ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * showOsAbiInfo - Prints the OS/ABI of an ELF header.
 * @ident: A pointer to an array containing the ELF version.
 *
 * Prints the OS/ABI of the ELF header, such as UNIX - System V or
 *	UNIX - Linux.
 */

void showOsAbiInfo(unsigned char *ident)
{
	printf("  OS/ABI:                            ");

	switch (ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_OSABI]);
	}
}

/**
 * showAbiVersion - Prints the ABI version of an ELF header.
 * @ident: A pointer to an array containing the ELF ABI version.
 *
 * Prints the ABI version of the ELF header.
 */

void showAbiVersion(unsigned char *ident)
{
	printf("  ABI Version:                       %d\n",
			ident[EI_ABIVERSION]);
}

/**
 * printFileType - Prints the type of an ELF header.
 * @type: The ELF type.
 * @ident: A pointer to an array containing the ELF class.
 *
 * Prints the type of the ELF header, such as
 *	EXEC (Executable file) or DYN (Shared object file).
 */

void printFileType(unsigned int type, unsigned char *ident)
{
	if (ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", type);
	}
}

/**
 * revealEntryPoint - Prints the entry point of an ELF header.
 * @entry: The address of the ELF entry point.
 * @ident: A pointer to an array containing the ELF class.
 *
 * Prints the entry point address of the ELF header.
 */

void revealEntryPoint(unsigned long int entry, unsigned char *ident)
{
	printf("  Entry point address:               ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);
	else
		printf("%#lx\n", entry);
}

/**
 * closeFileDescriptor - Closes an ELF file descriptor.
 * @fileDescriptor: The file descriptor of the ELF file.
 *
 * If the file cannot be closed, it prints an error message and exits with
 * code 98.
 */

void closeFileDescriptor(int fileDescriptor)
{
	if (close(fileDescriptor) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close file descriptor %d\n", fileDescriptor);
		exit(98);
	}
}

/**
 * main - Displays information from the ELF header at the start of an ELF file.
 * @argc: The number of arguments provided to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 98 on failure.
 *
 * Description: This function serves as the entry point for the program.
 *		It opens
 * an ELF file specified in the command-line arguments, reads its ELF header,
 * and prints relevant information. If there is an issue with opening the file,
 * memory allocation, or reading the header, the program exits with a status
 * code of 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fileDescriptor, readResult;

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeFileDescriptor(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(98);
	}
	readResult = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (readResult == -1)
	{
		free(header);
		closeFileDescriptor(fileDescriptor);
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}
	checkElfMagicAndExitOnError(header->e_ident);
	printf("ELF Header:\n");
	displayMagicNumbers(header->e_ident);
	outputClassInfo(header->e_ident);
	showDataEncoding(header->e_ident);
	printVersionDetails(header->e_ident);
	showOsAbiInfo(header->e_ident);
	showAbiVersion(header->e_ident);
	printFileType(header->e_type, header->e_ident);
	revealEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeFileDescriptor(fileDescriptor);
	return (0);
}
