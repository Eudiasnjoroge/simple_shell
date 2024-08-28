#include "shell.h"

/**
 * _erratoi - function that converts a string to an integer
 * @s: the string
 * Return: 0 if no numbers in string, converted number otherwise
 *
 */
int _erratoi(char *s)
{
	int b = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (b = 0;  s[b] != '\0'; b++)
	{
		if (s[b] >= '0' && s[b] <= '9')
		{
			result *= 10;
			result += (s[b] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - function that prints an error message
 * @info: the parameter
 * @estr: string
 * Return: 0 if no numbers in string
 *
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: input
 * @fd: the filedescriptor
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int b, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (b = 1000000000; b > 1; b /= 10)
	{
		if (_abs_ / b)
		{
			__putchar('0' + current / b);
			count++;
		}
		current %= b;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - function the converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char s = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (s)
		*--ptr = s;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string
 *
 * Return: Zero
 */
void remove_comments(char *buf)
{
	int b;

	for (b = 0 ; buf[b] != '\0' ; b++)
		if (buf[b] == '#' && (!b || buf[b - 1] == ' '))
		{
			buf[b] = '\0';
			break;
		}
}

