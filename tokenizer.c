#include "shell.h"

/**
 * **strtow - function that splits a string into words
 * @str: parameter string
 * @d: delimeter string
 * Return: a pointer to an array of strings
 */

char **strtow(char *str, char *d)
{
	int e, f, k, n, nw = 0;
	char **st;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (e = 0; str[e] != '\0'; e++)
		if (!is_delim(str[e], d) && (is_delim(str[e + 1], d) || !str[e + 1]))
			nw++;

	if (nw == 0)
		return (NULL);
	st = malloc((1 + nw) * sizeof(char *));
	if (!st)
		return (NULL);
	for (e = 0, f = 0; f < nw; f++)
	{
		while (is_delim(str[e], d))
			e++;
		k = 0;
		while (!is_delim(str[e + k], d) && str[e + k])
			k++;
		st[f] = malloc((k + 1) * sizeof(char));
		if (!st[f])
		{
			for (k = 0; k < f; k++)
				free(st[k]);
			free(st);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			st[f][n] = str[e++];
		st[f][n] = 0;
	}
	st[f] = NULL;
	return (st);
}

/**
 * **strtow2 - funtion to split string to words
 * @str: parameter string
 * @d: delimeter
 * Return: pointer to array of strings
 */
char **strtow2(char *str, char d)
{
	int e, f, k, n, nw = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (e = 0; str[e] != '\0'; e++)
		if ((str[e] != d && str[e + 1] == d) ||
		    (str[e] != d && !str[e + 1]) || str[e + 1] == d)
			nw++;
	if (nw == 0)
		return (NULL);
	s = malloc((1 + nw) * sizeof(char *));
	if (!s)
		return (NULL);
	for (e = 0, f = 0; f < nw; f++)
	{
		while (str[e] == d && str[e] != d)
			e++;
		k = 0;
		while (str[e + k] != d && str[e + k] && str[e + k] != d)
			k++;
		s[f] = malloc((k + 1) * sizeof(char));
		if (!s[f])
		{
			for (k = 0; k < f; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			s[f][n] = str[e++];
		s[f][n] = 0;
	}
	s[f] = NULL;
	return (s);
}

