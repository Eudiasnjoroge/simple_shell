#include "shell.h"

/**
 *_eputs - function that prints an input string
 * @str: the string
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}
}

/**
 * _eputchar - function that writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 *
 */
int _eputchar(char c)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}

/**
 * _putfd - function that writes the character c to given fd
 * @c: The character
 * @fd: The filedescriptor
 *
 * Return: On success 1
 *
 */
int _putfd(char c, int fd)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(fd, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}

/**
 *_putsfd - function that prints an input string
 * @str: the string
 * @fd: the filedescriptor
 *
 * Return: the number of chars
 */
int _putsfd(char *str, int fd)
{
	int b = 0;

	if (!str)
		return (0);
	while (*str)
	{
		b += _putfd(*str++, fd);
	}
	return (b);
}

