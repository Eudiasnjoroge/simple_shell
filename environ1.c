#include "shell.h"

/**
 * _myenv - this function prints the current environment
 * @info: Structure that contains potential arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - this function gets the value of an environ variable
 * @info: Structure that contains potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *c;

	while (node)
	{
		c = starts_with(node->str, name);
		if (c && *c)
			return (c);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - This function Initializes a new environment variable
 *             or modify an existing one
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - This function Removes an environment variable
 * @info: Structure that contains potential arguments
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - this function populates env linked list
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t s;

	for (s = 0; environ[s]; s++)
		add_node_end(&node, environ[s], 0);
	info->env = node;
	return (0);
}
