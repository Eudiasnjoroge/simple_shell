#include "shell.h"

/**
 **_strncpy -  function that copies a string
 *@dest: destination
 *@src: source string
 *@n: no of characters to be copied
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int e, f;
	char *s = dest;

	e = 0;
	while (src[e] != '\0' && e < n - 1)
	{
		dest[e] = src[e];
		e++;
	}
	if (e < n)
	{
		f = e;
		while (f < n)
		{
			dest[f] = '\0';
			f++;
		}
	}
	return (s);
}

/**
 **_strncat - function that concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: no of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int e, f;
	char *s = dest;

	e = 0;
	f = 0;
	while (dest[e] != '\0')
		e++;
	while (src[f] != '\0' && f < n)
	{
		dest[e] = src[f];
		e++;
		f++;
	}
	if (f < n)
		dest[e] = '\0';
	return (s);
}

/**
 **_strchr - function that locates a character
 *@s: the string to parsed
 *@c: the character to look
 *Return: a pointer to the memory
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

