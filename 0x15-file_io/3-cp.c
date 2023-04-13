#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if files can be opened.
 * @fileFrom: fileFrom.
 * @fileTo: fileTo.
 * @args: arguments vector.
 * Return: no return.
 */
void error_file(int fileFrom, int fileTo, char *args[])
{
	if (fileFrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", args[1]);
		exit(98);
	}
	if (fileTo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", args[2]);
		exit(99);
	}
}

/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fileFrom, fileTo, errClose;
	ssize_t nChars, nWr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	fileFrom = open(argv[1], O_RDONLY);
	fileTo = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(fileFrom, fileTo, argv);

	nChars = 1024;
	while (nChars == 1024)
	{
		nChars = read(fileFrom, buf, 1024);
		if (nChars == -1)
			error_file(-1, 0, argv);
		nWr = write(fileTo, buf, nChars);
		if (nWr == -1)
			error_file(0, -1, argv);
	}

	errClose = close(fileFrom);
	if (errClose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}

	errClose = close(fileTo);
	if (errClose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}
	return (0);
}
