#include "shell.h"

/**
 * get_history_file - function that gets the history file
 * @info: parameter
 *
 * Return: allocated string containg history file
 */

char *get_history_file(info_t *info)
{
	char *b, *d;

	d = _getenv(info, "HOME=");
	if (!d)
		return (NULL);
	b = malloc(sizeof(char) * (_strlen(d) + _strlen(HIST_FILE) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	_strcpy(b, d);
	_strcat(b, "/");
	_strcat(b, HIST_FILE);
	return (b);
}

/**
 * write_history - function that creates a file
 * @info: parameter
 *
 * Return: 1 true
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - function that reads history from file
 * @info: the parameter
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int b, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (b = 0; b < fsize; b++)
		if (buf[b] == '\n')
		{
			buf[b] = 0;
			build_history_list(info, buf + last, linecount++);
			last = b + 1;
		}
	if (last != b)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - function that adds entry to a history
 * @info: Structure
 * @buf: buffer
 * @linecount: the history linecount
 *
 * Return: zero
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - function that renumbers the history linkeds
 * @info: Structure
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int b = 0;

	while (node)
	{
		node->n = b++;
		node = node->next;
	}
	return (info->histcount = b);
}

