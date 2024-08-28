#include "shell.h"

/**
 * _strncpy - a function that copies a string
 *@dest: destination string to be copied to
 *@src: source string
 *@n: amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k, l;
	char *c = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		l = k;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (c);
}

/**
 * _strncat - a function that concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int k, l;
	char *c = dest;

	k = 0;
	l = 0;
	while (dest[k] != '\0')
		k++;
	while (src[l] != '\0' && l < n)
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	if (l < n)
		dest[k] = '\0';
	return (c);
}

/**
 * _strchr - this function locates a character in a string
 * @s: string to be parsed
 * @c: character to look for
 * Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do
	{
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
