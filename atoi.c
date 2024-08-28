#include "shell.h"

/**
 * interactive - function that returns true if shell is interactive
 * @info: struct
 *
 * Return: 1 if true
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function that checks if character is a delimiter
 * @c: parameter representing the character to check
 * @delim: string containing delimiter characters
 *
 * Return: 1 if true, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - function that checks for alphabetic character
 * @c: The character to be checked
 *
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function that converts a string to an integer
 * @s: parameter representing the string to be converted
 *
 * Return: The converted integer, or 0 if no numbers are found in the string
 */
int _atoi(char *s)
{
	int j, sign = 1, flag = 0;
	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	return ((sign == -1) ? (int)(-result) : (int)(result));
}

