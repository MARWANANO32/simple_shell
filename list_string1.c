#include "shell.h"

/**
 * list_length - the function that determine length
 * @w: the pointer to first node
 *
 * Return: the size of list
 */

size_t list_length(const OPPS_t *w)
{
	size_t a;

	for (a = 0; w; a++)
	{
		w = w->next;
	}
	return (a);
}
/**
 * list_string - the function return the arrays
 * @header: the pointer to the node
 * Return: the array of string
 */
char **list_string(OPPS_t *header)
{
	OPPS_t *node = header;
	size_t i = list_length(head);
	char **mars;
	char *mar;

	if (!header || !i)
		return (NULL);
	mars = malloc(sizeof(char *) * (i + 1));
	((!mars) ? (return (NULL), 0) : (0));

	while (node)
	{
		node = node->next;
		i++;
		mar = malloc(_strlen(node->mar) + 1);
		if (!str)
		{
			for (size_t j = 0; j < i; j++)
			{
				free(mars[j]);
			}
			free(mars);
			return (NULL);
		}
		mar = _strcpy(mar, node->mar);
		mars[i] = mar;
		node = node->next;
		i++;
	}
	mars[i] = NULL;
	return (mars);
}

/**
 * p_list - the function for print all element
 * @w: the pointer for node
 * Return: the size of list
 */
size_t p_list(const OPPS_t *w)
{
	size_t a = 0;

	while (w)
	{
		_puts(c_number(w->v, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(w->str ? w->str : "(nil)");
		_puts("\n");
		w = w->next;
		a++;
	}
	return (a);
}

/**
 * node_with - the function for return node
 * @node: the pointer to list
 * @pre: the string
 * @s: the next character
 * Return: the node
 */
OPPS_t *node_with(OPPS_t *node, char *pre, char s)
{
	char *a = NULL;

	while (node)
	{
		a = starts_with(node->str, pre);
		if (a && ((s == -1) || (*a == s)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_index - the function for get the index
 * @header: the pointer to list head
 * @node: the pointer to the node
 * Return: the index or -1
 */
ssize_t get_index(OPPS_t *header, OPPS_t *node)
{
	for (size_t i = 0; header; header = header->next, i++)
	{
		if (header == node)
			return (i);
	}
	return (-1);
}
