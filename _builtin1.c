#include "shell.h"

/**
 * _myhistory - thus function displays the history list
 * @info: Structure that contains potential arguments
 *
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - this function sets alias to string
 * @info: the parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *c, s;
	int ret;

	c = _strchr(str, '=');
	if (!c)
		return (1);
	s = *c;
	*c = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*c = s;
	return (ret);
}

/**
 * set_alias - this function sets alias to string
 * @info: the parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *c;

	c = _strchr(str, '=');
	if (!c)
	return (1);
	if (!*++c)
	return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this function prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *c = NULL, *a = NULL;

	if (node)
	{
		c = _strchr(node->str, '=');
		for (a = node->str; a <= c; a++)
		{
			_putchar(*a);
			_putchar('\'');
			_puts(c + 1);
			_puts("'\n");
			return (0);
		}
	}
	return (1);
}

/**
 * _myalias - this function mimics the alias builtin (man alias)
 * @info: Structure that contains potential argument
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *c = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		c = _strchr(info->argv[j], '=');
		if (c)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}
