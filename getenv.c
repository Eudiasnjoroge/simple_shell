#include "shell.h"

/**
 * get_environ - function returns the string array
 * @info: Structure containing potential args
 * Return: zero
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - function that Remove an environ . variable
 * @info: Structure containing potential arguments
 *
 *  Return: 1 on delete
 * @var: the string env var
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t b = 0;
	char *o;

	if (!node || !var)
		return (0);

	while (node)
	{
		o = starts_with(node->str, var);
		if (o && *o == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), b);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		b++;
	}
	return (info->env_changed);
}

/**
 * _setenv - function that initialize a new environment variable
 *
 * @info: Structure containing potential arguments
 *
 * @var: the string env var
 * @value: the string env var
 *  Return: zero
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *s;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		s = starts_with(node->str, var);
		if (s && *s == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

